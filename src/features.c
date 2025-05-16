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


void dimension(const char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    printf("Appel de dimension : %s\n", source_path);

    read_image_data(source_path, &data, &width, &height, &channels);

    printf("dimension: %d, %d\n", width, height);

    free_image_data(data);

}