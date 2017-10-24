//
// Created by alex on 2017.10.24..
//

#include <fstream>
#include "BMPImage.h"

BMPImage::BMPImage(char* filePath) {
    Input.ReadFromFile(filePath);
    this->toGrayScale();
    this->toScale();
}


void BMPImage::toGrayScale() {
    for( int j=0 ; j < Input.TellHeight() ; j++)
    {
        for( int i=0 ; i < Input.TellWidth() ; i++)
        {
            int Temp = (int) floor( 0.299*Input(i,j)->Red +
                                    0.587*Input(i,j)->Green +
                                    0.114*Input(i,j)->Blue );
            ebmpBYTE TempBYTE = (ebmpBYTE) Temp;

            Input(i,j)->Red = TempBYTE;
            Input(i,j)->Green = TempBYTE;
            Input(i,j)->Blue = TempBYTE;
        }
    }
}

void BMPImage::writeToFile(string& asciiString) {
    ofstream myFile;
    myFile.open("test.txt");
    myFile << asciiString;
    myFile.close();
}

string BMPImage::getACIIString() {
    string result = "";
    for( int j=0 ; j < Input.TellHeight() ; j++)
    {
        for( int i=0 ; i < Input.TellWidth() ; i++)
        {
            ebmpBYTE colorRange = Input(i, j)->Red;
            if (colorRange >= 0 && colorRange <= 30)
                result += "@";
            else if (colorRange > 30 && colorRange <= 60)
                result += "#";
            else if (colorRange > 60 && colorRange <= 90)
                result += "8";
            else if (colorRange > 90 && colorRange <= 120)
                result += "&";
            else if (colorRange > 120 && colorRange <= 150)
                result += "o";
            else if (colorRange > 150 && colorRange <= 180)
                result += ":";
            else if (colorRange > 180 && colorRange <= 210)
                result += "*";
            else if (colorRange > 210 && colorRange <= 240)
                result += ".";
            else if (colorRange > 240 && colorRange <= 255)
                result += " ";
        }
        result += "\n";
    }
    return result;
}

void BMPImage::toScale() {
    Rescale(Input, 'p', 40);
}
