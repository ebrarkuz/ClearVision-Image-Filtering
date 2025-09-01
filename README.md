# ClearVision: An Advanced C++ Image Processing System

**ClearVision** is a simple C++ app for working with images. It helps you make images look better, hide secret messages inside them, and more. It was made for a class project at Hacettepe University.

---
### What It Can Do

* **Make Images Clearer:**
    * It can use a **Mean Filter** to make images smoother and get rid of noise.
    * It can also use a **Gaussian Filter** to do a better job of smoothing.
    * It has an **Unsharp Mask** filter to make edges sharper and clearer.
* **Hide Secret Messages:**
    * You can put a secret message inside an image. This is called steganography.
    * You can also get the hidden message back out of the image.
* **Other Tools:**
    * It can add or subtract images.
    * You can check if two images are exactly the same.

---
### How to Use It

#### **Build the Program**

First, you need to turn the code into a program. Use this command:

```bash
g++ -g -std=c++11 -o clearvision main.cpp SecretImage.cpp GrayscaleImage.cpp Filter.cpp Crypto.cpp
```                        
Or, you can use the Makefile if you have one:

make
Run the Program
After you build it, you can run it from your terminal. Here are some examples:

To make an image smoother:

```bash

./clearvision mean photo.png 3

```

To make an image sharper:
```bash

./clearvision unsharp image.png 5 1.5

```

To hide a message:
```bash

./clearvision enc secret_photo.png "This is a secret note."


```

To find a hidden message:
```bash
./clearvision dec secret_photo.png 20

```

To check if two photos are the same:
```bash

./clearvision equals picture1.png picture2.png

./clearvision equals image1.png image2.png
