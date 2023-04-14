#ifndef LAB4_PIXEL_H
#define LAB4_PIXEL_H

#include <cstdint>
#include <vector>
using namespace std;

struct Pixel {
    int16_t size; //number of bytes
    vector<int8_t> bytes;
    Pixel(int16_t size) : size(size), bytes(size, 0) {}
};

#endif