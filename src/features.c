#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
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
void dimension(char* source_path) {
    unsigned char* data = NULL;
    int w=0, h=0, n=0;
    read_image_data(source_path, &data, &w, &h, &n);
    printf("dimension : %d, %d\n", w, h);
}
void first_pixel(char* source_path){
    unsigned char* data = NULL;
    int w, h, n;
    
    read_image_data(source_path, &data, &w, &h, &n);
    
    unsigned char R = data[0];
    unsigned char G = data[1];
    unsigned char B = data[2];

    printf("first_pixel: %d, %d, %d", R, G, B);
}
void tenth_pixel(char* source_path){
    unsigned char* data = NULL;
    int w, h, n;
    
    read_image_data(source_path, &data, &w, &h, &n);
    
    unsigned char R = data[27];
    unsigned char G = data[28];
    unsigned char B = data[29];

    printf("tenth_pixel: %d, %d, %d", R, G, B);
}
void second_line(char* source_path){
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
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
}

char* max_pixel(char* source_path){
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
    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel->R, max_pixel->G, max_pixel->B);
    char* result=malloc(100);
    sprintf(result,"max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel->R, max_pixel->G, max_pixel->B);
    return result;
    
}

char* min_pixel(char* source_path){
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
    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel->R, min_pixel->G, min_pixel->B);
    char* result=malloc(100);
    sprintf(result,"min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel->R, min_pixel->G, min_pixel->B);
    return result;
}

char* max_component(char *source_path, char color_pixel){
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
    printf("max_component %c (%d, %d): %d\n", color_pixel, max_x, max_y, color_pixel_max);
    char* result=malloc(100);
    sprintf(result,"max_component %c (%d, %d): %d\n", color_pixel, max_x, max_y, color_pixel_max);
    return result;
}

char* min_component(char *source_path, char color_pixel){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    int min_x = 0;
    int min_y = 0;
    int color_pixel_value=0;

    read_image_data(source_path, &data, &w, &h, &n);

    pixelRGB * first_pixel = get_pixel(data, w, h, n, 0, 0);
    int color_pixel_min;
    if (color_pixel=='R'){
        color_pixel_min= first_pixel->R;
    }
    else if (color_pixel=='G'){
        color_pixel_min= first_pixel->G;
    }
    else if (color_pixel=='B'){
        color_pixel_min= first_pixel->B;
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
                min_x = x;
                min_y = y;
            }
        }
    } 
    printf("min_component %c (%d, %d): %d\n", color_pixel, min_x, min_y, color_pixel_min);
    char* result=malloc(100);
    sprintf(result,"min_component %c (%d, %d): %d\n", color_pixel, min_x, min_y, color_pixel_min);
    return result;
}

void stat_report(char *source_path){
    FILE *report = fopen("file.txt", "w");
    
    char* maxpixel = max_pixel(source_path);
    char* minpixel = min_pixel(source_path);
    char* max_componentR = max_component(source_path,'R');
    char* max_componentG = max_component(source_path,'G');
    char* max_componentB = max_component(source_path,'B');
    char* min_componentR = min_component(source_path,'R');
    char* min_componentG = min_component(source_path,'G');
    char* min_componentB = min_component(source_path,'B');
    fprintf(report,"%s",maxpixel);
    fprintf(report,"%s",minpixel);
    fprintf(report,"%s",max_componentR);
    fprintf(report,"%s",max_componentG);
    fprintf(report,"%s",max_componentB);
    fprintf(report,"%s",min_componentR);
    fprintf(report,"%s",min_componentG);
    fprintf(report,"%s",min_componentB);
    fclose(report);
}

