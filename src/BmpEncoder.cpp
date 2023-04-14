#include "BmpEncoder.h"

BmpEncoder::BmpEncoder(string outputPath) : ImageEncoder(outputPath) {}

bool BmpEncoder::writeHeader(MetaData meta){
    BmpHead head; 
    head.width = meta.width;
    head.depth = meta.depth;
    head.bitsPerPixel = meta.bitsPerPixel;
    padding = (ALIGNMENT_FACTOR - (head.width*head.bitsPerPixel/BITS_PER_BYTE % ALIGNMENT_FACTOR)) % ALIGNMENT_FACTOR;
    head.filesize = head.headersize + head.depth*(head.width*head.bitsPerPixel/BITS_PER_BYTE+padding);
    head.biSizeImage = head.width*head.depth*head.bitsPerPixel/BITS_PER_BYTE;
    if (outstream.write((char*)&head, sizeof(BmpHead))){
        return true;
    }
    else {
        return false;
    }
}

bool BmpEncoder::writeNext(vector<Pixel> row){
    for (int i=0; i<row.size(); i++){
        if(! outstream.write((char*)((row[i].bytes).data()), row[i].size)){
            return false;
        }
    }
    for (int j=0; j<padding; j++){
        outstream.put(0);
    }
    return true;
}
