#include <iostream>
#include <fstream>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <cstring>
#include <cerrno>

#define CHARACTER_DEVICE_DRIVER_PATH "/ruta"
#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('b','b',int32_t*)

struct ioctl_args {
    int32_t value;
    int32_t dir;
};

int main() {
    int fd;
    const char *chr_dev_name = CHARACTER_DEVICE_DRIVER_PATH;
    struct ioctl_args args_read;
    struct ioctl_args args_write;
    int img_size;
    int index = 0;
    int times_to_read = 0;
    int buffer_size = 256;
    int buffer_dir = 0x18;

    std::cout << "Attempting to open character device at " << chr_dev_name << "\n";
    fd = open(chr_dev_name, O_RDWR);
    if (fd < 0) {
        std::cerr << "Failed to open character device. Error: " << strerror(errno) << "\n";
        return 0;
    }

    std::cout << "[App] Requesting start of image capture\n";
    args_write.dir = 0x14;
    args_write.value = 0x1;
    ioctl(fd, WR_VALUE, &args_write);
    std::cout << "Command to start capture issued at register 0x" << std::hex << args_write.dir << "\n";

    std::cout << "Requesting image size\n";
    args_write.value = 0x3;
    ioctl(fd, WR_VALUE, &args_write);
    std::cout << "Command to read image size issued\n";

    std::cout << "Retrieving image size from device\n";
    args_read.dir = 0x0;
    ioctl(fd, RD_VALUE, &args_read);
    std::cout << "Image size obtained: " << args_read.value << " bytes\n";
    img_size = args_read.value;
    times_to_read = (img_size / buffer_size) + (img_size % buffer_size != 0);

    std::vector<char> img_data(img_size);

    std::cout << "Beginning image data transfer\n";
    for (int i = 0; i < times_to_read; ++i) {
        args_write.dir = 0x14;
        args_write.value = 0x2;
        ioctl(fd, WR_VALUE, &args_write);

        for (int j = 0; j < buffer_size; j += 4) {
            if (index >= img_size) {
                break;
            }
            args_read.dir = buffer_dir + j;
            ioctl(fd, RD_VALUE, &args_read);

            img_data[index++] = args_read.value & 0xFF;
            if (index >= img_size) break;
            img_data[index++] = (args_read.value >> 8) & 0xFF;
            if (index >= img_size) break;
            img_data[index++] = (args_read.value >> 16) & 0xFF;
            if (index >= img_size) break;
            img_data[index++] = (args_read.value >> 24) & 0xFF;
        }
        if (index >= img_size) {
            break;
        }
    }

    std::cout << "Image data transfer complete\n";
    close(fd);

    std::cout << "Saving image to file\n";
    std::ofstream file_img("./images/img_device.bmp", std::ios::binary);
    if (!file_img) {
        std::cerr << "Failed to save image file.\n";
        return 1;
    }

    file_img.write(img_data.data(), img_size);
    file_img.close();

    std::cout << "Image successfully saved\n";
    
    std::cout << "************************************************************************************************************************************\n";
    std::cout << "Applying negative filter\n";
    system("python3 ./filters/negative.py");
    std::cout << "Applying smoothed filter\n";
    system("python3 ./filters/smoothed.py");
    std::cout << "************************************************************************************************************************************\n";

    return 0;
}
