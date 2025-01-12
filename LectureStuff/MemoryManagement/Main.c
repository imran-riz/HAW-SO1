#include <stdio.h>

// declare external variables and functions from PolarCoords.c to use
extern const double PI;
extern void toPolarCoordinates(double x, double y, double *r, double *phi);


int main(void)
{
    double x, y, r = 0, phi = 0;

    printf("\nEnter a pair of coordinates (x,y): ");
    scanf("(%lf,%lf)", &x, &y);

    toPolarCoordinates(x, y, &r, &phi);
    printf("\nIn Polar form (r, phi): (%.2f, %.2f) ", r, phi);


    return 0;
}

/*
 *  To run this program both the Main.c file and the PolarCoords.c file should be compiled and linked
 *  into a single binary file.
 *      gcc PolarCoords.c Main.c -o MainProgram
 */