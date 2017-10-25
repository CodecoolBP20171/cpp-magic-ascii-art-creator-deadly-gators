//
// Created by alex on 2017.10.24..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_IMAGE_H
#define CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_IMAGE_H

#include <iostream>
using namespace std;

class Image {
public:
    Image();

    virtual void toGrayScale();

    virtual string getACIIString();

    virtual void writeToFile(string& asciiString);

    virtual ~Image(){}
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_IMAGE_H
