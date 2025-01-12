/**
 *  IE SO 1 Lab 5 - Memory Management & Structures
 *
 *  17.2 - Same functionality of assignment 17.1 except we use a struct to store the coordinates of
 *  the waypoints. An array is dynamically allocated to elements of type struct.
 *
 *  We re-use 2 functions from the earlier lab - getRouteLengthKm() and distanceKm()
 *
 *  This program tests the use of structs and dynamic memory allocation.
 */


// #define _USE_MATH_DEFINES           // needed for windows
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double lat;
    double lon;
} geoCoord;

double getRouteLengthKm(geoCoord *coordinates, int n);
double distanceKm(double lat1, double lon1, double lat2, double lon2);
void clearKeyboardBuffer(void);

int main(void)
{
    int waypoints = 0, ret, i;
    double lat = 0.0, lon = 0.0;
    geoCoord *coordinates;

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

    // dynamically allocate a 1D array of type geoCoord to store the coordinates
    coordinates = (geoCoord *) malloc(waypoints * sizeof(geoCoord));

    // if memory allocation has failed, exit program
    if (coordinates == NULL)
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
            coordinates[i].lat = lat;
            coordinates[i].lon = lon;
            ++i;
        }
        else
        {
            printf("Expected two double values. Try again \"<latitude> <longitude>\": \n");
        }
    }

    // calculate and print the route length in km
    printf("\nBy taking this route you will travel %.1f km", getRouteLengthKm(coordinates, waypoints));

    // free the allocated memory
    free(coordinates);

    return 0;
}

/**
* Calculates the overall distance of a route given 2 arrays consisting of the points' coordinates
*
* @param coordinates an array of coordinates
* @param n the size of the arrays (they're the same)
*/
double getRouteLengthKm(geoCoord *coordinates, int n)
{
    double totalLength = 0.0;

    // Calculate the overall distance of the route
    // by summing the distances between waypoints
    for (int i = 0; i < n - 1; ++i)
        totalLength += distanceKm(coordinates[i].lat, coordinates[i].lon, coordinates[i+1].lat, coordinates[i+1].lon);

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