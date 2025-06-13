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

void print_pixel(char* source_path, int x, int y){
    unsigned char* data = NULL;
    int w, h, n;

    read_image_data(source_path, &data, &w, &h, &n);
    pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
    printf("print_pixel (%d %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
}

void max_pixel(char*source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    int max_x = 0;
    int max_y = 0;
    int sum = 0;
    int sum_maxi=0;

    read_image_data(source_path, &data, &w, &h, &n);
    pixelRGB * max_pixel = NULL;
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            sum = pixel->R + pixel->G + pixel->B;
            if(sum>sum_maxi){
                sum_maxi = sum;
                max_x = x;
                max_y = y;
                max_pixel=pixel;
            }
        }
    } 
    printf("max_pixel (%d %d): %d, %d, %d\n", max_x, max_y, max_pixel->R, max_pixel->G, max_pixel->B);
}

void min_pixel(char*source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    int min_x = 0;
    int min_y = 0;
    int sum;

    read_image_data(source_path, &data, &w, &h, &n);
    pixelRGB * min_pixel = NULL;
    pixelRGB * first_pixel = get_pixel(data, w, h, n, 0, 0);
    int sum_mini = first_pixel->R + first_pixel->G + first_pixel->B;
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            sum = pixel->R + pixel->G + pixel->B;
            if(sum<sum_mini){
                sum_mini = sum;
                min_x = x;
                min_y = y;
                min_pixel=pixel;
            }
        }
    } 
    printf("min_pixel (%d %d): %d, %d, %d\n", min_x, min_y, min_pixel->R, min_pixel->G, min_pixel->B);
}

int max_component(char *source_path, char color_pixel){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    int max_x = 0;
    int max_y = 0;
    int color_pixel_value=0;
    int color_pixel_max=0;
    
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            if (color_pixel=='R'){
                color_pixel_value=pixel->R;
            }
            else if (color_pixel=='G'){
                color_pixel_value=pixel->G;
            }
            else if (color_pixel=='B'){
                color_pixel_value=pixel->B;
            }
            if(color_pixel_value>color_pixel_max){
                color_pixel_max = color_pixel_value;
                max_x = x;
                max_y = y;
            }
        }
    } 
    printf("max_component %c (%d %d): %d\n", color_pixel, max_x, max_y, color_pixel_max);
    return(max_x, max_y, color_pixel_max);
}

void min_component(char *source_path, char color_pixel){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    int max_x = 0;
    int max_y = 0;
    int color_pixel_value;
    int color_pixel_min ;
    read_image_data(source_path, &data, &w, &h, &n);
    pixelRGB * first_pixel = get_pixel(data, w, h, n, 0,0);
    
    if (color_pixel=='R'){
        color_pixel_min = first_pixel->R;
    }
    else if (color_pixel=='G'){
        color_pixel_min=first_pixel->G;
    }
    else if (color_pixel=='B'){
            color_pixel_min=first_pixel->B;
    }
    
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            
            
            if (color_pixel=='R'){
                color_pixel_value=pixel->R;
            }
            else if (color_pixel=='G'){
                color_pixel_value=pixel->G;
            }
            else if (color_pixel=='B'){
                color_pixel_value=pixel->B;
            }
            if(color_pixel_value<color_pixel_min){
                color_pixel_min = color_pixel_value;
                max_x = x;
                max_y = y;
            }
        }
    } 
    printf("min_component %c (%d %d): %d\n", color_pixel, max_x, max_y, color_pixel_min);
}

void stat_report(char * source_path){
    FILE * fichier = fopen("report.txt","w");

    max_pixel(source_path);
    fprintf(fichier,"\n");
    min_pixel(source_path);
    fprintf(fichier,"\n");
    a, b, c = max_component(&source_path, 'R');
    fprintf(fichier,"max_component R (%d %d): %d\n", a, b, c);
    max_component(source_path, 'G');
    fprintf(fichier,"\n");
    max_component(source_path, 'B');
    fprintf(fichier,"\n");
    min_component(source_path,'R');
    fprintf(fichier,"\n");
    min_component(source_path,'G');
    fprintf(fichier,"\n");
    min_component(source_path,'B');
    fprintf(fichier,"\n");

    fclose(fichier);
}

