#include <math.h>
#include <stdio.h>

double getRouteLengthKm(double lat1, double lon1, double lat2, double lon2);

int main(void)
{
    double latitudes[] =
    {
        53.557029,
        53.557166,
        53.557274,
        53.560288,
        53.561306,
        53.562015,
        53.558241,
        53.557900,
        53.557203
    };
    double longitudes[] =
    {
        10.022918,
        10.021343,
        10.020297,
        10.014906,
        10.015426,
        10.016568,
        10.023244,
        10.022142,
        10.022632
    };
    int numOfElements = sizeof latitudes / sizeof latitudes[0];
    double overallDistance = 0.0;

    // Calculate the overall distance of the route
    // by summing the distances between waypoints
    for (int i = 0; i < numOfElements - 1; ++i)
        overallDistance += getRouteLengthKm(latitudes[i], longitudes[i], latitudes[i+1], longitudes[i+1]);

    printf("The overall distance is %.2fkm", overallDistance);

    return 0;
}

/**
 * Calculates and returns the distance in Km between 2 points based on
 * equation 15.4 stated in the theory section for lab 3.
 *
 * @param lat1 point 1's latitude in degrees
 * @param lon1 pont 1's longitude in degrees
 * @param lat2 point 2's latitude in degrees
 * @param lon2 point 2's longitude in degrees
 * @return the global distance
 */
double getRouteLengthKm(double lat1, double lon1, double lat2, double lon2)
{
    double lat1InRad, lon1InRad, lat2InRad, lon2InRad, distance;

    // if the points overlap, return 0
    if (lat1 == lat2 && lon1 == lon2) return 0.0;

    // convert the coordinates of point 1 to radians
    lat1InRad = lat1 * (M_PI / 180.0);
    lon1InRad = lon1 * (M_PI / 180.0);

    // convert the coordinates of point 2 to radians
    lat2InRad = lat2 * (M_PI / 180.0);
    lon2InRad = lon2 * (M_PI / 180.0);

    // calculate the global distance
    distance = 6378.388 * acos(sin(lat1InRad) * sin(lat2InRad) + cos(lat1InRad) * cos(lat2InRad) * cos(fabs(lon2InRad - lon1InRad)));

    return distance;
}