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
    printf("Hello World !");
}


void dimension(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data(source_path, &data, &width, &height, &channels);

    printf("dimension: %d, %d\n", width, height);

    free_image_data(data);

}

void first_pixel (char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data (source_path, &data, &width, &height, &channels);

    int R = data[0];
    int G = data[1];
    int B = data[2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);
    

    free_image_data(data);
}

void tenth_pixel (char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data (source_path, &data, &width, &height, &channels);

    int R = data[27];
    int G = data[28];
    int B = data[29];

    printf("tenth_pixel: %d, %d, %d\n", R, G, B);
    

    free_image_data(data);
}

void second_line (char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data (source_path, &data, &width, &height, &channels);

    int R = data[3*width];
    int G = data[3*width +1];
    int B = data[3*width +2];

    printf("second_line: %d, %d, %d\n", R, G, B);
    

    free_image_data(data);
}

void print_pixel( char *filename, int x, int y ) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data (filename, &data, &width, &height, &channels);
    pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);

    free_image_data(data);
}

void color_red(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    for (int i = 0;i < width*height*channels;i += channels){
        data[i+1]=0;
        data[i+2]=0;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0) {
        free_image_data(data);
    }
    
}

void color_green(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    for (int i = 0;i < width*height*channels;i += channels){
        data[i]=0;
        data[i+2]=0;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0) {
        free_image_data(data);
    }
    
}

void color_blue(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    for (int i = 0;i < width*height*channels;i += channels){
        data[i]=0;
        data[i+1]=0;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0) {
        free_image_data(data);
    }
    
}

void max_pixel(char *filename){
    unsigned char *data = NULL;
    int width, height, channels;
    if (read_image_data (filename, &data, &width, &height, &channels)==0){
        printf("Erreur");
    }
    else{
    read_image_data (filename, &data, &width, &height, &channels);
    
    int max_r = -1, max_g = -1, max_b = -1;
    int max_x, max_y;

    for (int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channels, x, y);
            if ((pixel->R + pixel->G + pixel->B) > (max_r + max_g + max_b)){
                max_r = pixel->R;
                max_g = pixel->G;
                max_b = pixel->B;
                max_x = x ;
                max_y = y ;

                //
            }
        }
    }
       
    printf ("max_pixel (%d, %d): %d, %d, %d",max_x ,max_y, max_r, max_g, max_b);

    free_image_data(data);
}
}

