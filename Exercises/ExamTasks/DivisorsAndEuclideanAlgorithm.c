/**
 *  Solution to exam task 20.3 - Divisors and Euclidean algorithm
 */
#include <stdio.h>
#include <stdlib.h>

void sortDescending(int *a, int *b);
int greatestCommonDivisor(int m, int n);
int getNumberOfDivisors(int m);
int *newArrayOfDivisors(int m, int size);
void clearKeyboardBuffer(void);

int main(void)
{
    int num1, num2, ret, divisorCount;
    int *divisorsArr;

    printf("Enter two positive integer numbers (comma-separated): ");
    do
    {
        ret = scanf("%d, %d", &num1, &num2);
        clearKeyboardBuffer();

        if (ret != 2 || num1 < 1 || num2 < 1)
            printf("Invalid input. Retry: ");
        else
            break;
    }
    while (1);

    divisorCount = getNumberOfDivisors(num1);
    divisorsArr = newArrayOfDivisors(num1, divisorCount);
    printf("Divisors of %d: ", num1);
    for (int i = 0; i < divisorCount; ++i)
        printf("%d ", divisorsArr[i]);

    // To test, you could uncomment the next block of code to see the divisors of num2
    /*
    divisorCount = getNumberOfDivisors(num2);
    divisorsArr = newArrayOfDivisors(num2, divisorCount);
    printf("\nDivisors of %d: ", num2);
    for (int i = 0; i < divisorCount; ++i)
        printf("%d ", divisorsArr[i]);
    */

    printf("\nGreatest common divisor: gcd(%d, %d) = %d", num1, num2, greatestCommonDivisor(num1, num2));

    // free dynamically allocated memory
    free(divisorsArr);

    printf("\n\nPress enter to quit...");
    getchar();

    return 0;
}

void sortDescending(int *a, int *b)
{
    int temp = 0;

    if (*a < *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

/*
 *  Takes 2 integers and returns the gcd of them based on the algorithm
 *  given in the exam task.
 */
int greatestCommonDivisor(int m, int n)
{
    int r = 0;
    do
    {
        sortDescending(&m , &n);
        r = m % n;

        // NOTE: the following 'if' condition will ALWAYS be reached eventually.
        // So, there's no need to attach and 'else' block following it
        // neither is it needed to add a 'return' statement at the end of the function body.
        if (r == 0) return n;

        m = n;
        n = r;
    }
    while (1);
}

/*
 *  Takes an integer m, counts and returns the number of divisors it has.
 */
int getNumberOfDivisors(int m)
{
    int count = 0;
    for (int i = 1; i < m; ++i)
        if (m % i == 0) count++;

    return count;
}

int *newArrayOfDivisors(int m, int size)
{
    int *array = (int*) malloc(size * sizeof(int));
    int index = 0;

    for (int i = 1; i < m; ++i)
    {
        if (m % i == 0)
        {
            array[index] = i;
            index++;
        }
    }

    return array;
}

void clearKeyboardBuffer(void)
{
    while (getchar() != '\n');
}