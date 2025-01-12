#include <math.h>

const double PI = 3.141592654;

/**
 * Cartesian coordinates (x, y) will be transformed to Polar coordinates r * phi
 *
 * @param x x coordinate
 * @param y y coordinate
 * @param r pointer to radius
 * @param phi pointer to phi
 */
void toPolarCoordinates(double x, double y, double *r, double *phi)
{
    *r = sqrt(x * x + y * y);
    *phi = atan2(y, x);
}