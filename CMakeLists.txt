cmake_minimum_required(VERSION 3.8)
project(cpp-magic-ascii-art-creator-deadly-gators)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp EasyBMP.h EasyBMP.cpp EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h Image.cpp Image.h BMPImage.cpp BMPImage.h lodepng.cpp lodepng.h PNGImage.cpp PNGImage.h)
add_executable(cpp-magic-ascii-art-creator-deadly-gators ${SOURCE_FILES} main.cpp)