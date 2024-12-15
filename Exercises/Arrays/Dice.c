/**
 *  A program that will simulate throwing a die a fixed number of times and then
 *      stores the number of a times a result (1 to 6) occurs
 *      calculates & displays the percentage frequency of each result
 */
#include <stdio.h>
#include <stdlib.h>

int throwDice();

int main(void)
{
    const double ROLL_COUNT = 1.0e+6;
    int value;
    double freq;
    int array[6] = {};

    for (int i = 0; i < (int) ROLL_COUNT; ++i)
    {
        value = throwDice();
        array[value-1]++;
    }

    printf("\nNumber of dice throws: %.1e", ROLL_COUNT);
    printf("\nRelative frequencies:");
    for (int i = 0; i < 6; ++i)
    {
        freq = (array[i] / ROLL_COUNT) * 100;
        printf("\nResult %d: %.2f %%", i+1, freq);
    }

    return 0;
}

/**
 * @return a random int in range of 1 to 6
 */
int throwDice()
{
    return rand() % 6 + 1;
}