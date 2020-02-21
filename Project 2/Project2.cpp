/* Project2.cpp
 * Adeel Rehman
 * EE312, Spring 2020
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
    //matrix c is a_rows x b_cols
    //b_rows = a_cols for valid multiply

    uint32_t c_row = 0, c_col=0;
    while(c_row < a_rows) {
        c_col = 0;
        while(c_col < b_cols) {
            double dotProduct = 0;
            uint32_t itemCounter = 0;
            while(itemCounter < a_cols) {
                //matrix A-row fixed at c-row
                //Matrix b-col fixed at c-col
                dotProduct += a[c_row * a_cols + itemCounter] * b[itemCounter * b_cols + c_col];
                itemCounter++;
            }
            c[c_row * b_cols + c_col] = dotProduct;
            c_col++;
        }
        c_row++;
    }

}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

    double **c = (double**)malloc(a_rows * sizeof(double));

    uint32_t c_row = 0, c_col=0;
    while(c_row < a_rows) {
        c[c_row] = (double*)malloc(b_cols* sizeof(double));
        c_col = 0;
        while(c_col < b_cols) {
            double dotProduct = 0;
            uint32_t itemCounter = 0;
            while(itemCounter < a_cols) {
                //matrix A-row fixed at c-row
                //Matrix b-col fixed at c-col
                dotProduct += a[c_row][itemCounter] * b[itemCounter][ c_col];
                itemCounter++;
            }
            c[c_row][c_col] = dotProduct;

            c_col++;
        }

        c_row++;
    }

    return c;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {

    double **b = (double**)malloc(a_cols * sizeof(double));

    uint32_t b_row = 0;
    while (b_row < a_cols) {
        b[b_row] = (double*)malloc(a_rows * sizeof(double));
        uint32_t b_col = 0;
        while(b_col < a_rows) {
            b[b_row][b_col] = a[b_col][b_row];
            b_col++;
        }
        b_row++;
    }

    return b;
}

