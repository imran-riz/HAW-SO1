// #define_USE_MATH_DEFINES         // for windows
#include <stdio.h>
#include <math.h>

void swap(int *a, int *b);
void transformToPolarCoords(double x, double y, double *r, double *phi);

int main(void)
{
    // int num1 = 10, num2 = 12;
    // printf("\nBefore: num1 = %d, num2 = %d", num1, num2);
    // swap(&num1, &num2);         // pass the address of the variables using the & character
    // printf("\nAfter: num1 = %d, num2 = %d", num1, num2);

    double x = 2.0, y = 3.75;
    double r, phi;
    printf("\nCartesian: (x, y) = (%.2f, %.2f)", x, y);
    transformToPolarCoords(x, y, &r, &phi);
    printf("\nPolar: (x, y) = (%.2f, %.2f * pi)", r, phi / M_PI);


    return 0;
}

void swap(int *a, int *b)
{
    const int temp = *a;
    *a = *b;
    *b = temp;

    printf("\nAddresses received: a = %p, b = %p", a, b);
}

/**
 * Transforms Cartesian coords (x, y) to polar coords (r, phi) where
 * r = sqrt(x^2 + y^2) and phi = atan2(y, x)
 */
void transformToPolarCoords(double x, double y, double *r, double *phi)
{
    *r = sqrt((x * x) + (y * y));
    *phi = atan2(y, x);
}