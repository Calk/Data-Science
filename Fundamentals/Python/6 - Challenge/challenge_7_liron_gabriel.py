from PIL import Image

# manually cut out the gray strip from the image

im = Image.open('gray_strip.png')

image_length = im.size[0]
image_height = im.size[1]

pix = im.load()

rgb_values = []

for col in range(image_length):
    for row in range(image_height):
        rgb_values.append(pix[col, row][0])


for _ in rgb_values[::7]:
    print chr(int(_)),
print '\n'

# by inspection:
next_step = [105, 110, 116, 101, 103, 114, 105, 116, 121]


for _ in next_step:
    print chr(int(_))

# integrity