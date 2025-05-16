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

    if (read_image_data (source_path, &data, &width, &height, &channels)) {
        if (channels >= 3) {
            int r = data[0];
            int g = data[1];
            int b = data[2];
            printf("first_pixel: %d, %d, %d\n", r, g, b);
        }
    }

    if (data != NULL) {
        free(data);
    }
}