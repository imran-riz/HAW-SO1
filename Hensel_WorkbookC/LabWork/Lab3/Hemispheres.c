/**
* Assignment 15.2 - Hemispheres
*
* A program that determines if a geographical location, given by its latitude and longitude, is
* in the Northern or Southern hemispheres.
*/

#include <stdio.h>

int isNorthernHemisphere(double, double);
int isSouthernHemisphere(double, double);

int main(void)
{
    // Test coordinates for Northern hemisphere
    printf("\nAre these locations in the Northern hemisphere?");
    printf("\n\tNew York City, USA: Lat 40.714°, Lon -74.006°? \t%s", isNorthernHemisphere(40.714, -74.006) == 1 ? "True": "False");
    printf("\n\tSydney, Australia: Lat -33.868°, Lon 151.209°? \t%s", isNorthernHemisphere(-33.8688, 151.2093) == 1 ? "True": "False");

    // Test coordinates for Southern hemisphere
    printf("\n\nAre these locations in the Southern hemisphere?");
    printf("\n\tNew York City, USA: Lat 40.714°, Lon -74.006°? \t%s", isSouthernHemisphere(40.714, -74.006) == 1 ? "True": "False");
    printf("\n\tSydney, Australia: Lat -33.868°, Lon 151.209°? \t%s", isSouthernHemisphere(-33.8688, 151.2093) == 1 ? "True": "False");

    return 0;
}

/**
 * Checks if a given point is in the Northern hemisphere of the Earth.
 * Any point that has a latitude in the range 0 deg to 90 deg is in the Northern hemisphere.
 *
 * @param lat the latitude of the point in degrees
 * @param lon the longitude of the point in degrees
 * @return 1 if true, 0 if false
 */
int isNorthernHemisphere(double lat, double lon)
{
    if (lat > 0.0 && lat <= 90.0) return 1;

    return 0;
}

/**
 * Checks if a given point is in the Southern hemisphere of the Earth.
 * Any point that has a latitude in the range 0 deg to -90 deg is in the Southern hemisphere.
 *
 * @param lat the latitude of the point in degrees
 * @param lon the longitude of the point in degrees
 * @return 1 if true, 0 if false
 */
int isSouthernHemisphere(double lat, double lon)
{
    if (lat < 0.0 && lat >= -90.0) return 1;

    return 0;
}
