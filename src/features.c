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

void helloWorld()
{
    printf("Hello World !");
}

void dimension(char *source_path)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data(source_path, &data, &width, &height, &channels);

    printf("dimension: %d, %d\n", width, height);

    free_image_data(data);
}

void first_pixel(char *source_path)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data(source_path, &data, &width, &height, &channels);

    int R = data[0];
    int G = data[1];
    int B = data[2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);

    free_image_data(data);
}

void tenth_pixel(char *source_path)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data(source_path, &data, &width, &height, &channels);

    int R = data[27];
    int G = data[28];
    int B = data[29];

    printf("tenth_pixel: %d, %d, %d\n", R, G, B);

    free_image_data(data);
}

void second_line(char *source_path)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data(source_path, &data, &width, &height, &channels);

    int R = data[3 * width];
    int G = data[3 * width + 1];
    int B = data[3 * width + 2];

    printf("second_line: %d, %d, %d\n", R, G, B);

    free_image_data(data);
}

void print_pixel(char *filename, int x, int y)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data(filename, &data, &width, &height, &channels);
    pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);

    free_image_data(data);
}

void color_red(char *filename)
{
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i = 0; i < width * height * channels; i += channels)
    {
        data[i + 1] = 0;
        data[i + 2] = 0;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0)
    {
        free_image_data(data);
    }
}

void color_green(char *filename)
{
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i = 0; i < width * height * channels; i += channels)
    {
        data[i] = 0;
        data[i + 2] = 0;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0)
    {
        free_image_data(data);
    }
}

void color_blue(char *filename)
{
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i = 0; i < width * height * channels; i += channels)
    {
        data[i] = 0;
        data[i + 1] = 0;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0)
    {
        free_image_data(data);
    }
}

void color_gray(char *filename)
{
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i = 0; i < width * height * channels; i += channels)
    {
        unsigned char value = (data[i] + data[i + 1] + data[i + 2]) / 3;
        data[i] = value;
        data[i + 1] = value;
        data[i + 2] = value;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0)
    {
        free_image_data(data);
    }
}

void color_invert(char *filename)
{
    int width, height, channels, old_R, old_G, old_B;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i = 0; i < width * height * channels; i += channels)
    {
        old_R = data[i];
        old_G = data[i + 1];
        old_B = data[i + 2];
        data[i] = 255 - old_R;
        data[i + 1] = 255 - old_G;
        data[i + 2] = 255 - old_B;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0)
    {
        free_image_data(data);
    }
}

void color_gray_luminance(char *filename)
{
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i = 0; i < width * height * channels; i += channels)
    {

        unsigned char R = data[i];
        unsigned char G = data[i + 1];
        unsigned char B = data[i + 2];

        unsigned char value = (0.21 * R + 0.72 * G + 0.07 * B);

        data[i] = value;
        data[i + 1] = value;
        data[i + 2] = value;
    }

    if (write_image_data("image_out.bmp", data, width, height) != 0)
    {
        free_image_data(data);
    }
}

