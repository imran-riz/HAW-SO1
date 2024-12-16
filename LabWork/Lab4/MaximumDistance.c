/**
 *  IE SO 1 Lab 4 - Arrays and Pointers
 *
 *  A program that finds the maximum distance in Km between 2 locations using their coordinates,
 *  given as (latitude, longitude).
 *
 *  A 1D array stores the names of the locations and a 2D array stores their coordinates respectively.
 *  The coordinates array is passed to a function that performs the search. The function returns the max distance
 *  and the indices of the 2 locations given 2 pointers.
 */

#include <stdio.h>
#include <math.h>

double getMaximumDistance(const double coords[][2], int n, int *indexA, int *indexB, char *names[]);
double getRouteLengthKm(double lat1, double lon1, double lat2, double lon2);

int main(void)
{
    char *names[] =
    {
        "HAW Hamburg",
        "Eiffel Tower",
        "Palma de Mallorca",
        "Las Vegas",
        "Copacabana",
        "Waikiki Beach",
        "Surfer's Paradise"
    };
    double coordinates[][2] =
    {
        {53.557078, 10.023109},
        {48.858363, 2.294481},
        {39.562553, 2.661947},
        {36.156214, -115.148736},
        {-22.971177, -43.182543},
        {21.281004, -157.837456},
        {-28.002695, 153.431781},
    };
    int numOfElements = sizeof coordinates / sizeof coordinates[0];
    int rowA = 0;           // row index of first location
    int rowB = 0;           // row index of second location
    double maxDistance = getMaximumDistance(coordinates, numOfElements, &rowA, &rowB, names);

    printf("\n\n%s and %s have the largest distance (%.2f km). \nYou'd better not walk. Take a flight instead.", names[rowA], names[rowB], maxDistance);

    return 0;
}

/**
 * Searches for the 2 locations (A and B) in an array of coordinates
 * that have the maximum distance between them.
 *
 * @param coords nx2 array containing the latitudes and longitudes of locations
 * @param n the number of locations (elements) in the coords array
 * @param indexA address of the variable that stores the row index of location A
 * @param indexB address of the variable that stores the row index of location B
 * @param names address of the names array of the n locations (used for testing)
 * @return the max distance between 2 locations
 */
double getMaximumDistance(const double coords[][2], const int n, int *indexA, int *indexB, char *names[])
{
    double maxDistance = 0.0;
    double tempDistance = 0.0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n ; ++j)
        {
            tempDistance = getRouteLengthKm(coords[i][0], coords[i][1], coords[j][0], coords[j][1]);

            // testing
            // printf("\nChecking from %s to %s", names[i], names[j]);
            // printf("\nDistance = %.2f", tempDistance);

            // if the distance of the current 2 points are larger,
            // update the max distance and store the indices of the new locations
            if (tempDistance > maxDistance)
            {
                maxDistance = tempDistance;
                *indexA = i;
                *indexB = j;
            }
        }
    }

    return maxDistance;
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