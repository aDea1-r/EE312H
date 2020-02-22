#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "gtest/gtest.h"
#include "MatrixMultiply.h"


void generateIdentityMatrix(double a[], const uint32_t rows, const uint32_t cols)
{
    uint32_t i, j;
    i = 0;

    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            if (i == j) { a[(i * cols) + j] = 1.0; }
            else { a[(i * cols) + j] = 0; }
            j += 1;
        }
        i += 1;
    }
}

void generateIdentityMatrixPtr(double **a, const uint32_t rows,
                               const uint32_t cols) {
    uint32_t i, j; // two loop variables, uninteresting in all respects.
    i = 0;
    while (i < rows) {
        j = 0;
        while (j < cols) {
            if (i == j) {
                a[i][j] = 1.0;
            } else {
                a[i][j] = 0;
            }
            j += 1;
        }
        i += 1;
    }
}



void perturbMatrix(double a[], const uint32_t rows, const uint32_t cols,
    uint32_t src_row[], double perturb_values[],
    const uint32_t num_perturbations)
{
    uint32_t i, k;
    uint32_t dst_row;
    i = 0;

    while (i < num_perturbations)
    {
        ASSERT_LT(src_row[i], rows);
        dst_row = 0;

        while (dst_row < rows)
        {
            if (dst_row != src_row[i])
            {
                k = 0;
                while (k < cols)
                {
                    a[(dst_row * cols) + k] += perturb_values[i] * a[(src_row[i] * cols) + k];
                    k += 1;
                }
            }
            dst_row += 1;
        }
        i += 1;
    }
}

void perturbMatrixPtr(double **a, const uint32_t rows, const uint32_t cols,
                      uint32_t src_row[], double perturb_values[],
                      const uint32_t num_perturbations) {
    uint32_t i, k;    // two loop variables, uninteresting in all respects.
    uint32_t dst_row; // index of the row being written into
    i = 0;
    while (i < num_perturbations) {
        assert(src_row[i] < rows);
        /* apply perturbation i to every row (except to itself) */
        dst_row = 0;
        while (dst_row < rows) {
            if (dst_row != src_row[i]) {
                /* take the src row, and scale it by the perturbation value
                 * and add the resulting row to the destination row */
                k = 0;
                while (k < cols) {
                    a[dst_row][k] += perturb_values[i] * a[src_row[i]][k];
                    k += 1;
                } // end for each element in a row
            }   // end if dst_row != src_row
            dst_row += 1;
        } // end for each dst_row in the matrix
        i += 1;
    } // end for each perturbation
}

/*
 * generate a matrix with random elements.
 * the matrix should be stored in array a in row-major order
 * the parameters 'rows' and 'cols' specify the size of the matrix
 */
void generateRandomMatrix(double a[], const uint32_t rows, const uint32_t cols)
{
    const int max_value = 100; // maximum scale factor to apply to a row
    const int perturbations = 7;
    uint32_t src_rows[7];
    double perturb_values[7];
    int k;

    /* randomly perturb the matrix seven times, that should scramble things pretty well */
    generateIdentityMatrix(a, rows, cols);

    k = 0;
    while (k < perturbations)
    {
        src_rows[k] = rand() % rows;
        perturb_values[k] = max_value - (rand() % (2 * max_value));
        k += 1;
    }

    perturbMatrix(a, rows, cols, src_rows, perturb_values, perturbations);
}

void generateRandomMatrixPtr(double **a, const uint32_t rows,
                             const uint32_t cols) {
    const int max_value = 100; // maximum scale factor to apply to a row
    const int perturbations = 7;
    uint32_t src_rows[7];
    double perturb_values[7];
    int k; // an unininteresting loop variable
    
    /* randomly perturb the matrix seven times, that should scramble things pretty
     * well */
    generateIdentityMatrixPtr(a, rows, cols);
    
    k = 0;
    while (k < perturbations) {
        src_rows[k] = rand() % rows;
        perturb_values[k] = max_value - (rand() % (2 * max_value));
        k += 1;
    }
    
    perturbMatrixPtr(a, rows, cols, src_rows, perturb_values, perturbations);
}



void assertEqualMatrices(double a[], double b[], const uint32_t rows, const uint32_t cols)
{
    //FAIL();
    uint32_t i, j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            double a_ij = a[(i*cols) + j];
            double b_ij = b[(i*cols) + j];
            double diff = a_ij - b_ij;
            if (diff < 0) diff = -diff;
            EXPECT_DOUBLE_EQ(a_ij, b_ij);
            j += 1;
        }
        i += 1;
    }
}
void assertEqualMatricesPtr(double **a, double **b, const uint32_t rows,
                           const uint32_t cols) {
    uint32_t i, j; // two loop variables, uninteresting in all respects.
    
    i = 0;
    while (i < rows) {
        j = 0;
        while (j < cols) {
            EXPECT_DOUBLE_EQ(a[i][j], b[i][j]);
            double difference = fabs(a[i][j] - b[i][j]);
            if (difference > 1.0e-6) {
                fprintf(stderr, "Sorry, matrices do not match, first difference at row "
                        "%d and col %d\n",
                        i, j);
            }
            j += 1;
        }
        i += 1;
    }
}
void copyMatrix(double dest[], double src[], const uint32_t rows, const uint32_t cols)
{
    uint32_t i = 0;
    while (i < rows)
    {
        uint32_t j = 0;
        while (j < cols)
        {
            dest[(i * cols) + j] = src[(i * cols) + j];
            j += 1;
        }
        i += 1;
    }
}

void copyMatrixPtr(double **dest, double **src, const uint32_t rows,
                   const uint32_t cols) {
    uint32_t i = 0;
    while (i < rows) {
        uint32_t j = 0;
        while (j < cols) {
            dest[i][j] = src[i][j];
            j += 1;
        }
        i += 1;
    }
}

void printMatrix(double a[], const uint32_t rows, const uint32_t cols)
{
    uint32_t i = 0;
    while (i < rows)
    {
        uint32_t j = 0;
        while (j < cols)
        {
            printf("%g, ", a[(i * cols) + j]);
            j += 1;
        }
        printf("\n");
        i += 1;
    }
}

void printMatrixPtr(double **a, const uint32_t rows, const uint32_t cols) {
    uint32_t i = 0;
    while (i < rows) {
        uint32_t j = 0;
        while (j < cols) {
            printf("%g, ", a[i][j]); // %g is just like %f, only better
            j += 1;
        }
        printf("\n");
        i += 1;
    }
}

void memoryRelease(double** ptr, int length) {
    for(int i =0; i < length ; i++) {
        free(*(ptr + i));
    }
    free(ptr);
}
