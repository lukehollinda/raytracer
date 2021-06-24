#include "bitMapUtility.h"
#include <iterator>
#include <fstream>
#include <iostream>

void generateBitmapImage(Image image, std::string imageFileName)
{
    int widthInBytes = image.getWidth() * BYTES_PER_PIXEL;

    //Rows must be padded to fit a 4 byte multiple.  (ie) width = 1, bytesPerPixel = 3, padding  
    const char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;
    int stride = (widthInBytes) + paddingSize;

    std::fstream imageOutput;
    imageOutput.open(imageFileName, std::fstream::out | std::fstream::trunc);

    
    const char* fileHeader = createBitmapFileHeader(image.getHeight(), stride);
    imageOutput.write(fileHeader, FILE_HEADER_SIZE);


    char* infoHeader = createBitmapInfoHeader(image.getHeight(), image.getWidth() );
    imageOutput.write(infoHeader, INFO_HEADER_SIZE);

    //fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);

    for (int i = 0; i < image.getHeight(); i++) 
    {
        std::vector<char> row = image.outputRowAsBytes(i);
        copy(row.cbegin(), row.cend(), std::ostreambuf_iterator<char>(imageOutput));
        imageOutput.write(padding, paddingSize);
    }

    imageOutput.flush();
    imageOutput.close();
}


/*
*   Bitmap Standard found here - http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm
*/
char* createBitmapFileHeader (int height, int stride)
{
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    static char fileHeader[] = {
        0,0,     // Signature (BM)
        0,0,0,0, // File Size in Bytes
        0,0,0,0, // Reserved / Unused
        0,0,0,0, // DataOffset - Offset from beginning of file to the beginning of the bitmap data
    };

    fileHeader[ 0] = (char)('B');
    fileHeader[ 1] = (char)('M');
    fileHeader[ 2] = (char)(fileSize      );
    fileHeader[ 3] = (char)(fileSize >>  8);
    fileHeader[ 4] = (char)(fileSize >> 16);
    fileHeader[ 5] = (char)(fileSize >> 24);
    fileHeader[10] = (char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

char* createBitmapInfoHeader (int height, int width)
{
    static char infoHeader[] = {
        0,0,0,0, // Size of InfoHeader
        0,0,0,0, // Horizontal Width of bitmap in pixels
        0,0,0,0, // Vertical Hieght of bitmap in pixels
        0,0,     // Number of Planes (=1)
        0,0,     // Bits per pixel
        0,0,0,0, // Compression
        0,0,0,0, // image size (Can be zero if compression is zero)
        0,0,0,0, /// horizontal resolution
        0,0,0,0, /// vertical resolution
        0,0,0,0, /// colors in color table
        0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (char)(width      );
    infoHeader[ 5] = (char)(width >>  8);
    infoHeader[ 6] = (char)(width >> 16);
    infoHeader[ 7] = (char)(width >> 24);
    infoHeader[ 8] = (char)(height      );
    infoHeader[ 9] = (char)(height >>  8);
    infoHeader[10] = (char)(height >> 16);
    infoHeader[11] = (char)(height >> 24);
    infoHeader[12] = (char)(1);
    infoHeader[14] = (char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}