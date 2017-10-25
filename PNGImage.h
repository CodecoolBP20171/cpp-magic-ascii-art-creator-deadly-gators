//
// Created by eros on 24/10/17.
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_PNGIMAGE_H
#define CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_PNGIMAGE_H


#include "Image.h"
#include "lodepng.h"

class PNGImage : public Image {
public:
    PNGImage(char* filePath);

    void writeToFile(string& asciiString) override;

    string getACIIString() override;

private:
    vector<unsigned char> image;
    unsigned width, height;
    void toGrayScale() override;
    void toScale();
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_PNGIMAGE_H
