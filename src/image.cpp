
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include "image.h"
using namespace std;

Image::Image() {
}

void Image::read(const string& inName) {
    //(14) Read in the .tga file
    this->stream = ifstream(inName, ios_base::binary);

    //(15) Check if the file is opening
    if(!stream.is_open()) {
        cout << "Invalid argument, file does not exist." << endl;
        throw runtime_error("Could not open file.");
    }


    //(16) Read in each element of the .tga file
    stream.read((char*)&header.idLength , sizeof(header.idLength));
    stream.read((char*)&header.colorMapType , sizeof(header.colorMapType));
    stream.read((char*)&header.dataTypeCode , sizeof(header.dataTypeCode));
    stream.read((char*)&header.colorMapOrigin , sizeof(header.colorMapOrigin));
    stream.read((char*)&header.colorMapLength , sizeof(header.colorMapLength));
    stream.read((char*)&header.colorMapDepth , sizeof(header.colorMapDepth));
    stream.read((char*)&header.xOrigin , sizeof(header.xOrigin));
    stream.read((char*)&header.yOrigin, sizeof(header.yOrigin));
    stream.read((char*)&header.width , sizeof(header.width));
    stream.read((char*)&header.height , sizeof(header.height));
    stream.read((char*)&header.bitsPerPixel , sizeof(header.bitsPerPixel));
    stream.read((char*)&header.imageDescriptor , sizeof(header.imageDescriptor));


    //(17) Get the image size by multiplying the image height and width
    int imageSize = (int)header.height * header.width;

    //(18) Create a for loop to read in all the pixels
    for(int i = 0; i < imageSize; i++) {
        //(19) Create a new pixel object for each iteration
        Pixel pixel;

        //(20) Read in all the pixels
        // .tga files are read in reverse order rgb -> bgr
        stream.read((char*)&pixel.blue, sizeof(pixel.blue));
        stream.read((char*)&pixel.green, sizeof(pixel.green));
        stream.read((char*)&pixel.red, sizeof(pixel.red));

        //(21) Push in each pixel to the pixel vector
        pixelVect.push_back(pixel);
    }
}

void Image::readSRC(const string& inName) {
    //(14) Read in the .tga file
    this->stream = ifstream(inName, ios_base::binary);

    //(15) Check if the file is opening
    if(!stream.is_open()) {
        cout << "File does not exist." << endl;
        throw runtime_error("Could not open file.");
    }


    //(16) Read in each element of the .tga file
    stream.read((char*)&header.idLength , sizeof(header.idLength));
    stream.read((char*)&header.colorMapType , sizeof(header.colorMapType));
    stream.read((char*)&header.dataTypeCode , sizeof(header.dataTypeCode));
    stream.read((char*)&header.colorMapOrigin , sizeof(header.colorMapOrigin));
    stream.read((char*)&header.colorMapLength , sizeof(header.colorMapLength));
    stream.read((char*)&header.colorMapDepth , sizeof(header.colorMapDepth));
    stream.read((char*)&header.xOrigin , sizeof(header.xOrigin));
    stream.read((char*)&header.yOrigin, sizeof(header.yOrigin));
    stream.read((char*)&header.width , sizeof(header.width));
    stream.read((char*)&header.height , sizeof(header.height));
    stream.read((char*)&header.bitsPerPixel , sizeof(header.bitsPerPixel));
    stream.read((char*)&header.imageDescriptor , sizeof(header.imageDescriptor));


    //(17) Get the image size by multiplying the image height and width
    int imageSize = (int)header.height * header.width;

    //(18) Create a for loop to read in all the pixels
    for(int i = 0; i < imageSize; i++) {
        //(19) Create a new pixel object for each iteration
        Pixel pixel;

        //(20) Read in all the pixels
        // .tga files are read in reverse order rgb -> bgr
        stream.read((char*)&pixel.blue, sizeof(pixel.blue));
        stream.read((char*)&pixel.green, sizeof(pixel.green));
        stream.read((char*)&pixel.red, sizeof(pixel.red));

        //(21) Push in each pixel to the pixel vector
        pixelVect.push_back(pixel);
    }
}

