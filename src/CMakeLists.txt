cmake_minimum_required(VERSION 3.29)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
    Crypto.cpp
    Crypto.h
    Filter.cpp
    Filter.h
    GrayscaleImage.cpp
    GrayscaleImage.h
    main.cpp
    SecretImage.cpp
    SecretImage.h
    stb_image.h
    stb_image_write.h)
