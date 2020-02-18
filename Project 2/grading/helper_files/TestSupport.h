#include <stdint.h>
#include <stdio.h>
#include "MatrixMultiply.h"


void generateIdentityMatrix(double a[], const uint32_t rows,
                            const uint32_t cols);

void generateIdentityMatrixPtr(double **a, const uint32_t rows,
                               const uint32_t cols);

void perturbMatrix(double a[], const uint32_t rows, const uint32_t cols,
                   uint32_t src_row[], double perturb_values[],
                   const uint32_t num_perturbations);

void perturbMatrixPtr(double **a, const uint32_t rows, const uint32_t cols,
                      uint32_t src_row[], double perturb_values[],
                      const uint32_t num_perturbations);

void generateRandomMatrix(double a[], const uint32_t rows,
                          const uint32_t cols);

void generateRandomMatrixPtr(double** a, const uint32_t rows,
                             const uint32_t cols);


void assertEqualMatrices(double a[], double b[], const uint32_t rows,
                        const uint32_t cols);

void assertEqualMatricesPtr(double** a, double** b, const uint32_t rows,
                           const uint32_t cols);

void copyMatrix(double dest[], double src[], const uint32_t rows,
                const uint32_t cols);

void copyMatrixPtr(double** dest, double** src, const uint32_t rows,
                   const uint32_t cols);

void printMatrix(double a[], const uint32_t rows, const uint32_t cols);

void printMatrixPtr(double** a, const uint32_t rows, const uint32_t cols);

void memoryRelease(double** ptr, int length);