void rotate_cw(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    int new_width = height;
    int new_height = width;

    unsigned char *rotate_90 = (unsigned char *)malloc(new_width * new_height * channels);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            int src_idx = (j * width + i) * channels;
            int dst_idx = (i * new_width + (new_width - 1 - j)) * channels;

            for (int c = 0; c < channels; c++) {
                rotate_90[dst_idx + c] = data[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", rotate_90, new_width, new_height) != 0) {
        free_image_data(rotate_90);
    }
    
}

void rotate_acw(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    int new_width = height;
    int new_height = width;

    unsigned char *rotate_a90 = (unsigned char *)malloc(new_width * new_height * channels);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            int src_idx = (j * width + i) * channels;
            int dst_idx = ((width - 1 - i) * new_width + j) * channels;

            for (int c = 0; c < channels; c++) {
                rotate_a90[dst_idx + c] = data[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", rotate_a90, new_width, new_height) != 0) {
        free_image_data(rotate_a90);
    }
    
}

void mirror_horizontal(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    unsigned char *rotate_mirrorh = (unsigned char *)malloc(width * height * channels);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            int src_idx = (j * width + i) * channels;
            int dst_idx = (j * width + (width - 1 - i)) * channels;

            for (int c = 0; c < channels; c++) {
                rotate_mirrorh[dst_idx + c] = data[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", rotate_mirrorh, width, height) != 0) {
        free_image_data(rotate_mirrorh);
    }
}

void mirror_vertical(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    unsigned char *rotate_mirrorv = (unsigned char *)malloc(width * height * channels);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            int src_idx = (j * width + i) * channels;
            int dst_idx = ((height - 1 - j) * width + i) * channels;

            for (int c = 0; c < channels; c++) {
                rotate_mirrorv[dst_idx + c] = data[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", rotate_mirrorv, width, height) != 0) {
        free_image_data(rotate_mirrorv);
    }
}

void mirror_total(char *filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data (filename, &data, &width, &height,  &channels);

    unsigned char *rotate_mirror = (unsigned char *)malloc(width * height * channels);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            int src_idx = (j * width + i) * channels;
            int dst_idx = ((height - 1 - j) * width + (width - 1 - i)) * channels;

            for (int c = 0; c < channels; c++) {
                rotate_mirror[dst_idx + c] = data[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", rotate_mirror, width, height) != 0) {
        free_image_data(rotate_mirror);
    }
}

void scale_crop(char *filename, int center_x, int center_y, int crop_width, int crop_height){
    int width, height, channels;
    unsigned char *data = NULL;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

    int start_x = center_x - crop_width / 2;
    int start_y = center_y - crop_height / 2;

    // Clamp pour rester dans les limites
    if (start_x < 0) start_x = 0;
    if (start_y < 0) start_y = 0;
    if (start_x + crop_width > width) crop_width = width - start_x;
    if (start_y + crop_height > height) crop_height = height - start_y;

    unsigned char *cropped = malloc(crop_width * crop_height * channels);
    if (!cropped) {
        printf("Erreur d'allocation mémoire.\n");
        free_image_data(data);
        return;
    }

    // Copier les pixels du crop
    for (int y = 0; y < crop_height; y++) {
        for (int x = 0; x < crop_width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_idx = ((start_y + y) * width + (start_x + x)) * channels + c;
                int dst_idx = (y * crop_width + x) * channels + c;
                cropped[dst_idx] = data[src_idx];
            }
        }
    }

    if (write_image_data("image_out.bmp", cropped, crop_width, crop_height) != 0) {
        free_image_data(cropped);
    }
}


void max_pixel(char *filename)
{
    unsigned char *data = NULL;
    int width, height, channels;
    if (read_image_data(filename, &data, &width, &height, &channels) == 0)
    {
        printf("Erreur");
    }
    else
    {
        read_image_data(filename, &data, &width, &height, &channels);

        int max_r = -1, max_g = -1, max_b = -1;
        int max_x, max_y;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
                if ((pixel->R + pixel->G + pixel->B) > (max_r + max_g + max_b))
                {
                    max_r = pixel->R;
                    max_g = pixel->G;
                    max_b = pixel->B;
                    max_x = x;
                    max_y = y;

                    
                }
            }
        }

        printf("max_pixel (%d, %d): %d, %d, %d", max_x, max_y, max_r, max_g, max_b);

        free_image_data(data);
    }
}

void min_pixel(char *filename){
    unsigned char *data = NULL;
    int width, height, channels;
    if (read_image_data(filename, &data, &width, &height, &channels) == 0)
    {
        printf("Erreur");
    }
    else
    {
        read_image_data(filename, &data, &width, &height, &channels);

        int min_r = 256, min_g = 256, min_b = 256;
        int min_x, min_y;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
                if ((pixel->R + pixel->G + pixel->B) < (min_r + min_g + min_b))
                {
                    min_r = pixel->R;
                    min_g = pixel->G;
                    min_b = pixel->B;
                    min_x = x;
                    min_y = y;

                    
                }
            }
        }

        printf("min_pixel (%d, %d): %d, %d, %d", min_x, min_y, min_r, min_g, min_b);

        free_image_data(data);
    }
}

void max_component(char *filename, char component)
{
    unsigned char *data = NULL;
    int width, height, channels;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0)
    {
        printf("Erreur");
        return;
    }

    int max_value = -1, max_x = -1, max_y = -1;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
            int value = 0;
        if (component == 'R') 
        {
        value = pixel->R ;
        }
        else if (component == 'G')
        { 
        value = pixel->G; 
        }
        else if (component == 'B') 
        {
        value = pixel->B; 
        }
            if (value > max_value)
            {
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }
    printf("max_component %c(%d, %d): %d\n", component, max_x, max_y, max_value);
    free_image_data(data);
}
void min_component(char *filename, char component)
{
    unsigned char *data = NULL;
    int width, height, channels;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0)
    {
        printf("Erreur");
        return;
    }

    int min_value = 255, min_x = 255, min_y = 255;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
            int value = 0;
        if (component == 'R') 
        {
        value = pixel->R ;
        }
        else if (component == 'G')
        { 
        value = pixel->G; 
        }
        else if (component == 'B') 
        {
        value = pixel->B; 
        }
            if (value < min_value)
            {
                min_value = value;
                min_x = x;
                min_y = y;
            }
        }
    }
    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
    free_image_data(data);
}
void stat_report(char *filename){
max_pixel(filename);
printf("\n\n");
min_pixel(filename);
printf("\n\n");
max_component(filename,'R');
printf("\n");
max_component(filename,'G');
printf("\n");
max_component(filename,'B');
printf("\n");
min_component(filename,'R');
printf("\n");
min_component(filename,'G');
printf("\n");
min_component(filename,'B');
}