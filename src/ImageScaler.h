#ifndef LAB4_IMAGE_SCALER_H
#define LAB4_IMAGE_SCALER_H

#include <fstream>
#include <vector>
#include <iostream>
#include "ImageDecoder.h"
#include "ImageEncoder.h"
#include "BmpDecoder.h"
#include "Pixel.h"
using namespace std;

class ImageScaler {
    ImageDecoder* decoder;
    ImageEncoder* encoder;
  public:
    ImageScaler(ImageDecoder*, ImageEncoder*);
    void scale(int);
};

#endif