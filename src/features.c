#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !!!!!");
}
void dimension(char*source_path) {
    unsigned char* data = NULL;
    int w=0, h=0, n=0;
    read_image_data(source_path, &data, &w, &h, &n);
    printf("dimension : %d, %d\n", w, h);
}
void first_pixel(char*source_path){
    unsigned char* data = NULL;
    int w, h, n;
    
    read_image_data(source_path, &data, &w, &h, &n);
    
    unsigned char R = data[0];
    unsigned char G = data[1];
    unsigned char B = data[2];

    printf("first_pixel: %d, %d, %d", R, G, B);
}
void tenth_pixel(char*source_path){
    unsigned char* data = NULL;
    int w, h, n;
    
    read_image_data(source_path, &data, &w, &h, &n);
    
    unsigned char R = data[27];
    unsigned char G = data[28];
    unsigned char B = data[29];

    printf("tenth_pixel: %d, %d, %d", R, G, B);
}
void second_line(char*source_path){
    unsigned char* data = NULL;
    int w, h, n;
    
    read_image_data(source_path, &data, &w, &h, &n);
    
    unsigned char R = data[3*w];
    unsigned char G = data[3*w+1];
    unsigned char B = data[3*w+2];

    printf("second_line: %d, %d, %d", R, G, B);
}

void print_pixel( char *filename, int x, int y ){
    unsigned char *data = NULL;
    int w, h, n;
    read_image_data(const char *filename, unsigned char **data, int *w, int *h, int *n);
    if( (x>w) || (y>h) || !data){
        return NULL;
    }
    else{
        return (pixelRGB *) &data[n*(y*w+x)] ;
    }

}