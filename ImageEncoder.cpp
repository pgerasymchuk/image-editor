#include "ImageEncoder.h"

ImageEncoder::ImageEncoder(string outputPath) {
    outstream = ofstream(outputPath, ios::binary);
    if (! outstream){
        throw ofstream::failure("Impossible to open the file "+outputPath+" for writing!");
    }
}

ImageEncoder::~ImageEncoder() {
    if (outstream.is_open()){
        outstream.close();
    }
}

