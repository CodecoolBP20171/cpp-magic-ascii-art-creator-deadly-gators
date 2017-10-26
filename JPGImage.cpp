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
    string result = "\n";
    if(width > 0 && height > 0) {
        unsigned w2 = 58;
        if(width < w2) w2 = width;
        unsigned h2 = height * w2 / width;
        h2 = (h2 * 2) / 3; //compensate for non-square characters in terminal
        if(h2 > (w2 * 2)) h2 = w2 * 2; //avoid too large output
        for(unsigned y = 0; y < h2; y++)
        {
            for(unsigned x = 0; x < w2; x++)
            {
                unsigned x2 = x * width / w2;
                unsigned y2 = y * height / h2;
                int r = image[y2 * width * 3 + x2 * 3 + 0];
                int g = image[y2 * width * 3 + x2 * 3 + 1];
                int b = image[y2 * width * 3 + x2 * 3 + 2];
                int lightness = (r + g + b) / 3;
                int min = (r < g && r < b) ? r : (g < b ? g : b);
                int max = (r > g && r > b) ? r : (g > b ? g : b);
                int saturation = max - min;
                int letter = 'i'; //i for grey, or r,y,g,c,b,m for colors
                if(saturation > 32)
                {
                    int h = lightness >= (min + max) / 2;
                    if(h) letter = (min == r ? 'c' : (min == g ? 'm' : 'y'));
                    else letter = (max == r ? 'r' : (max == g ? 'g' : 'b'));
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
    }
    return result;
}

void JPGImage::writeToFile(string &asciiString) {
    Image::writeToFile(asciiString);
}


void JPGImage::toScale() {

}
