#ifndef LAB4_IMAGE_ENCODER_H
#define LAB4_IMAGE_ENCODER_H

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include "Pixel.h"
#include "MetaData.h"
#define BITS_PER_BYTE 8

using namespace std;

class ImageEncoder {
  protected:
    ofstream outstream;
  public:
    ImageEncoder(string);
    ~ImageEncoder();
    virtual bool writeHeader(MetaData) = 0;
    virtual bool writeNext(vector<Pixel>) = 0;
};

#endif


