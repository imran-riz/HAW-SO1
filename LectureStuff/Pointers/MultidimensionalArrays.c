#include <stdio.h>

int sumOfMatrix(int a[][3], int rows);
void printMatrix(int *data, int rows, int cols);
int sumOfAnyMatrix(int *data, int rows, int cols);

int main(void)
{
    int a[2][3] ={
        {20, 37, 10},
        {16, 2, 14}
    };

    printMatrix(*a, 2, 3);
    printf("Sum of matrix is %d \n\n", sumOfMatrix(a, 2));

    int b[4][4] = {
        {20, 37, 10, 90},
        {16, 2, 14, 9},
        {20, 30, 10, 0},
        {18, 2, 14, 0}
    };

    printMatrix(*b, 4, 4);
    printf("Sum of matrix is %d \n\n", sumOfAnyMatrix(b, 4, 4));

    return 0;
}

/*
 *  Can be used to find the sum of only a Nx3 matrix
 */
int sumOfMatrix(int a[][3], const int rows)       // or int sumOfMatrix(int (*a)[3], const int rows);
{
    int sum = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < 3; ++j)
            sum += a[i][j];
    }
    return sum;
}

void printMatrix(int *data, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%2d ", data[i * cols + j]);
        printf("\n");
    }
}

/*
 *  Can be used to find the sum of a NxM matrix
 */
int sumOfAnyMatrix(int *data, int rows, int cols)
{
    int sum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            sum += data[i * cols + j];
    }

    return sum;
}