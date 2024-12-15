#include <stdio.h>

void reverseArr(int[], int);
void printArr(int[][3], int, int);
void transposeMatrix(int[][3], int, int);

int main(void)
{
    const int ROWS = 3, COLS = 3;

    int matrix[ROWS][COLS] = {
    {10, 12, 14},
    {90, 78, 32},
    {100, 67, 44}
    };

    printArr(matrix, ROWS, COLS);

    transposeMatrix(matrix, ROWS, COLS);

    printf("\n");
    printArr(matrix, ROWS, COLS);
}

void reverseArr(int arr[], int size)
{
    printf("\n[");

    for (int i = size - 1; i >= 0; --i)
    {
        printf("%d%s", arr[i], i == 0 ? "]" : ", ");
    }
}

void printArr(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        printf("\n[");
        for (int j = 0; j < cols; ++j)
        {
            printf("%3d%s", arr[i][j], j == rows-1 ? "]" : ", ");
        }
    }
}

// can only be called for a square matrices
void transposeMatrix(int matrix[][3], int rows, int cols)
{
    int temp;

    for (int i = 0; i < rows; ++i)
    {
        // start with col index = current row index, so that we do not adjust the lower triangle and undo the
        // transposition
        for (int j = i; j < cols; ++j)
        {
            temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}