void Image::write(const string& outName) {
    //(22) Create a .tga file
    ofstream stream(outName, ios_base::binary);

    //(23) Write out each .tga file header element
    stream.write((char*)&header.idLength , sizeof(header.idLength));
    stream.write((char*)&header.colorMapType , sizeof(header.colorMapType));
    stream.write((char*)&header.dataTypeCode , sizeof(header.dataTypeCode));
    stream.write((char*)&header.colorMapOrigin , sizeof(header.colorMapOrigin));
    stream.write((char*)&header.colorMapLength , sizeof(header.colorMapLength));
    stream.write((char*)&header.colorMapDepth , sizeof(header.colorMapDepth));
    stream.write((char*)&header.xOrigin , sizeof(header.xOrigin));
    stream.write((char*)&header.yOrigin, sizeof(header.yOrigin));
    stream.write((char*)&header.width , sizeof(header.width));
    stream.write((char*)&header.height , sizeof(header.height));
    stream.write((char*)&header.bitsPerPixel , sizeof(header.bitsPerPixel));
    stream.write((char*)&header.imageDescriptor , sizeof(header.imageDescriptor));

    //(24) Create a for loop to write out each pixel
    for(int i = 0; i < pixelVect.size(); i++) {
        Pixel pixel = pixelVect[i];
        //(25) Write out each image pixel
        stream.write((char*)&pixel.blue, sizeof(pixel.blue));
        stream.write((char*)&pixel.green, sizeof(pixel.green));
        stream.write((char*)&pixel.red, sizeof(pixel.red));
    }
}

void Image::Clamp(int& value) {
    if (value > 255) {
        value = 255;
    }
    if (value < 0) {
        value = 0;
    }
}

void Image::Compare(const Image &example) {
    //compare header
    if (header.idLength != example.header.idLength) {
        cout << "idLength";
    } else if (header.colorMapType != example.header.colorMapType) {
        cout << "colorMapType";
    } else if (header.dataTypeCode != example.header.dataTypeCode) {
        cout << "dataTypeCode";
    } else if (header.colorMapOrigin != example.header.colorMapOrigin) {
        cout << "colorMapOrigin";
    } else if (header.colorMapLength != example.header.colorMapLength) {
        cout << "colorMapLength";
    } else if (header.colorMapDepth != example.header.colorMapDepth) {
        cout << "colorMapDepth";
    } else if (header.xOrigin != example.header.xOrigin) {
        cout << "xOrigin";
    } else if (header.yOrigin != example.header.yOrigin) {
        cout << "yOrigin";
    } else if (header.width != example.header.width) {
        cout << "width";
    } else if (header.height != example.header.height) {
        cout << "height";
    } else if (header.bitsPerPixel != example.header.bitsPerPixel) {
        cout << "bitsPerPixel";
    } else if (header.imageDescriptor != example.header.imageDescriptor) {
        cout << "imageDescriptor";
    }
    //compare pixels
    for (int i = 0; i < pixelVect.size(); i++) {
        if (pixelVect.at(i).blue != example.pixelVect.at(i).blue) {
            cout << i << " blue" << endl;
        }
        if (pixelVect.at(i).green != example.pixelVect.at(i).green) {
            cout << i << " green" << endl;
        }
        if (pixelVect.at(i).red != example.pixelVect.at(i).red) {
            cout << i << " red" << (float)example.pixelVect.at(i).red << "ex my" << (float)pixelVect.at(i).red << endl;
        }
    }
}

void Image::Multiply(const Image &otherImage) {
    float tempNormMine;
    float tempNormOther;
    float tempSolution;
    unsigned char solution;
    for(int i = 0; i < pixelVect.size(); i++) {
        //pixelVect.at(i).blue = 200;
        tempNormMine = (float)pixelVect.at(i).blue / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).blue / 255;
        tempSolution = tempNormMine * tempNormOther;
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).blue = solution;

        tempNormMine = (float)pixelVect.at(i).green / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).green / 255;
        tempSolution = tempNormMine * tempNormOther;
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).green = solution;

        tempNormMine = (float)pixelVect.at(i).red / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).red / 255;
        tempSolution = tempNormMine * tempNormOther;
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).red = solution;
    }
}

void Image::Subtract(const Image &otherImage) {
    int temp;
    for (int i = 0; i < pixelVect.size(); i++) {
        //Mine on top; Other on bottom
        temp = (int)pixelVect.at(i).blue - (int)otherImage.pixelVect.at(i).blue;
        Clamp(temp);
        pixelVect.at(i).blue = temp;

        temp = (int)pixelVect.at(i).green - (int)otherImage.pixelVect.at(i).green;
        Clamp(temp);
        pixelVect.at(i).green = temp;

        temp = (int)pixelVect.at(i).red - (int)otherImage.pixelVect.at(i).red;
        Clamp(temp);
        pixelVect.at(i).red = temp;
    }
}

