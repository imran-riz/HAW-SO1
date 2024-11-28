/**
 * Assignment 15.3 - Distances
 *
 * A program to find the local distance and global distance between 2 points given their
 * geographical locations in (latitude, longitude)
 */
#include <stdio.h>
#include <math.h>

double localDistanceKm(double, double, double, double);
double distanceKm(double, double, double, double);

const double PI = 3.142;

int main(void)
{
    printf("\nLocation           | Latitude     | Longitude    | Distance to HAW (km) | Local distance to HAW (km)  ");
    printf("\n------------------------------------------------------------------------------------------------------------------");
    printf("\nHAW Hamburg        | 53.557078    | 10.023109    | %18.1f   | %18.1f", distanceKm(53.557078, 10.023109, 53.557078, 10.023109 ), localDistanceKm(53.557078, 10.023109, 53.557078, 10.023109 ));
    printf("\nEiffel Tower       | 48.858363    | 2.294481     | %18.1f   | %18.1f", distanceKm(48.858363, 2.294481 , 53.557078, 10.023109 ), localDistanceKm(48.858363, 2.294481 , 53.557078, 10.023109 ));
    printf("\nPalma de Mallorca  | 39.562553    | 2.661947     | %18.1f   | %18.1f", distanceKm(39.562553, 2.661947, 53.557078, 10.023109 ), localDistanceKm(39.562553, 2.661947, 53.557078, 10.023109 ));
    printf("\nLas Vegas          | 36.156214    | -115.148736  | %18.1f   | %18.1f", distanceKm(36.156214, -115.148736, 53.557078, 10.023109 ), localDistanceKm(36.156214, -115.148736, 53.557078, 10.023109 ));
    printf("\nCopacabana         | -22.971177   | -43.182543   | %18.1f   | %18.1f", distanceKm(-22.971177 , -43.182543, 53.557078, 10.023109 ), localDistanceKm(-22.971177 , -43.182543, 53.557078, 10.023109 ));
    printf("\nWaikiki Beach      | 21.281004    | -157.837456  | %18.1f   | %18.1f", distanceKm(21.281004, -157.837456, 53.557078, 10.023109 ), localDistanceKm(21.281004, -157.837456, 53.557078, 10.023109 ));
    printf("\nSurfer’s Paradise  | -28.002695   | 153.431781   | %18.1f   | %18.1f", distanceKm(-28.002695 , 153.431781, 53.557078, 10.023109 ), localDistanceKm(-28.002695 , 153.431781, 53.557078, 10.023109 ));

    getchar();

    return 0;
}

/**
 * Calculates and returns the local distance in Km between 2 points based on
 * equation 15.3 in the theory section for lab 3.
 *
 * @param lat1 point 1's latitude in degrees
 * @param lon1 pont 1's longitude in degrees
 * @param lat2 point 2's latitude in degrees
 * @param lon2 point 2's longitude in degrees
 * @return the local distance in Km between the 2 points based on the given coordinates
 */
double localDistanceKm(double lat1, double lon1, double lat2, double lon2)
{
    double distance, deltaX, deltaY, lat1InRad, lat2InRad;

    // convert the latitudes of both points to radians
    lat1InRad = lat1 * (PI / 180.0);
    lat2InRad = lat2 * (PI / 180.0);

    // calculate the distances between latitudes (deltaY) and longitudes (deltaX) of the 2 points
    deltaY = 111.3 * fabs(lat1 - lat2);
    deltaX = 111.3 * cos((lat1InRad + lat2InRad) / 2.0) * fabs(lon1 - lon2);

    // find the overall distance by applying the Pythagorean theorem
    distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    return distance;
}

/**
 * Calculates and returns the global distance in Km between 2 points based on
 * equation 15.4 stated in the theory section for lab 3.
 *
 * @param lat1 point 1's latitude in degrees
 * @param lon1 pont 1's longitude in degrees
 * @param lat2 point 2's latitude in degrees
 * @param lon2 point 2's longitude in degrees
 * @return the global distance
 */
double distanceKm(double lat1, double lon1, double lat2, double lon2)
{
    double lat1InRad, lon1InRad, lat2InRad, lon2InRad, distance;

    // if the points overlap, return 0
    if (lat1 == lat2 && lon1 == lon2) return 0.0;

    // convert the coordinates of point 1 to radians
    lat1InRad = lat1 * (PI / 180.0);
    lon1InRad = lon1 * (PI / 180.0);

    // convert the coordinates of point 2 to radians
    lat2InRad = lat2 * (PI / 180.0);
    lon2InRad = lon2 * (PI / 180.0);

    // calculate the global distance
    distance = 6378.388 * acos(sin(lat1InRad) * sin(lat2InRad) + cos(lat1InRad) *cos(lat2InRad) * cos(fabs(lon2InRad - lon1InRad)));

    return distance;
}
