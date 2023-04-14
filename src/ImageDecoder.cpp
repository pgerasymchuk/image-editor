#include "ImageDecoder.h"

ImageDecoder::ImageDecoder(string inputPath) {
    instream = ifstream(inputPath, ios::binary);
    if (! instream){
        throw ifstream::failure("Impossible to open the file "+inputPath+" for reading!");
    }
}

ImageDecoder::~ImageDecoder() {
    if (instream.is_open()){
        instream.close();
    }
}

