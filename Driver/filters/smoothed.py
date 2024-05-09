from PIL import Image, ImageFilter

def apply_smoothed_filter(image_path, output_path):
    print("Opening img")
    image = Image.open(image_path)

    print("Applying smoothed")
    smoothed_image = image.filter(ImageFilter.SMOOTH)

    print("Saving smoothed")
    smoothed_image.save(output_path)
    print("Apply")

if __name__ == "__main__":
    apply_smoothed_filter("./images/img_device.bmp", "./images/img_smoothed.bmp")