void color_green(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            pixel->R=0;
            pixel->B=0;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void color_red(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            pixel->G=0;
            pixel->B=0;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void color_blue(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            pixel->R=0;
            pixel->G=0;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void color_gray(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            unsigned char value = (pixel->R + pixel->G + pixel->B) / 3;
            pixel->R=value;
            pixel->G=value;
            pixel->B=value;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void color_invert(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            pixel->R=255-pixel->R;
            pixel->G=255-pixel->G;
            pixel->B=255-pixel->B;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void color_gray_luminance(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            unsigned char value = 0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B;
            pixel->R=value;
            pixel->G=value;
            pixel->B=value;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void rotate_cw(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    unsigned char* rotate_data = malloc(w * h * n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB* current_pixel = get_pixel(data, w, h, n, x, y);
            int nouveau_x = h - y;
            int nouveau_y = x;
            pixelRGB* rotate_pixel = get_pixel(rotate_data, h, w, n, nouveau_x, nouveau_y);
            rotate_pixel->R = current_pixel->R;
            rotate_pixel->G = current_pixel->G;
            rotate_pixel->B = current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", rotate_data, h, w);
}

void mirror_horizontal(char *source_path){
    unsigned char* data = NULL;
    int w, h, n,  x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    unsigned char* mirror_h_data = malloc(w * h * n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB* current_pixel = get_pixel(data, w, h, n, x, y);
            int nouveau_x = w - 1 - x;
            int nouveau_y = y;
            pixelRGB* mirror_h_pixel = get_pixel(mirror_h_data, w, h, n, nouveau_x, nouveau_y);
            mirror_h_pixel->R = current_pixel->R;
            mirror_h_pixel->G = current_pixel->G;
            mirror_h_pixel->B = current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", mirror_h_data, w, h);
}

void rotate_acw(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    
    unsigned char* rotate_a_data = malloc(w * h * n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB* current_pixel = get_pixel(data, w, h, n, x, y);
            int nouveau_x = y;
            int nouveau_y = w-1-x;
            pixelRGB* rotate_a_pixel = get_pixel(rotate_a_data, h, w, n, nouveau_x, nouveau_y);
            rotate_a_pixel->R = current_pixel->R;
            rotate_a_pixel->G = current_pixel->G;
            rotate_a_pixel->B = current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", rotate_a_data, h, w);
}

void mirror_vertical(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    unsigned char* mirror_v_data = malloc(w * h * n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB* current_pixel = get_pixel(data, w, h, n, x, y);
            int nouveau_x =x;
            int nouveau_y = h-1-y;
            pixelRGB* mirror_v_pixel = get_pixel(mirror_v_data, w, h, n, nouveau_x, nouveau_y);
            mirror_v_pixel->R = current_pixel->R;
            mirror_v_pixel->G = current_pixel->G;
            mirror_v_pixel->B = current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", mirror_v_data, w, h);
}

void mirror_total(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    unsigned char* mirror_t_data = malloc(w * h * n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB* current_pixel = get_pixel(data, w, h, n, x, y);
            int nouveau_x = w-x;
            int nouveau_y = h-1-y;
            pixelRGB* mirror_t_pixel = get_pixel(mirror_t_data, w, h, n, nouveau_x, nouveau_y);
            mirror_t_pixel->R = current_pixel->R;
            mirror_t_pixel->G = current_pixel->G;
            mirror_t_pixel->B = current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", mirror_t_data, w, h);
}

void scale_crop(char *source_path, int center_x, int center_y, int width, int height) {
    unsigned char *data = NULL;
    int original_width, original_height, n;

    read_image_data(source_path, &data, &original_width, &original_height, &n);

    int start_x = center_x - width / 2;
    int start_y = center_y - height / 2;

    unsigned char *cropped_data = malloc(width * height * n);
    if (!cropped_data) {
        free(data);
        return;
    }


    for (int y = 0; y < height; y++) {
        int src_y = start_y + y;
        if (src_y < 0 || src_y >= original_height) continue;

        for (int x = 0; x < width; x++) {
            int src_x = start_x + x;
            if (src_x < 0 || src_x >= original_width) continue;

            pixelRGB *src_pixel = get_pixel(data, original_width, original_height, n, src_x, src_y);
            pixelRGB *dst_pixel = get_pixel(cropped_data, width, height, n, x, y);

            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }

    write_image_data("image_out.bmp", cropped_data, width, height);

}

void color_desaturate(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y; 
    read_image_data(source_path, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){       
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            unsigned char val_min = pixel->R;
            if(val_min>pixel->G){
                val_min = pixel->G;
            }
            if(val_min>pixel->B){
                val_min = pixel->B;
            }

            unsigned char val_max = pixel->R;
            if(val_max<pixel->G){
                val_max = pixel->G;
            }
            if(val_max<pixel->B){
                val_max = pixel->B;
            }

            unsigned char value =(val_min+val_max)/2 ;
            pixel->R=value;
            pixel->G=value;
            pixel->B=value;
        }

    }
    write_image_data("image_out.bmp", data, w, h);
}


void scale_nearest(char *source_path, float val) {
    unsigned char* data = NULL;
    int w, h, n;

    read_image_data(source_path, &data, &w, &h, &n); 

    int new_w = (int)(w * val);
    int new_h = (int)(h * val);

    unsigned char* scaled_data = malloc(new_w * new_h * n);
    if (!scaled_data) {
        free(data);
        return;
    }

    float x_ratio = (float)w / new_w;
    float y_ratio = (float)h / new_h;

    for (int y = 0; y < new_h; y++) {
        for (int x = 0; x < new_w; x++) {
            int nearest_x = (int)(x * x_ratio);
            int nearest_y = (int)(y * y_ratio);

            pixelRGB* src_pixel = get_pixel(data, w, h, n, nearest_x, nearest_y);
            pixelRGB* dst_pixel = get_pixel(scaled_data, new_w, new_h, n, x, y);

            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }

    write_image_data("image_out.bmp", scaled_data, new_w, new_h);

}

void scale_bilinear(char *source_path, float val){
    unsigned char* data=NULL;
    int w, h, n, x, y;

    read_image_data(source_path, &data, &w, &h, &n);

    int new_w = (int)(w * val);
    int new_h = (int)(h * val);

    unsigned char* scaled_data = malloc(new_w * new_h * n);
    if (!scaled_data) {
        free(data);
        return;
    }

    float x_ratio = (float)(w - 1) / new_w;
    float y_ratio = (float)(h-1) / new_h;

    float gx, gy, dx, dy;
    int x1, x2, y1, y2;

    for (y = 0;y < new_h; y++){
        for (x=0; x<new_w; x++){

            gx= x *x_ratio;
            gy = y* y_ratio;

            x1 = (int)gx;
            y1 = (int)gy;
            x2 = x1 + 1;
            y2 = y1 + 1;

            dx = gx - x1;
            dy = gy - y1;

            if (x2 >= w) x2 = w - 1;
            if(y2 >= h) y2 = h -1;

            pixelRGB* A= get_pixel(data, w, h, n, x1, y1);
            pixelRGB* E= get_pixel(data, w, h, n, x2, y1);
            pixelRGB* C= get_pixel(data, w, h, n, x1, y2);
            pixelRGB* D= get_pixel(data, w, h, n, x2, y2);

            pixelRGB* dst =get_pixel(scaled_data, new_w, new_h, n, x, y);

            dst->R = (unsigned char)(A->R *(1-dx)*(1-dy)+E->R * dx*(1-dy)+C->R*(1-dx)*dy+D->R*dx*dy);
            dst->G = (unsigned char)(A->G *(1-dx)*(1-dy)+E->G * dx*(1-dy)+C->G*(1-dx)*dy+D->G*dx*dy);
            dst->B = (unsigned char)(A->B *(1-dx)*(1-dy)+E->B * dx*(1-dy)+C->B*(1-dx)*dy+D->B*dx*dy);

            write_image_data("image_out.bmp", scaled_data, new_w, new_h);
        }
    }

}