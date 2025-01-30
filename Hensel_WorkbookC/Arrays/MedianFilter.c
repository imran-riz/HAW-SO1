#include <stdio.h>

void getMedian(int arr[3]);
void displayArr(int arr[], int size);

int main(void)
{
    int arr[15] = {95, 91, 211, 97, 89, 96, 94, 3, 91, 94, 92, 96, 93, 97, 94};
    int median[15] = {};

    median[0] = arr[0];
    median[14] = arr[14];
    printf("\nMedian: ");
    displayArr(median, 15);

    for (int k = 1; k < 14; ++k)
    {
        int tempArr[3] = {arr[k-1], arr[k], arr[k+1]};
        getMedian(tempArr);
        median[k] = tempArr[1];

        // printf("\nMedian after k=%d: ", k);
        // displayArr(median, 15);
    }

    printf("\n\nOriginal: ");
    displayArr(arr, 15);
    printf("\nMedian: ");
    displayArr(median, 15);

    return 0;
}

/*
 * Uses a bubble sort algorithm to sort an array of 3 numbers in ascending order
 */
void getMedian(int arr[3])
{
    int j = 2;      // the upper bound should be the index of the array's last value
    int temp;

    printf("\n\nArray to sort: [");
    displayArr(arr, 3);
    printf("]");

    while (j > 0) {
        for (int i = 0; i < j; ++i)
        {
            if (arr[i] > arr[i+1])
            {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
            printf("\nWhen i = %d, j = %d: [", i, j);
            displayArr(arr, 3);
            printf("]");
        }

        --j;        // reduce the upper bound as the upper value is now the largest
    }
}

void displayArr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d%c ", arr[i], i != size-1 ? ',' : ' ');
    }
}