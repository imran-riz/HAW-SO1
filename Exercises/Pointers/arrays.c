#include <stdio.h>
#include <math.h>

void rotate2DVector(double *x, double alpha);
void transposeMatrix(int *matrix, int size);
void printArray(int *arr, int rows, int cols);

int main(void)
{
    double vector[] = {2, 3};
    printf("[%.1f %.1f]^T \n", vector[0], vector[1]);

    rotate2DVector(vector, 90.0);
    printf("[%.1f %.1f]^T \n", vector[0], vector[1]);

    const int SIZE = 4;
    int matrixA[SIZE][SIZE] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };

    printf("\n\nMatrix A\n");
    printArray(matrixA, SIZE, SIZE);

    transposeMatrix(matrixA, SIZE);
    printf("\nMatrix A transposed\n");
    printArray(matrixA, SIZE, SIZE);

    return 0;
}

/*
 *  In the 2D plane, a vector x = [a b] can be rotated by an angle alpha (in deg) by the following equation:
 *      A.x =  [cos(alpha)  -sin(alpha)] . [a]
 *             [sin(alpha)  cos(alpha) ]   [b]
 */
void rotate2DVector(double *x, double alphaDeg)
{
    double alpha = alphaDeg * (M_PI / 180.0);
    double a = *x, b = *(x + 1);

    *x = a * cos(alpha) - b * sin(alpha);
    *(x + 1) = a * sin(alpha) + b * cos(alpha);
}

/*
 *  A function that gets a NxN matrix and transposes it
 */
void transposeMatrix(int *matrix, int size)
{
    int temp = 0;

    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            // temporarily store matrix[i][j]
            temp = matrix[i * size + j];
            matrix[i * size + j] = matrix[j * size + i];
            matrix[j * size + i] = temp;
        }
    }
}


void printArray(int *arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d | ", arr[i * cols + j]);
        }
        printf("\n");
    }
}