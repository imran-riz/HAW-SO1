#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int x;
    int y;
} point2D;

/* Function prototypes */
int keyboardInputNumberPoints(void);
point2D* generateRandomPoints(int numberPoints);
void printPoints(point2D *points, int numberPoints);
point2D getCenterOfGravity(point2D* points, int numberPoints);
void clearKeyboardBuffer(void);

int main(void)
{
    int numPoints = keyboardInputNumberPoints();
    point2D *points = generateRandomPoints(numPoints);
    point2D cog;

    // exit program if dynamic memory allocation has failed
    if (points == NULL)
    {
        printf("Failed to allocated memory! Exiting program. \n");
        exit(EXIT_FAILURE);
    }

    // display the randomly generated coordinates
    printf("Number entered: %d \n", numPoints);
    printPoints(points, numPoints);

    // display the center of gravity of all points
    cog = getCenterOfGravity(points, numPoints);
    printf("\nCenter of gravity: cog = (%d, %d)", cog.x, cog.y);

    // free the dynamically allocated memory
    free(points);

    return 0;
}

/*
 * Gets the number of points from the user. Each input is validated to ensure
 * data type and that it's positive.
 */
int keyboardInputNumberPoints(void)
{
    int numPoints = 0;
    int ret;

    do
    {
        printf("Enter number of 2D points to generate: ");
        ret = scanf("%d", &numPoints);
        clearKeyboardBuffer();

        if (ret != 1)
            printf("Invalid input. Try again. \n\n");
        else if (numPoints < 1)
            printf("Number of points must be positive. Try again. \n\n");
    }
    while (ret != 1 || numPoints < 1);

    return numPoints;
}

/*
 * Creates an array of size numberPoints and generates random coordinates for each
 * x and y in the range of 0 to 9
 */
point2D* generateRandomPoints(int numberPoints)
{
    point2D* points = (point2D *) malloc(numberPoints * sizeof(point2D));

    srand((unsigned int) time(NULL));

    for (int i = 0; i < numberPoints; ++i)
    {
        points[i].x = (rand() % 9) + 1;
        points[i].y = (rand() % 9) + 1;
    }

    return points;
}

/*
 * Prints out each point in the array in the format of Pk(x, y)
 * where k is a running number starting with 1 and x & y are replaced by the respective values
 */
void printPoints(point2D *points, int numberPoints)
{
    for (int i = 0; i < numberPoints; ++i)
        printf("P%d = (%d, %d) \n", i + 1, points[i].x, points[i].y);
}

/*
 * Calculates and returns the mean values of all points in an array.
 */
point2D getCenterOfGravity(point2D* points, int numberPoints)
{
    point2D center;
    int sumX = 0;
    int sumY = 0;

    for (int i = 0; i < numberPoints; ++i)
    {
        sumX += points[i].x;
        sumY += points[i].y;
    }

    center.x = (int) ((sumX + 0.5) / numberPoints);
    center.y = (int) ((sumY + 0.5) / numberPoints);

    return center;
}

void clearKeyboardBuffer()
{
    while (getchar() != '\n');
}