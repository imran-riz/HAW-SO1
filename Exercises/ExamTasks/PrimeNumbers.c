#include <stdio.h>

typedef enum
{
    FALSE = 0,
    TRUE = 1,
} boolean;

boolean isEven(int num);
boolean isPrimeNumber(int k);
void clearKeyboardBuffer(void);

int main(void)
{
    int inputNum, ret, primeCount = 0;

    printf("Enter maximum number to test: ");
    do
    {
        ret = scanf("%d", &inputNum);
        clearKeyboardBuffer();

        if (inputNum <= 0 || ret != 1) printf("Invalid input, must be a positive integer. Retry: ");
    }
    while (inputNum <= 0 || ret != 1);

    printf("Prime numbers in [1, %d] \n", inputNum);
    for (int i = 1; i <= inputNum; ++i)
    {
        if (isPrimeNumber(i) == TRUE)
        {
            primeCount++;
            printf("%3d ", i);

            if (primeCount % 10 == 0) printf("\n");
        }
    }

    printf("\nThere are %d prime numbers in [1, %d]", primeCount, inputNum);

    printf("\n\nPress enter to exit...");
    getchar();

    return 0;
}

boolean isEven(int num)
{
    if (num % 2 == 0) return TRUE;

    return FALSE;
}

boolean isPrimeNumber(int k)
{
    if (k <= 1) return FALSE;

    if (isEven(k) == TRUE && k >= 4) return FALSE;

    for (int m = 3; m < k/2; m+=2)
    {
        if (k % m == 0) return FALSE;
    }

    return TRUE;
}

void clearKeyboardBuffer(void)
{
    while (getchar() != '\n');
}