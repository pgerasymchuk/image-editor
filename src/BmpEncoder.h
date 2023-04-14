#ifndef IMAGE_EDITOR_BMP_ENCODER_H
#define IMAGE_EDITOR_BMP_ENCODER_H

#include "ImageEncoder.h"
#include "BmpHeader.h"
#include "MetaData.h"

class BmpEncoder : public ImageEncoder {
    int32_t padding;
  public:
    BmpEncoder(string);
    bool writeHeader(MetaData meta);
    bool writeNext(vector<Pixel>);
};

#endif