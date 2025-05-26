#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

 pixelRGB * get_pixel( unsigned char* data, const unsigned int w, const unsigned int h, const unsigned int n, const unsigned int x, const unsigned int y ){
    read_image_data(source_path, &data, &w, &h, &n);

    if( (x>w) || (y>h) || (!data)){
        return NULL;
    }
    else{
        return (pixelRGB *) &data[n*(y*w+x)] ;
    }

 }

