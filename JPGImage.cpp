//
// Created by alex on 2017.10.25..
//
#include "JPGImage.h"


JPGImage::JPGImage(const char* filePath) {
    this->loadImage(filePath);
    image = njGetImage();
    width = njGetWidth();
    height = njGetHeight();
}

void JPGImage::loadImage(const char* filePath) {
    int size;
    char *buf;
    FILE *f;
    f = fopen(filePath, "rb");
    if (!f) {
        printf("Error opening the input file.\n");
    }
    fseek(f, 0, SEEK_END);
    size = (int) ftell(f);
    buf = (char*) malloc(size);
    fseek(f, 0, SEEK_SET);
    size = (int) fread(buf, 1, size, f);
    fclose(f);

    njInit();
    if (njDecode(buf, size)) {
        free((void*)buf);
        printf("Error decoding the input file.\n");
    }
    free((void*)buf);
}

string JPGImage::getACIIString() {
    std::string result = "";
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int r = image[y * width * 3 + x * 3 + 0];
            int g = image[y * width * 3 + x * 3 + 1];
            int b = image[y * width * 3 + x * 3 + 2];
            int lightness = ((r + g + b) / 3);
            int min = (r < g && r < b) ? r : (g < b ? g : b);
            int max = (r > g && r > b) ? r : (g > b ? g : b);
            int saturation = max - min;
            if (saturation > 32) {
                int h = lightness >= (min + max) / 2;
            }
            if (lightness >= 0 && lightness <= 30)
                result += '@';
           else if (lightness > 30 && lightness <= 60)
                result += '#';
            else if (lightness > 60 && lightness <= 90)
                result += '8';
            else if (lightness > 90 && lightness <= 120)
                result += '&';
            else if (lightness > 120 && lightness <= 150)
                result += 'o';
            else if (lightness > 150 && lightness <= 180)
                result += ':';
            else if (lightness > 180 && lightness <= 210)
                result += '*';
            else if (lightness > 210 && lightness <= 240)
                result += '.';
            else if (lightness > 240 && lightness <= 255)
                result += ' ';
        }
        result += '\n';
    }

    return result;
}

void JPGImage::writeToFile(string &asciiString) {
    Image::writeToFile(asciiString);
}


void JPGImage::toScale() {

}
