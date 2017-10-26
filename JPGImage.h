//
// Created by alex on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_JPGIMAGE_H
#define CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_JPGIMAGE_H

extern "C" {
#include "nanojpeg.h"
}

#include "Image.h"
#include <iostream>

using namespace std;

class JPGImage : public Image {
public:
    JPGImage(const char* filePath);

    void writeToFile(string& asciiString) override;

    string getACIIString() override;

private:
    unsigned char* image;
    int width;
    int height;
    void loadImage(const char* filePath);
    void toScale();
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_JPGIMAGE_H
