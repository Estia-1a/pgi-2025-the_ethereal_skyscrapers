void max_pixel(char *filename){
 
    unsigned char* data;
    int width, height, channel_count;
 
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
 
        int x, y, i, max = -1 , R,G,B;
        y = 0;
        x = 0;
     
 
        for (i =0;i <= height*width;i++){
                       
            if ((data[i*3] + data[i*3+1] + data[i*3+2])> max){
                max = (data[i*3] + data[i*3+1] + data[i*3+2]);
                y = i / width;
                x = i % width;
                R = data[i*3];
                G = data[i*3+1];
                B = data[i*3+2];
            }
           
        }
        printf("max_pixel (%d, %d): %d, %d, %d\n", x, y, R, G, B);
        free_image_data(data);
 
    }
}
 
 
void min_pixel(char *filename){
 
    unsigned char* data;
    int width, height, channel_count;
 
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
 
        int x, y, i, R,G,B;
        int min = 255 * 3 + 1;
        for (i =0;i < height*width;i++){
           
            if ((data[i*3] + data[i*3+1] + data[i*3+2])< min){
                min = (data[i*3] + data[i*3+1] + data[i*3+2]);
                y = i / width;
                x = i % width;
                R = data[i*3];
                G = data[i*3+1];
                B = data[i*3+2];
            }
           
        }
        printf("min_pixel (%d, %d): %d, %d, %d\n", x, y, R, G, B);
        free_image_data(data);
 
    }
}