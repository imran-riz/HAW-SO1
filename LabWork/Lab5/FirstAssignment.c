/**
 *  IE SO 1 Lab 5 - Memory Management & Structures
 *
 *  17.1 - A program to calculate the total route length given a number of waypoints by the user. The waypoints
 *  are represented by their latitude and longitude coordinates.
 *
 *  We re-use 2 functions from the earlier lab - getRouteLengthKm() and distanceKm()
 *
 *  This program tests the use of dynamic memory allocation.
 */

// #define _USE_MATH_DEFINES           // needed for windows
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getRouteLengthKm(double latitudes[], double longitudes[], int n);
double distanceKm(double lat1, double lon1, double lat2, double lon2);
void clearKeyboardBuffer(void);

int main(void)
{
    int waypoints = 0, ret, i;
    double lat = 0.0, lon = 0.0;
    double *latitudes, *longitudes;

    // get the number of waypoints and validate user input
    printf("Enter the number of waypoints: ");
    ret = scanf("%d", &waypoints);
    clearKeyboardBuffer();
    while (ret != 1 || waypoints <= 0)
    {
        printf("Try again (expected numer >= 0): ");
        ret = scanf("%d", &waypoints);
        clearKeyboardBuffer();
    }

    // dynamically allocate two 1D arrays to store the latitude and longitude of the waypoints
    latitudes = (double *) malloc(waypoints * sizeof(double));
    longitudes = (double *) malloc(waypoints * sizeof(double));

    // if memory allocation has failed, exit program
    if (latitudes == NULL || longitudes == NULL)
    {
        printf("\nFailed to allocate memory. Exiting program!");
        exit(EXIT_FAILURE);
    }

    // get the waypoints validating each input
    printf("\nEnter the waypoints as \"<latitude> <longitude>\":\n");
    i = 0;
    while (i < waypoints)
    {
        printf("Waypoint %d: ", i + 1);
        ret = scanf("%lf %lf", &lat, &lon);
        clearKeyboardBuffer();

        // if scanf successfully reads 2 inputs
        if (ret == 2)
        {
            longitudes[i] = lon;
            ++i;
        }
        else
        {
            printf("Expected two double values. Try again \"<latitude> <longitude>\": \n");
        }
    }

    // calculate and print the route length in km
    printf("\nBy taking this route you will travel %.1f km", getRouteLengthKm(latitudes, longitudes, waypoints));

    // free the allocated memory
    free(latitudes);
    free(longitudes);

    return 0;
}

/**
* Calculates the overall distance of a route given 2 arrays consisting of the points' coordinates
*
* @param latitudes an array of latitudes
* @param longitudes an array of longitudes
* @param n the size of the arrays (they're the same)
*/
double getRouteLengthKm(double latitudes[], double longitudes[], int n)
{
    double totalLength = 0.0;

    // Calculate the overall distance of the route
    // by summing the distances between waypoints
    for (int i = 0; i < n - 1; ++i)
        totalLength += distanceKm(latitudes[i], longitudes[i], latitudes[i + 1], longitudes[i + 1]);

    return totalLength;
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
double distanceKm(double lat1, double lon1, double lat2, double lon2)
{
    double lat1InRad, lon1InRad, lat2InRad, lon2InRad;

    // if the points overlap, return 0
    if (lat1 == lat2 && lon1 == lon2) return 0.0;

    // convert the coordinates of point 1 to radians
    lat1InRad = lat1 * (M_PI / 180.0);
    lon1InRad = lon1 * (M_PI / 180.0);

    // convert the coordinates of point 2 to radians
    lat2InRad = lat2 * (M_PI / 180.0);
    lon2InRad = lon2 * (M_PI / 180.0);

    // calculate and return the global distance
    return 6378.388 * acos(sin(lat1InRad) * sin(lat2InRad) + cos(lat1InRad) * cos(lat2InRad) * cos(fabs(lon2InRad - lon1InRad)));
}


void clearKeyboardBuffer(void)
{
    while (getchar() != '\n')
        /* NOP */;
}