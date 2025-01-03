#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *array, int size);
void printStrings(char *arr[], int size);
void findMinMax(const int *arr, int size, int *min, int *max);
void countRandomNums();
double getAverageOfHistogram(const int arr[], int size);

int main()
{
    int a[] = {11, 21, 10, 12, 14, 16, 18, 2, 20};             // an array name is the address of its first element
    int size = 0;
    printf("a == &a[0]? %d \n", a == &a[0]);
    printf(" *(a + 1) = %d \n", *(a + 1));
    printf(" *(a + 5) = %d \n", *(a + 5));
    size = sizeof a / sizeof a[0];
    printArray(a, size);


    printf("\n\nArray of strings");
    char *arr[] = {"Hello", "World", "C Programming"};
    size = sizeof arr / sizeof arr[0];
    printStrings(arr, size);


    printf("\n\nMinimum and maximum");
    int min, max;
    size = sizeof a / sizeof a[0];
    findMinMax(a, size, &min, &max);
    printf("\nMin = %d, Max = %d", min, max);

    printf("\n\nRandom numbers");
    countRandomNums();

    return 0;
}

/*
 *  Here *array is a pointer to an int array
 */
void printArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d, ", array[i]);

    printf("\n");
}

/*
 *  Here *arr[] is an array of pointers to strings. Meaning that each element in arr is a pointer. And
 *  those pointers point to the first element of char arrays (i.e. strings).
 */
void printStrings(char *arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}


void findMinMax(const int *arr, int size, int *min, int *max)
{
    *min = *max = arr[0];

    // straight-forward and inefficient approach
    // for (int i = 1; i < size; ++i)
    // {
    //     *max = arr[i] > *max ? arr[i]: *max;
    //     *min = arr[i] < *min ? arr[i]: *min;
    // }

    // works by comparing pairs, reduced by ~25%
    for (int i = size % 2; i < size - 1; i += 2)      // if the size is even start from 0, if odd start from 1
    {
        if (arr[i] < arr[i + 1])
        {
            if (arr[i] < *min) *min = arr[i];
            if (arr[i + 1] > *max) *max = arr[i + 1];
        }
        else
        {
            if (arr[i] > *max) *max = arr[i];
            if (arr[i + 1] < *min) *min = arr[i + 1];
        }
    }
}


/*
 *  Generates random numbers in the range 0 to 10
 *  An array count will store the number of occurrences of each number in the corresponding element
 *      Eg: count[9] = 19 means that the number 9 occurred 19 times
 *
 *  Prints out the average value of the generated numbers
 */
void countRandomNums()
{
    const int SIZE = 11;
    const int NUMS_GENERATED = 11000;

    int count[SIZE] = {0};        // initialise the array with 0s in all 11 elements
    double average;

    // initialise the random number generator
    srand((unsigned) time(NULL));

    // fill the array with count of each random number generated and then find the average
    for (int i = 0; i < NUMS_GENERATED; ++i)
        count[rand() % SIZE]++;
    average = getAverageOfHistogram(count, SIZE);

    // print the array
    printf("Histogram of numbers: \n");
    for (int i = 0; i < SIZE; ++i)
        printf("%2d: %5d \n", i, count[i]);

    printf("Average = %.2f\n", average);

}

double getAverageOfHistogram(const int arr[], int size)        // could also use: int *arr
{
    int numCount = 0, sum = 0;

    for (int i = 0; i < size; ++i)
    {
        numCount += arr[i];
        sum += (i * arr[i]);
    }

    return (double) sum / numCount ;
}