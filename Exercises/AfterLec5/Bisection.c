/**
 *  A program with a bisection function to approximate zero-crossing of f(x) = x^2 - 2x - 1
 */

#include <stdio.h>

double bisection(double xL, double xR, double intervalSize);
double f(double x);

int main(void)
{
    printf("%.9f", bisection(0, 4, 10e-6));
    return 0;
}

double bisection(double xL, double xR, double intervalSize)
{
    double deltaX = xL - xR;
    double fxL = 0.0, fxR = 0.0, xM, fxM;

    while (deltaX < intervalSize)
    {
        xM = 0.5 * (xL + xR);

        fxL = f(xL);
        fxR = f(xR);
        fxM = f(xM);

        if (xL * xM > 0)
        {
            xL = xM;
            fxL = fxM;
        }
        else
        {
            xR = xM;
            fxR = fxM;
        }

        deltaX = xR - xL;
    }

    return 0.5 * (fxL + fxR);
}

// f(x) = x^2 - 2x - 1
double f(double x)
{
    return (x*x) - 2.0*x - 1.0;
}