//
// Created by alex on 2017.10.24..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_BMPIMAGE_H
#define CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_BMPIMAGE_H


#include "Image.h"
#include "EasyBMP.h"

class BMPImage : public Image {
public:
    BMPImage(char* filePath);

    void writeToFile(string& asciiString) override;

    string getACIIString() override;

private:
    BMP Input;
    void toGrayScale() override;
    void toScale();
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_BMPIMAGE_H
