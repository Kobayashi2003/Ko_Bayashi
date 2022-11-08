from PIL import Image, ImageFont, ImageDraw
import numpy as np

# import os, sys
# os.chdir(sys.path[0])

def ascii_srt(file):

    im = Image.open(file)
    sample_rate = 0.5

    # Computer letter aspect ratio
    font = ImageFont.truetype("C:/Users/17312/Desktop/Code/Python/Practice/ASCII_ART/SourceCodePro-Regular.ttf", size=18)
    aspect_ratio = font.getsize('x')[0] / font.getsize('x')[1]
    new_im_size = np.array(
        [im.size[0] * sample_rate, im.size[1] * sample_rate * aspect_ratio]
    ).astype(int)

    # Downsample the image
    im = im.resize(new_im_size)

    # keep a copy of image for color sampling
    im_color = np.array(im)

    # Convert to gray scale image
    im = im.convert('L')

    # Convert to numpy array for image manipulation
    im = np.array(im)

    # Defines all the symbols in ascending order that will form the final ascii
    # symbols = np.array(list(" .-v*M@#"))
    symbols = np.array(list(" `.^\\:~<!ct+{i7?u30pw4A8DX\%#HWM"))

    # Normalize the minimum and maximum to [0, max_symbol_index]
    im = (im - im.min()) / (im.max() - im.min()) * (symbols.size - 1)

    # Generate the ascii art
    ascii = symbols[im.astype(int)]

    # file_path = "test.txt"
    # lines = "\n".join("".join(r) for r in ascii)
    # with open(file_path, "w") as file:
    #     file.write(lines)

    # Create a output image for drawing ascii text
    letter_size = font.getsize('x')
    im_out_size = new_im_size * letter_size
    bg_color = "black"
    im_out = Image.new('RGB', tuple(im_out_size), bg_color)
    draw = ImageDraw.Draw(im_out)

    # Draw text
    y = 0
    for i, line in enumerate(ascii):
        for j, ch in enumerate(line):
            # color = (255, 255, 255) # white
            color = tuple(im_color[i, j]) # sample color from original image
            draw.text((j * letter_size[0], y), ch, font=font, fill=color)
        y += letter_size[1] # increase y by letter height

    # Save the image
    im_out.save(file + ".acii.png")

if __name__ == "__main__":
    ascii_srt("C:/Users/17312/Desktop/Code/Python/Practice/ASCII_ART/one-piece.jpg")
