#ifndef LAB4_BMPHEADER_H
#define LAB4_BMPHEADER_H

#define ALIGNMENT_FACTOR 4
#include <cstdint>
#pragma pack(push,1)
struct BmpHead {
    int8_t id[2];            
    int32_t filesize;        
    int16_t reserved[2];     
    int32_t headersize;      
    int32_t infoSize;        
    int32_t width;           
    int32_t depth;          
    int16_t biPlanes;        
    int16_t bitsPerPixel;            
    int32_t biCompression;  
    int32_t biSizeImage;    
    int32_t biXPelsPerMeter; 
    int32_t biYPelsPerMeter; 
    int32_t biClrUsed;       
    int32_t biClrImportant;  
    BmpHead(){
        id[0] = 'B'; id[1] = 'M';
        filesize = 0;
        reserved[0] = 0; reserved[1] = 0;
        headersize = 54;
        infoSize = 40;
        width = 0;
        depth = 0;
        biPlanes = 1;
        bitsPerPixel = 
        biCompression = 0;
        biSizeImage = 0;
        biXPelsPerMeter = 2834;
        biYPelsPerMeter = 2834;
        biClrUsed = 0;
        biClrImportant = 0;
    };
} ;
#pragma pack(pop)
#endif