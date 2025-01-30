#include <stdio.h>

double leibnizSeries(int);

int main(void)
{
    double approxPI = 0.0;

    for (int i = 0; i <= 1000; i+=50)
    {
        approxPI = leibnizSeries(i);
        printf("\nThe approx. of PI for %4d summands is %.4f", i, approxPI);
    }

    return 0;
}

double leibnizSeries(int maxN)
{
    double pi = 0.0;
    double sum = 0.0 ;
    double summand = 0.0;
    int sign = 1;

    for (int n = 0; n <= maxN; n++)
    {
        summand = sign / (double) (2*n + 1);
        sum += summand;
        sign *= -1;
    }

    pi = 4.0 * sum;

    return pi;
}