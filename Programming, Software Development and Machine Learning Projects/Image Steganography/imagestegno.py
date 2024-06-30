import cv2
import numpy as np
from PIL import Image
import warnings

warnings.filterwarnings("ignore")

#it convert data in binary formate


def data2binary(data):
    if type(data) == str:
        p = ''.join([format(ord(i), '08b')for i in data])
    elif type(data) == bytes or type(data) == np.ndarray:
        p = [format(i, '08b')for i in data]
    return p


# hide data in given img

def hidedata(img, data):
    data += "$"
    d_index = 0
    b_data = data2binary(data)
    len_data = len(b_data)

 #iterate pixels from image and update pixel values

    for value in img:
        for pix in value:
            r, g, b = data2binary(pix)
            if d_index < len_data:
                pix[0] = int(r[:-1] + b_data[d_index])
                d_index += 1
            if d_index < len_data:
                pix[1] = int(g[:-1] + b_data[d_index])
                d_index += 1
            if d_index < len_data:
                pix[2] = int(b[:-1] + b_data[d_index])
                d_index += 1
            if d_index >= len_data:
                break
    return img


def encode():
    img_name = input("\nEnter Image Name:")
    image = cv2.imread(img_name)
    img = Image.open(img_name, 'r')
    w, h = img.size
    data = input("\nEnter Message(max-length: 10000 characters):")
    if data == 0:
        raise ValueError("Empty Data")
    enc_img = input("\nEnter Encoded Image Name:")
    enc_data = hidedata(image, data)
    cv2.imwrite(enc_img, enc_data)
    img1 = Image.open(enc_img, 'r')
    img1 = img1.resize((w, h),Image.Resampling.LANCZOS)
    # optimize with 65% quality
    if w != h:
        img1.save(enc_img, optimize=True, quality=65)
    else:
        img1.save(enc_img)

# decoding

def find_data(img):
    bin_data = ""
    c = 0
    for value in img:
        for pix in value:
            r, g, b = data2binary(pix)
            bin_data += r[-1]
            bin_data += g[-1]
            bin_data += b[-1]
            c += 1
            if(c == 10000):
                break
        if(c == 10000):
            break

    all_bytes = [bin_data[i: i + 8] for i in range(0, len(bin_data), 8)]

    readable_data = ""
    for x in all_bytes:
        readable_data += chr(int(x, 2))
        if readable_data[-1:] == "$":
            break
    return readable_data[:-1]


def decode():
    img_name = input("\nEnter Image Name: ")
    image = cv2.imread(img_name)
    img=Image.open(img_name,'r')
    msg = find_data(image)
    return msg


def stegnography():
    x = 1
    while x != 0:
        print('\nImage Stegnography\n1. Encode\n2. Decode\n0. Exit')
        u_in = int(input("\nEnter Your Choice:"))
        if(u_in == 1):
            encode()
            x = int(input("\nEnter 1 For Continue Otherwise 0:"))
        elif(u_in == 2):
            ans = decode()
            print("\nYour message:",ans)
            x = int(input("\nEnter 1 For Continue Otherwise 0:"))
        elif(u_in == 0):
            x = 0
        else:
            print("Invalid choice!!")
    print("Thanks for visiting!!")


stegnography()
