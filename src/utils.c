#include <estia-image.h>

#include "utils.h"

pixelRGB * get_pixel( unsigned char* data, const unsigned int w, const unsigned int h, const unsigned int n, const unsigned int x, const unsigned int y ){
    
    read_image_data(source_path, &data, &w, &h, &n);
    
    if ((x>w)|| (y>h) || (&data == NULL)){
        return NULL;
    }

    return (pixelRGB *) &data[(y*w+x)*n] ;
}

void print_pixel( char *filename, int x, int y ){
    
}


