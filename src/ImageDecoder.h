#ifndef IMAGE_EDITOR_IMAGE_READER_H
#define IMAGE_EDITOR_IMAGE_READER_H

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include "Pixel.h"
#include "MetaData.h"
#define BITS_PER_BYTE 8

using namespace std;

class ImageDecoder {
  protected:
    MetaData meta;
    ifstream instream;
  public:
    ImageDecoder(string);
    ~ImageDecoder();
    virtual MetaData getMeta() = 0;
    virtual bool readNext(vector<Pixel>&) = 0;
};

#endif