void Image::Screen(const Image &otherImage) {
    //1 - [(1-NP1) * (1-NP2)]
    //NP1 Mine top; NP2 Other bottom
    float tempNormMine;
    float tempNormOther;
    float tempSolution;
    unsigned char solution;
    for(int i = 0; i < pixelVect.size(); i++) {
        //pixelVect.at(i).blue = 200;
        tempNormMine = (float)pixelVect.at(i).blue / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).blue / 255;
        tempSolution = 1 - ((1 - tempNormMine) * (1 - tempNormOther));
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).blue = solution;

        tempNormMine = (float)pixelVect.at(i).green / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).green / 255;
        tempSolution = 1 - ((1 - tempNormMine) * (1 - tempNormOther));
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).green = solution;

        tempNormMine = (float)pixelVect.at(i).red / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).red / 255;
        tempSolution = 1 - ((1 - tempNormMine) * (1 - tempNormOther));
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).red = solution;
    }
}

void Image::Overlay(const Image &otherImage) {
    //NP2 <= 0.5        2 * NP1 * NP2
    //NP2 > 0.5         1 - [2 * (1 - NP1) * (1 - NP2)]
    float tempNormMine;
    float tempNormOther;
    float tempSolution;
    unsigned char solution;

    for(int i = 0; i < pixelVect.size(); i++) {
        tempNormMine = (float)pixelVect.at(i).blue / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).blue / 255;
        if(tempNormOther > 0.5) {
            tempSolution = 1 - (2 * (1 - tempNormMine) * (1 - tempNormOther));
        } else {
            tempSolution = 2 * tempNormMine * tempNormOther;
        }
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).blue = solution;

        tempNormMine = (float)pixelVect.at(i).green / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).green / 255;
        if(tempNormOther > 0.5) {
            tempSolution = 1 - (2 * (1 - tempNormMine) * (1 - tempNormOther));
        } else {
            tempSolution = 2 * tempNormMine * tempNormOther;
        }
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).green = solution;

        tempNormMine = (float)pixelVect.at(i).red / 255;
        tempNormOther = (float)otherImage.pixelVect.at(i).red / 255;
        if(tempNormOther > 0.5) {
            tempSolution = 1 - (2 * (1 - tempNormMine) * (1 - tempNormOther));
        } else {
            tempSolution = 2 * tempNormMine * tempNormOther;
        }
        tempSolution = (tempSolution * 255) + 0.5f;
        solution = (unsigned char)tempSolution;
        pixelVect.at(i).red = solution;
    }
}

void Image::SpecificAdd(const int &value, const string &color) {
    int tempSolution;
    if (color == "blue") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = (int)pixelVect.at(i).blue + value;
            Clamp(tempSolution);
            pixelVect.at(i).blue = (unsigned char)tempSolution;
        }
    } else if (color == "green") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = (int)pixelVect.at(i).green + value;
            Clamp(tempSolution);
            pixelVect.at(i).green = (unsigned char)tempSolution;
        }
    } else if (color == "red") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = (int)pixelVect.at(i).red + value;
            Clamp(tempSolution);
            pixelVect.at(i).red = (unsigned char)tempSolution;
        }
    } else {
        cout << "What color in RGB isn't red, green, or blue? Stay in school, kids." << endl;
    }
}

void Image::SpecificMultiply(const float &value, const string &color) {
    float tempSolution;
    unsigned char solution;

    if (color == "blue") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = (float)pixelVect.at(i).blue * value;
            if (tempSolution > 255) {
                tempSolution = 255;
            } else if (tempSolution < 0) {
                tempSolution = 0;
            }
            solution = (unsigned char)tempSolution;
            pixelVect.at(i).blue = solution;
        }
    } else if (color == "green") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = (float)pixelVect.at(i).green * value;
            if (tempSolution > 255) {
                tempSolution = 255;
            } else if (tempSolution < 0) {
                tempSolution = 0;
            }
            solution = (unsigned char)tempSolution;
            pixelVect.at(i).green = solution;
        }
    } else if (color == "red") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = (float)pixelVect.at(i).red * value;
            if (tempSolution > 255) {
                tempSolution = 255;
            } else if (tempSolution < 0) {
                tempSolution = 0;
            }
            solution = (unsigned char)tempSolution;
            pixelVect.at(i).red = solution;
        }
    } else {
        cout << "What color in RGB isn't red, green, or blue? Stay in school, kids." << endl;
    }
}

