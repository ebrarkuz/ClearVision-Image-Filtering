#include "Crypto.h"
#include "GrayscaleImage.h"


// Extract the least significant bits (LSBs) from SecretImage, calculating x, y based on message length
std::vector<int> Crypto::extract_LSBits(SecretImage& secret_image, int message_length) {
    std::vector<int> LSB_array;
    GrayscaleImage image= secret_image.reconstruct();
    int width=image.get_width();
    int height=image.get_height();
    int dimension=width*height;
    int totalBits=message_length*7;
    if (totalBits>dimension) {
        throw std::runtime_error("Message is too long for the image.");
    }
    int startingPixelNumber = dimension - totalBits;
    for (int index = startingPixelNumber; index < dimension; ++index) {
        int y = index % width;
        int x = index / width;
        int pixelValue = image.get_pixel(x, y);
        int lsb = pixelValue & 1;
        LSB_array.push_back(lsb);
    }

    // TODO: Your code goes here.

    // 1. Reconstruct the SecretImage to a GrayscaleImage.
    // 2. Calculate the image dimensions.
    // 3. Determine the total bits required based on message length.
    // 4. Ensure the image has enough pixels; if not, throw an error.
    // 5. Calculate the starting pixel from the message_length knowing that
    //    the last LSB to extract is in the last pixel of the image.
    // 6. Extract LSBs from the image pixels and return the result.

    return LSB_array;
}


// Decrypt message by converting LSB array into ASCII characters
std::string Crypto::decrypt_message(const std::vector<int>& LSB_array) {
    std::string message;

    if (LSB_array.size() % 7 != 0) {
        throw std::runtime_error("LSB array size is not a multiple of 7.");
    }

    for (size_t i = 0; i < LSB_array.size(); i += 7) {
        std::bitset<7> bits;
        for (int j = 0; j < 7; ++j) {
            bits[6-j]=LSB_array[i+j];
        }

        char character = static_cast<char>(bits.to_ulong());
        message += character;
    }

// TODO: Your code goes here.

    // 1. Verify that the LSB array size is a multiple of 7, else throw an error.
    // 2. Convert each group of 7 bits into an ASCII character.
    // 3. Collect the characters to form the decrypted message.
    // 4. Return the resulting message.

    return message;
}

// Encrypt message by converting ASCII characters into LSBs
std::vector<int> Crypto::encrypt_message(const std::string& message) {
    std::vector<int> LSB_array;
    for(char a : message) {
        std::bitset<7> bits (a);
        for (int i = 0; i <7; ++i) {
            LSB_array.push_back(bits[6-i]);
        }

    }
    // TODO: Your code goes here.

    // 1. Convert each character of the message into a 7-bit binary representation.
    //    You can use std::bitset.
    // 2. Collect the bits into the LSB array.
    // 3. Return the array of bits.

    return LSB_array;
}

// Embed LSB array into GrayscaleImage starting from the last bit of the image
SecretImage Crypto::embed_LSBits(GrayscaleImage& image, const std::vector<int>& LSB_array) {
    int width=image.get_width();
    int height = image.get_height();
    int dimension=width*height;
    if(dimension<LSB_array.size()) {
        throw std::runtime_error("The message is too long .");
    }
    int startingPixelNumber= dimension - LSB_array.size();
    for(int i=0; i<LSB_array.size(); ++i) {
        int indexX=(startingPixelNumber+i)/width;
        int indexY=(startingPixelNumber+i)%width;
        int value=image.get_pixel(indexX,indexY);

        if (LSB_array[i] == 1) {
            value |= 1;
        } else {
            value &= ~1;
        }
        image.set_pixel(indexX,indexY, value);
    }
    SecretImage secret_image(image);

    // TODO: Your code goes here.

    // 1. Ensure the image has enough pixels to store the LSB array, else throw an error.
    // 2. Find the starting pixel based on the message length knowing that
    //    the last LSB to embed should end up in the last pixel of the image.
    // 3. Iterate over the image pixels, embedding LSBs from the array.
    // 4. Return a SecretImage object constructed from the given GrayscaleImage
    //    with the embedded message.


    return secret_image;
}
