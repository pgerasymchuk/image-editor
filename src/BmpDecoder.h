#ifndef IMAGE_EDITOR_BMP_DECODER_H
#define IMAGE_EDITOR_BMP_DECODER_H
#include <iostream>
#include "ImageDecoder.h"
#include "MetaData.h"
#include "BmpHeader.h"
using namespace std;

class BmpDecoder : public ImageDecoder {
    BmpHead head;
    int32_t padding;
    size_t bytesLeft(ifstream&);
  public:
    BmpDecoder(string);
    MetaData getMeta();
    bool readNext(vector<Pixel>&);
    bool writeNext(vector<Pixel>);
};

#endif