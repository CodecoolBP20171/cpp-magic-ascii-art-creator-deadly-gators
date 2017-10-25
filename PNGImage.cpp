//
// Created by eros on 24/10/17.
//

#include <fstream>
#include "PNGImage.h"

PNGImage::PNGImage(char* filePath) {
    vector<unsigned char> png;
    lodepng::load_file(png, filePath);

    //decode
    unsigned error = lodepng::decode(image, width, height, filePath);

    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    //std::cout << "Width: " << width << std::endl;
    //std::cout << "Height: " << height << std::endl;

    this->toGrayScale();
    this->toScale();
}


void PNGImage::toGrayScale() {
    for(unsigned y = 0; y < height; y++) {
        for(unsigned x = 0; x < width; x++) {

        }
    }
}

void PNGImage::writeToFile(string& asciiString) {
    ofstream myFile;
    myFile.open("test.txt");
    myFile << asciiString;
    myFile.close();
}

string PNGImage::getACIIString() {
    string result = "";
    if(width > 0 && height > 0) {
       for(unsigned y = 0; y < height; y++) {
            for(unsigned x = 0; x < width; x++) {
                int r = image[y * width * 4 + x * 4 + 0];
                int g = image[y * width * 4 + x * 4 + 1];
                int b = image[y * width * 4 + x * 4 + 2];
                int a = image[y * width * 4 + x * 4 + 3];
                int lightness = ((r + g + b) / 3) * a / 255;
                int min = (r < g && r < b) ? r : (g < b ? g : b);
                int max = (r > g && r > b) ? r : (g > b ? g : b);
                int saturation = max - min;
                if(saturation > 32)
                {
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
    }
    return result;
}

void PNGImage::toScale() {
    //Rescale(Input, 'p', 40);
}