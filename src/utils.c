#include <estia-image.h>
#include <stddef.h>
#include "utils.h"



pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){

 if (x>width||y>height){
        return NULL ;
    } 
    else 
     return (pixelRGB *) &data[(y * width + x) * n] ;
}

