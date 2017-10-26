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
    virtual ~Image() {}

    virtual string getACIIString() = 0;

    virtual void writeToFile(string& asciiString) = 0;
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_DEADLY_GATORS_IMAGE_H
