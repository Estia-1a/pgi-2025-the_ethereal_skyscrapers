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
    printf("Hello Word !! ");
}
void dimension(char *source_path){
    unsigned char* data;
    int w, h, n;
    read_image_data(source_path, &data, &w, &h, &n);
    printf("dimension : %d, %d\n", w, h);
}
void first_pixel (char *source_path){
    unsigned char* data = NULL;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];

    printf("first_pixel : %d, %d, %d\n", r, g, b);

}

void tenth_pixel (char *source_path){
    unsigned char* data = NULL;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    unsigned char r = data[27];
    unsigned char g = data[28];
    unsigned char b = data[29];

    printf("tenth_pixel : %d, %d, %d\n", r, g, b);

}

void second_line (char *source_path){
    unsigned char* data = NULL;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    unsigned char r = data[3*width];
    unsigned char g = data[3*width+1];
    unsigned char b = data[3*width+2];

    printf("second_line : %d, %d, %d\n", r, g, b);

}