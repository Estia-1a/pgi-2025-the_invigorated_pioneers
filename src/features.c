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

void max_pixel(char *filename, int x , int y){
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;
    read_image_data (filename, &data, &width, &height, &channels);
    int i = 0;
    int R = data[0];
    int G = data[1];
    int B = data[2];
    int b = 0 ;
    int a = 0 ; 
    int M = 0;
    int N = 0 ;
    int O = 0 ;

        while (i <(height * width) ){
            R= data [3*i];
            G = data[3*i + 1];
            B = data [3*i + 2];

            a=R+G+B;

            i++;
            if (a>b){
                b = a ; 
                M = R ;
               N = G ;
               O = B ;

            }
           
        }
         printf ("max_pixel(%d, %d): %d, %d, %d",x ,y, M, N, O);
free_image_data(data);
}

