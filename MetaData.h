#ifndef LAB4_META_DATA
#define LAB4_META_DATA

#include <cstdint>
    
    
#pragma pack(push,1)
struct MetaData{
    int32_t width;           
    int32_t depth;
    int16_t bitsPerPixel;
    int32_t headersize;  
};
#pragma pack(pop)

#endif