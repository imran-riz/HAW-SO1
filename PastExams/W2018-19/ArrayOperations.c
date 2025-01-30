/**
 *  21.2 Array Operations
 */
#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size);
int* cloneArray(const int array[], int size);
void swap(int *a, int *b);
void invertArray(int array[], int size);

int main(void)
{
    // declare and initialise variables
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof numbers / sizeof(int);
    int *clone = cloneArray(numbers, size);

    // display the original array and its clone
    printf("Input   : ");
    printArray(numbers, size);
    printf("\nClone   : ");
    printArray(clone, size);

    // call the invert function and display the updated array
    invertArray(numbers, size);
    printf("\nInverted: ");
    printArray(numbers, size);

    // free dynamically allocated memory to avoid memory leaks
    free(clone);

    return 0;
}

void printArray(int array[], int size)
{
    printf("[");
    for (int i = 0; i < size; ++i)
    {
        printf("%d", array[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]");
}

int* cloneArray(const int array[], int size)
{
    // dynamically allocate memory for an array of size elements and initialise all element values to 0
    int *clone = (int *) calloc(size, sizeof(int));

    // in the event that the computer fails to allocate memory,
    // log an error message and exit the program immediately
    if (clone == NULL)
    {
        printf("\nFailed to allocate memory to clone array! Exiting program.");
        exit(EXIT_FAILURE);
    }

    // otherwise, copy the values from the passed array into the clone one element at a time
    for (int i = 0; i < size; ++i)
        clone[i] = array[i];

    return clone;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void invertArray(int array[], int size)
{
    for (int i = 0; i < size / 2; ++i)
        swap(&(array[i]), &array[size - i - 1]);
}