#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//(1) Declare a Header struct
struct Header {
    //(2) Declare each Header element
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};


//(3) Declare a Pixel struct
struct Pixel {
    //(4) Declare each Pixel element
    unsigned char blue; //number between 0 and 255
    unsigned char green; //unsigned char is an 8bit int from 0-255 (can't be below 0)
    unsigned char red; // 0 (dark) - 255 (bright)
};


//(5) Declare an Image class
class Image {
    //(6) Declare private data member of the Image class
private:
    //(7) Declare a name
    string name;
    //(8) Declare a stream (ifstream)
    ifstream stream;

public:
    //(9) Declare a header for the Image
    Header header;
    //(10) Declare a vector of pixels
    vector<Pixel> pixelVect;

    //constructor
    Image();
    void read(const string& inName);
    void readSRC(const string& inName);
    void write(const string& outName);
    void Clamp(int& value);
    void Compare(const Image& example);
    void Multiply(const Image& otherImage);
    void Subtract(const Image& otherImage);
    void Screen(const Image& otherImage);
    //void ScreenOtherTop(const Image &otherImage);
    void Overlay(const Image& otherImage);
    void SpecificAdd(const int& value, const string& color);
    void SpecificMultiply(const float& value, const string& color);
    void BlackAndWhite(const string& color);
    void Add(const Image& otherImage);
    void ReplaceChannel(const Image& otherImage, const string& color);
    void UpsideDown();
    //void clearData();
};

