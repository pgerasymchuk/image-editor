#include "ImageScaler.h"

ImageScaler::ImageScaler(ImageDecoder* decoder, ImageEncoder* encoder) : decoder(decoder) , encoder(encoder) {}

void ImageScaler::scale(int factor){
    MetaData meta = decoder->getMeta();
    int32_t oldDepth = meta.depth;
    meta.width *= factor;
    meta.depth *= factor;
    encoder->writeHeader(meta);
    vector<Pixel> row;
    vector<Pixel> scaledRow;
    for (int i=0; i<oldDepth; i++){
        if (decoder->readNext(row)){
            scaledRow.clear();
            for (int i=0; i < row.size(); i++){
                for (int j=0; j < factor; j++){
                    scaledRow.push_back(row[i]);
                }
            } 
            for (int i=0; i < factor; i++){
                encoder->writeNext(scaledRow);
            }
        }
        else {
            throw invalid_argument("Image frame is corrupted!");
        }
    }
}
