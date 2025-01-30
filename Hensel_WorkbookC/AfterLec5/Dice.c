/**
 *  Ex 36 - Dice
 *
 *  Function throwDice() will mimic the outcome of rolling a die - will return a random number from 1 to 6
 *  The program will
 *      1. roll the die 100 times
 *      2. print out the resulting numbers in 4 rows with 25 numbers each
 *      5. print out the average number rolled
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int throwDice();

int main(void)
{
    int total = 0;
    double avg = 0;

    srand(time(NULL));

    for (int i = 1; i <= 100; i++)
    {
        int rolledNum = throwDice();
        total += rolledNum;

        printf(" %2d  |", rolledNum);

        if (i % 25 == 0)
            printf("\n");
    }

    avg = (double) total / 100;

    printf("\nThe average number rolled is %.2f", avg);

    return 0;
}

/**
 * @return a random int in range of 1 to 6
 */
int throwDice()
{
    return rand() % 6 + 1;
}