#include "BMPImage.h"
#include "PNGImage.h"
#include "JPGImage.h"
#include <memory>

using namespace std;

std::vector<string> parseInput(int argc, char* argv[]) {
    std::vector<string> result;
    if (argc != 5 && argc != 7) {
        std::cout  << "1 Usage: main -f <input_filename> -t <input_filetype> [-r <res>]" << std::endl;
        exit(0);
    }
    if ((string) argv[1] != "-f" && (string) argv[3] != "-t") {
        std::cout  << "2 Usage: main -f <input_filename> -t <input_filetype> [-r <res>]" << std::endl;
        exit(0);
    }

    if ((string) argv[4] == "png" || (string) argv[4] == "jpg" || (string) argv[4] == "bmp") {
        result.emplace_back(argv[2]);
        result.emplace_back(argv[4]);
    }
    else {
        std::cout << "\nUnsupported file type.";
        exit(0);
    }
    return result;
}

int main (int argc, char* argv[]) {
    std::vector<string> input = parseInput(argc, argv);
    string filePath = input[0] + '.' + input[1];
    string fileExt = input[1];
    std::cout << filePath << " Type:" << fileExt;
    //string res = input[2];
    unique_ptr<Image> imgConv;
    if(fileExt == "bmp"){
        imgConv.reset(new BMPImage(filePath.c_str()));
    } else if(fileExt == "png"){
        imgConv.reset(new PNGImage(filePath.c_str()));
    } else if(fileExt == "jpg"){
        imgConv.reset(new JPGImage(filePath.c_str()));
    }
    string asciiString = imgConv->getACIIString();
    cout << asciiString;

    return 0;
}