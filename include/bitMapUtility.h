#pragma once
#include <string>
#include <vector>
#include "image.h"


const int BYTES_PER_PIXEL = 3; // red, green, & blue
const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;

void generateBitmapImage(Image image, std::string imageFileName);
unsigned char* createBitmapFileHeader(int height, int stride);
unsigned char* createBitmapInfoHeader(int height, int width);