void Image::BlackAndWhite(const string &color) {
    unsigned char grey_val;
    if (color == "blue") {
        for(int i = 0; i < pixelVect.size(); i++) {
            grey_val = pixelVect.at(i).blue;
            pixelVect.at(i).green = grey_val;
            pixelVect.at(i).red = grey_val;
        }
    } else if (color == "green") {
        for(int i = 0; i < pixelVect.size(); i++) {
            grey_val = pixelVect.at(i).green;
            pixelVect.at(i).blue = grey_val;
            pixelVect.at(i).red = grey_val;
        }
    } else if (color == "red") {
        for(int i = 0; i < pixelVect.size(); i++) {
            grey_val = pixelVect.at(i).red;
            pixelVect.at(i).green = grey_val;
            pixelVect.at(i).blue = grey_val;
        }
    } else {
        cout << "What color in RGB isn't red, green, or blue? Stay in school, kids." << endl;
    }
}

void Image::Add(const Image &otherImage) {
    int tempSolution;
    for(int i = 0; i < pixelVect.size(); i++) {
        tempSolution = (int)pixelVect.at(i).blue + (int)otherImage.pixelVect.at(i).blue;
        Clamp(tempSolution);
        pixelVect.at(i).blue = (unsigned char)tempSolution;

        tempSolution = (int)pixelVect.at(i).green + (int)otherImage.pixelVect.at(i).green;
        Clamp(tempSolution);
        pixelVect.at(i).green = (unsigned char)tempSolution;

        tempSolution = (int)pixelVect.at(i).red + (int)otherImage.pixelVect.at(i).red;
        Clamp(tempSolution);
        pixelVect.at(i).red = (unsigned char)tempSolution;
    }
}

void Image::ReplaceChannel(const Image &otherImage, const string& color) {
    unsigned char tempSolution;
    if (color == "blue") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = otherImage.pixelVect.at(i).blue;
            pixelVect.at(i).blue = tempSolution;
        }
    } else if (color == "green") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = otherImage.pixelVect.at(i).green;
            pixelVect.at(i).green = tempSolution;
        }
    } else if (color == "red") {
        for(int i = 0; i < pixelVect.size(); i++) {
            tempSolution = otherImage.pixelVect.at(i).red;
            pixelVect.at(i).red = tempSolution;
        }
    } else {
        cout << "What color in RGB isn't red, green, or blue? Stay in school, kids." << endl;
    }

}

void Image::UpsideDown() {
    unsigned char temp;
    if (pixelVect.size() % 2 == 0) { //pixelVect.size even
        for (int i = 0; i < (pixelVect.size() / 2); i++) {
            temp = pixelVect.at(i).blue;
            pixelVect.at(i).blue = pixelVect.at(pixelVect.size() - i - 1).blue;
            pixelVect.at(pixelVect.size() - i - 1).blue = temp;

            temp = pixelVect.at(i).green;
            pixelVect.at(i).green = pixelVect.at(pixelVect.size() - i - 1).green;
            pixelVect.at(pixelVect.size() - i - 1).green = temp;

            temp = pixelVect.at(i).red;
            pixelVect.at(i).red = pixelVect.at(pixelVect.size() - i - 1).red;
            pixelVect.at(pixelVect.size() - i - 1).red = temp;
        }
    } else { //pixelVect.size odd
        for (int i = 0; i < ((pixelVect.size() - header.width) / 2); i++) {
            temp = pixelVect.at(i).blue;
            pixelVect.at(i).blue = pixelVect.at(pixelVect.size() - i - 1).blue;
            pixelVect.at(pixelVect.size() - i - 1).blue = temp;

            temp = pixelVect.at(i).green;
            pixelVect.at(i).green = pixelVect.at(pixelVect.size() - i - 1).green;
            pixelVect.at(pixelVect.size() - i - 1).green = temp;

            temp = pixelVect.at(i).red;
            pixelVect.at(i).red = pixelVect.at(pixelVect.size() - i - 1).red;
            pixelVect.at(pixelVect.size() - i - 1).red = temp;
        }
    }
}
/*
void Image::clearData() {

}
*/




