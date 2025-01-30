/**
 *  A program with a function to compare 2 1D arrays of int type
 */
#include <stdio.h>

int isEqualArrays(int arr1[], int arr2[], int size);

int main(void)
{
    int a[] = {6, 5, 9, 11, 20};
    int b[] = {6, 5, 9, 11, 20};
    int c[] = {6, 7, 9, 11, 20};

    printf("\nCompare arrays value by value");
    printf("\nIs a same as b?: %s", isEqualArrays(a, b, 5) ? "true" : "false");
    printf("\nIs a same as c?: %s", isEqualArrays(a, c, 5) ? "true" : "false");
    printf("\nIs b same as c?: %s", isEqualArrays(b, c, 5) ? "true" : "false");

    return 0;
}

int isEqualArrays(int arr1[], int arr2[], int size)
{
    int isEqual = 1, i = 0;

    while (isEqual && i < size)
    {
        if (arr1[i] != arr2[i])
            isEqual = 0;

        ++i;
    }

    return isEqual;
}