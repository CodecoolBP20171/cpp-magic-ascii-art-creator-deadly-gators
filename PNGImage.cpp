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

}

void PNGImage::writeToFile(string& asciiString) {
    ofstream myFile;
    myFile.open("test.txt");
    myFile << asciiString;
    myFile.close();
}

string PNGImage::getACIIString() {
    if(width > 0 && height > 0)
    {
        std::cout << std::endl << "ASCII Art Preview: " << std::endl;
        unsigned w2 = 48;
        if(width < w2) w2 = width;
        unsigned h2 = height * w2 / width;
        h2 = (h2 * 2) / 3; //compensate for non-square characters in terminal
        if(h2 > (w2 * 2)) h2 = w2 * 2; //avoid too large output

        std::cout << '+';
        for(unsigned x = 0; x < w2; x++) std::cout << '-';
        std::cout << '+' << std::endl;
        for(unsigned y = 0; y < h2; y++)
        {
            std::cout << "|";
            for(unsigned x = 0; x < w2; x++)
            {
                unsigned x2 = x * width / w2;
                unsigned y2 = y * height / h2;
                int r = image[y2 * width * 4 + x2 * 4 + 0];
                int g = image[y2 * width * 4 + x2 * 4 + 1];
                int b = image[y2 * width * 4 + x2 * 4 + 2];
                int a = image[y2 * width * 4 + x2 * 4 + 3];
                int lightness = ((r + g + b) / 3) * a / 255;
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
                int symbol = ' ';
                if(lightness > 224) symbol = '@';
                else if(lightness > 128) symbol = letter - 32;
                else if(lightness > 32) symbol = letter;
                else if(lightness > 16) symbol = '.';
                std::cout << (char)symbol;
            }
            std::cout << "|";
            std::cout << std::endl;
        }
        std::cout << '+';
        for(unsigned x = 0; x < w2; x++) std::cout << '-';
        std::cout << '+' << std::endl;
    }
    return "TODO...";
}

void PNGImage::toScale() {
    //Rescale(Input, 'p', 40);
}