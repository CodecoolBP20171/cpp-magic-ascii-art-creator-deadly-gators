#include "BMPImage.h"
#include <memory>

using namespace std;

int main (int argc, char* argv[]) {
    if (argc != 3) {
        cout << "blabal"  << endl << endl;
        return 1;
    }

    unique_ptr<BMPImage> bmpConv(new BMPImage(argv[1]));

    string asciiString = bmpConv->getACIIString();
    cout << asciiString;
    bmpConv->writeToFile(asciiString);
    return 0;
}