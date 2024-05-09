from PIL import Image

def apply_negative_filter(image_path, output_path):
    print("Opening img")
    image = Image.open(image_path)

    print("Applying negative")
    negative_image = Image.eval(image, lambda x: 255 - x)

    print("Saving negative")
    negative_image.save(output_path)
    print("Apply")

if __name__ == "__main__":
    apply_negative_filter("test.bmp", "test_negative.bmp")
