#define _USE_MATH_DEFINES
#include "Filter.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <math.h>
// Mean Filter
void Filter::apply_mean_filter(GrayscaleImage& image, int kernelSize) {
    GrayscaleImage originalImage(image);
    int height = image.get_height();
    int width = image.get_width();

    int h = kernelSize / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::vector<int> neighbors = {};


            for (int k = -h; k <= h; k++) {
                for (int l = -h; l <= h; l++) {
                    int ni = i + k;
                    int nj = j + l;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
                         neighbors.push_back(originalImage.get_pixel(ni, nj));
                    } else {
                        neighbors.push_back(0);

                    }


                }
            }


            int total = std::accumulate(neighbors.begin(), neighbors.end(), 0);
            int average = total / neighbors.size();


            image.set_pixel(i, j, average);
        }
    } // TODO: Your code goes here.
        // 1. Copy the original image for reference.
        // 2. For each pixel, calculate the mean value of its neighbors using a kernel.
        // 3. Update each pixel with the computed mean.
}






// Gaussian Smoothing Filter
#include <cmath>
#include <iostream>

void Filter::apply_gaussian_smoothing(GrayscaleImage& image, int kernelSize, double sigma) {
    int width = image.get_width();
    int height = image.get_height();
    int** originalData = image.get_data();


    int** gaussfilteredData = new int*[height];
    for (int i = 0; i < height; i++) {
        gaussfilteredData[i] = new int[width];
    }


    int kernelHalf = kernelSize / 2;
    double** kernel = new double*[kernelSize];
    for (int i = 0; i < kernelSize; i++) {
        kernel[i] = new double[kernelSize];
    }


    double kernelSum = 0.0;

    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            int x = i - kernelHalf;
            int y = j - kernelHalf;


            double exponent = -(x * x + y * y) / (2.0 * sigma * sigma);
            kernel[i][j] = (1.0 / (2.0 * M_PI * sigma * sigma)) * exp(exponent);


            kernelSum += kernel[i][j];
        }
    }


    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            kernel[i][j] /= kernelSum;
        }
    }


    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            double pixelSum = 0.0;


            for (int i = 0; i < kernelSize; i++) {
                for (int j = 0; j < kernelSize; j++) {

                    int neighborX = x + (i - kernelHalf);
                    int neighborY = y + (j - kernelHalf);


                    if (neighborX >= 0 && neighborX < height && neighborY >= 0 && neighborY < width) {
                        pixelSum += originalData[neighborX][neighborY] * kernel[i][j];
                    }
                }
            }


            gaussfilteredData[x][y] = static_cast<int>(pixelSum);
        }
    }


    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image.set_pixel(i, j, gaussfilteredData[i][j]);
        }
    }


    for (int i = 0; i < height; i++) {
        delete[] gaussfilteredData[i];
    }
    delete[] gaussfilteredData;

    for (int i = 0; i < kernelSize; i++) {
        delete[] kernel[i];
    }
    delete[] kernel;


    // TODO: Your code goes here.
    // 1. Create a Gaussian kernel based on the given sigma value.
    // 2. Normalize the kernel to ensure it sums to 1.
    // 3. For each pixel, compute the weighted sum using the kernel.
    // 4. Update the pixel values with the smoothed results.
}

// Unsharp Masking Filter
void Filter::apply_unsharp_mask(GrayscaleImage& image, int kernelSize, double amount) {
    GrayscaleImage originalimage(image);
    apply_gaussian_smoothing(image, kernelSize, 1);
    int** originalData= originalimage.get_data();
    int** gauss_data=image.get_data();
    int width = image.get_width();
    int height = image.get_height();


    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            double subValue = static_cast<double>(originalData[i][j]) - static_cast<double>(gauss_data[i][j]);
            double value2 = subValue * amount;

            double newkValue = static_cast<double>(originalData[i][j]) + value2;
            if (newkValue < 0){
                newkValue = 0;
            }
            if (newkValue > 255) {
                newkValue = 255;
            }
            image.set_pixel(i, j, static_cast<int>(newkValue));
        }
    }



    
    // TODO: Your code goes here.
    // 1. Blur the image using Gaussian smoothing, use the default sigma given in the header.
    // 2. For each pixel, apply the unsharp mask formula: original + amount * (original - blurred).
    // 3. Clip values to ensure they are within a valid range [0-255].
}
