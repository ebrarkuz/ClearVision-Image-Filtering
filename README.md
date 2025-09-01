# ClearVision: An Advanced C++ Image Processing System

**ClearVision** is a robust image processing application built in C++11, designed to handle critical tasks ranging from **image enhancement to secure data handling**. Developed as a project for the BBM203 Software Practicum I course, this system provides a suite of tools for noise reduction, image manipulation, and steganography.

---
### Core Capabilities

* **Image Filtering:**
    * **Noise Reduction:** Implementations of **Mean** and **Gaussian** filters effectively smooth out imperfections and noise.
    * **Image Sharpening:** The **Unsharp Mask** filter helps in enhancing edge details and improving overall clarity.
* **Image Manipulation & Analysis:**
    * Perform essential operations like **addition, subtraction, and comparison** on grayscale images. These functionalities are built using C++ operator overloading for a more intuitive syntax.
* **Secure Data Handling (Steganography):**
    * **Message Embedding:** Hide text messages within an image's pixel data by modifying its **Least Significant Bits (LSB)**, providing a secure method for secret communication.
    * **Message Extraction:** Reliably retrieve hidden messages from images that have been processed with the steganography module.

---
### Technology Stack

The project leverages key C++11 features to deliver its functionality:

* **Dynamic Memory Management:** Images are stored and manipulated efficiently in memory using dynamic allocation.
* **Arrays and Matrices:** All image processing operations are performed on pixel data stored in a matrix format.
* **External Libraries:** The `stb_image.h` and `stb_image_write.h` single-header libraries are used for seamless image file I/O (loading and saving PNG/JPG files).

---
### Building and Running the Application

To get the project up and running, follow these simple steps.

#### **Building from Source**

You can compile the source files directly using `g++`:

```bash
g++ -g -std=c++11 -o clearvision main.cpp SecretImage.cpp GrayscaleImage.cpp Filter.cpp Crypto.cpp
Alternatively, you can use the provided build scripts:

Bash

# To build with the Makefile
make

# To build with CMake
mkdir clearvision_build
cmake -S . -B clearvision_build/
make -C clearvision_build/
Using ClearVision
After compiling, you can execute the program from the command line with various arguments to perform different tasks.

Apply a Mean Filter:

Bash

./clearvision mean input_image.png 3
Apply an Unsharp Mask Filter:

Bash

./clearvision unsharp input.png 5 1.5
Embed a Secret Message:

Bash

./clearvision enc secret_image.png "This is a confidential message."
Extract a Hidden Message:

Bash

./clearvision dec secret_image.png 20
Compare Two Images:

Bash

./clearvision equals image1.png image2.png
