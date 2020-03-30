#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _image {
    int rows;
    int cols;
    int **pixels;
} Image;

Image* imageAlloc(int rows, int cols);
void imageInit(Image *image);
int pixelAvg(Image *image, int row, int col);
Image* imageBlur(Image *image);
void imageFree(Image *image);

int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}

/* A. Allocate (and return) an image on the heap. Also initialize all
* attributes of the allocated image based on the given arguments.
* You do not have to initialize each pixel to any specific value. */
Image* imageAlloc(int rows, int cols) {
    Image *img = malloc(sizeof(Image));
    img->rows = rows;
    img->cols = cols;
    img->pixels = malloc(sizeof(int *) * rows);
    for (int i=0; i<rows; i++) {
        img->pixels[i] = malloc (sizeof(int) * cols);
    }
    return img;
}

/* B. Initialize the given image (which is already allocated) to
* random values. Each pixel should have value between 0 and 255
* (inclusive). Do *not* change number of columns and rows. */
void imageInit(Image *image) {
    for (int i=0; i<image->rows; i++) {
        for (int j=0; j<image->cols; j++) {
            image -> pixels[i][j] = rand() % 256;
        }
    }
}

/* C. Free everything related to the given image (and the image) from
* the heap. */
void imageFree(Image *image) {
    for (int i=0; i<image-> rows; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

/* D. Compute average value of all values in a 3x3 matrix around the
* given pixel. ’row’ is the row of the pixel and ’col’ is the column
* of the pixel. You can think of the given pixel as being in a
* center of a small matrix 3x3. Make sure that you do not go outside
* the bounaries of your image, i.e., if the pixel is at location (0,
* 0), then you should only use the following pixels: (0, 0), (0, 1),
* (1, 0), (1, 1). */
int pixelAvg(Image *image, int row, int col) {
    int sum = 0;
    int elems = 0;
    for (int i = max(0,row-1); i<=min(row+1, image->rows - 1); i++) {
        for (int j= max(0, col-1); j<=min(col+1, image-> cols -1); j++) {
            elems++;
            sum += image->pixels[i][j];
        }
    }
    return sum/elems;
}

/* E. Obtain a *new* image, which is a blur of the image given as the
* argument. A value of each pixel in the blured image is computed
* with pixelAvg function on the given image.
*
* Example input:
*
* 103 198 105 115 81
* 255 74 236 41 205
* 186 171 242 251 227
* 70 124 194 84 248
* 27 232 231 141 118
*
* Example output:
*
* 157 161 128 130 110
* 164 174 159 167 153
* 146 172 157 192 176
* 135 164 185 192 178
* 113 146 167 169 147
*
* 113 = (70 + 124 + 27 + 232) / 4
* 153 = (115 + 81 + 41 + 205 + 251 + 227) / 6 */
Image* imageBlur(Image *image) {
    Image *blur = imageAlloc(image->rows, image->cols);
    for (int i=0; i<image->rows; i++) {
        for (int j=0; j<image->cols; j++) {
            blur->pixels[i][j] = pixelAvg(image,i,j);
        }
    }
    return blur;
}

/* F. Write a program that creates one image, blurs the image, and
* frees allocated space. */
int main(void) {
    Image *image = imageAlloc(5,5);
    imageInit(image);

    Image *blur = imageBlur(image);

    imageFree(image);
    imageFree(blur);
}
