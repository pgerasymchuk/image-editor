#include "BmpDecoder.h"

BmpDecoder::BmpDecoder(string inputPath) : ImageDecoder(inputPath) { 
    if (! instream.read((char*)&head, sizeof(BmpHead))){
        throw ifstream::failure("Image header is corrupted!");
    }
    if (head.id[0]!='B' || head.id[1]!='M'){
        throw invalid_argument("Invalid file format!");
    }
    if (head.bitsPerPixel % BITS_PER_BYTE){
        throw invalid_argument("Image colour depth not supported!");
    }
    padding = (ALIGNMENT_FACTOR - (head.width*head.bitsPerPixel/BITS_PER_BYTE % ALIGNMENT_FACTOR)) % ALIGNMENT_FACTOR;
    meta.width = head.width;
    meta.depth = head.depth;
    meta.bitsPerPixel = head.bitsPerPixel;
}

MetaData BmpDecoder::getMeta(){
    return meta;
}

size_t BmpDecoder::bytesLeft(ifstream& file){
    streampos currentPosition = file.tellg();
    file.seekg(0, ios::end);
    streampos endPosition = file.tellg();
    size_t bytesLeft = endPosition - currentPosition;
    file.seekg(currentPosition);
    return bytesLeft;
}

bool BmpDecoder::readNext(vector<Pixel>& row){
    row.clear();
    int pixelSize = head.bitsPerPixel/BITS_PER_BYTE;
    int bufferSize = head.width*pixelSize + padding;
    if (bytesLeft(instream) >= bufferSize){
        for (int i=0; i<head.width; i++){
            Pixel pixel(pixelSize);
            if (! instream.read((char*)((pixel.bytes).data()), pixel.size)) {
                return false;
            }
            row.push_back(pixel);
        }
        instream.seekg(padding, ios::cur);
        return true;
    }
    else {
        return false;
    }

}
