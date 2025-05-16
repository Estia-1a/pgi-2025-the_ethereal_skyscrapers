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
    printf("Hello World !\n");
}

void dimension(char *source_path){
    unsigned char* data;
    int h,w, n;
    read_image_data(source_path, &data, &w, &h, &n);
    printf("dimension: %d %d", w, h);
}



void first_pixel (char *source_path){
    unsigned char* data;
    int h,w, n;
    read_image_data(source_path, &data, &w, &h, &n);
    
    printf("first_pixel: %d, %d, %d", data[0], data[1], data[2]);
}

void tenth_pixel (char *source_path){
    unsigned char* data;
    int h,w, n;
    read_image_data(source_path, &data, &w, &h, &n);
    
    printf("first_pixel: %d, %d, %d", data[27], data[28], data[29]);
}

void second_line (char *source_path){
    unsigned char* data;
    int h,w, n;
    read_image_data(source_path, &data, &w, &h, &n);

    printf("second_line: %d, %d, %d", data[3*w], data[3*w+1], data[3*w+2]);
}

