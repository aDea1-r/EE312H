#include <stdio.h>
#include <malloc.h>
#include <cstdlib>
#include <assert.h>

int sumrec(int **matrix, int rows, int cols);
int helper(int **matrix, int r0, int rows, int c0, int cols);
int sumItr(int **matrix, int rows, int cols);
int printMatrix(int **matrix, int rows, int cols);

int main() {
    for (int i=0; i<30; i++) {
        int rows = rand() % 30;
        int cols = rand() % 30;
        int **matrix = (int**)malloc(sizeof(int*) * rows);
        for (int j=0; j<rows; j++)
            matrix[j] = (int*)malloc(sizeof(int) * cols);
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                matrix[r][c] = rand() %100;
            }
        }

        int recSum = sumrec(matrix, rows, cols);
        int itrSum = sumItr(matrix, rows, cols);
        printf("These two sums are the same: \n");
        printMatrix(matrix, rows, cols);
        printf("Sums are %d and %d\n",recSum, itrSum);
        assert(recSum == itrSum);
    }
}

int sumrec(int **matrix, int rows, int cols) {
    return helper(matrix, 0, rows, 0, cols);
}

int helper(int **matrix, int r0, int rows, int c0, int cols) {
    if (rows == 1 && cols == 1) {
        printf("counting %d at %d,%d\n", matrix[r0][c0], r0, c0);
        return matrix[r0][c0];
    }
    if (rows == 0 || cols == 0)
        return 0;

    int topLeft = helper(matrix, r0, rows/2, c0, cols/2);
    int botLeft = helper(matrix, r0 + rows/2, rows - rows/2, c0, cols/2);
    int topRight = helper(matrix, r0, rows/2, c0 + cols/2, cols - cols/2);
    int botRight = helper(matrix, r0 + rows/2, rows - rows/2, c0 + cols/2, cols - cols/2);

    printf("%d\n",topLeft + botLeft + topRight + botRight);
    return topLeft + botLeft + topRight + botRight;
}

int sumItr(int **matrix, int rows, int cols) {
    int sum = 0;
    for (int r=0; r<rows; r++) {
        for (int c=0; c<cols; c++) {
            sum += matrix[r][c];
        }
    }
    return sum;
}

int printMatrix(int **matrix, int rows, int cols) {
    for (int r=0; r<rows; r++) {
        for (int c=0; c<cols; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
    return 0;
}