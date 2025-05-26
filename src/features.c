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

    printf("Appel de  la dimension : %s\n", source_path);

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

    printf("secon_line: %d, %d, %d\n", R, G, B);
    

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
void stat_report(){
<<<<<<< HEAD
    read_image_data (source_path, &data, &width, &height, &channels);

    int R = data[3*width];
    int G = data[3*width +1];
    int B = data[3*width +2];

    printf("secon_line: %d, %d, %d\n", R, G, B);
=======
    read_image_data (filename, &data, &width, &height, &channels);
    pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);

    free_image_data(data);
>>>>>>> 6732d13eb1fdbee07bab98ad74d5dbba236979ec
}