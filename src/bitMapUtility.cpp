#include "bitMapUtility.h"
#include <iterator>
#include <fstream>
#include <iostream>

void generateBitmapImage(Image image, std::string imageFileName)
{
    int widthInBytes = image.getWidth() * BYTES_PER_PIXEL;

    //Rows must be padded to fit a 4 byte multiple.  (ie) width = 1, bytesPerPixel = 3, padding  
    const unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;
    int stride = (widthInBytes) + paddingSize;

    std::fstream imageOutput;
    imageOutput.open(imageFileName, std::fstream::out | std::fstream::trunc | std::fstream::binary);

    
    const unsigned char* fileHeader = createBitmapFileHeader(image.getHeight(), stride);
    imageOutput.write((char *)fileHeader, FILE_HEADER_SIZE);


    const unsigned char* infoHeader = createBitmapInfoHeader(image.getHeight(), image.getWidth() );
    imageOutput.write((char *)infoHeader, INFO_HEADER_SIZE);


    for (int i = 0; i < image.getHeight(); i++) 
    {
        std::vector<unsigned char> row = image.outputRowAsBytes(i);
        // copy(row.cbegin(), row.cend(), std::ostreambuf_iterator<char>(imageOutput));
        for(int j = 0; j < image.getWidth(); j++)
        {
            imageOutput.write((char *)&row.at(j*3), 3);
        }
        imageOutput.write((char *)padding, paddingSize);
    }

    imageOutput.flush();
    imageOutput.close();
}


/*
*   Bitmap Standard found here - http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm
*/
unsigned char* createBitmapFileHeader (int height, int stride)
{
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    static unsigned char fileHeader[] = {
        0,0,     // Signature (BM)
        0,0,0,0, // File Size in Bytes
        0,0,0,0, // Reserved / Unused
        0,0,0,0, // DataOffset - Offset from beginning of file to the beginning of the bitmap data
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader (int height, int width)
{
    static unsigned char infoHeader[] = {
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

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}