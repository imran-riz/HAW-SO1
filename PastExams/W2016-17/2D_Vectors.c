#include <stdio.h>
#include <math.h>

// Manifest constants
#define DIM 2

// Function prototypes
void printVector2D(const double v[DIM]);
double vectorLength(const double v[DIM]);
void scaleVector2D(double v[DIM], double k);
double dotProduct2D(const double v1[DIM], const double v2[DIM]);

// Main function
int main(void)
{
    double a1[DIM] = { 3.0, 4.0 };
    double a2[DIM] = { -2.0, 6.0 };

    // print out vectors
    printf("Vectors: \na1 = ");
    printVector2D(a1);
    printf("\na2 = ");
    printVector2D(a2);

    printf("\n\nVector length \n|a1| = %.1f \n", vectorLength(a1));

    printf("\nScale a2 with 0.5: \n");
    scaleVector2D(a2, 0.5);
    printf("a2 = ");
    printVector2D(a2);

    printf("\n\nDot product: \n");
    printf("<a1, a2> = %.1f \n", dotProduct2D(a1, a2));

    getchar();

    // added a new comment
    return 0;
}

void printVector2D(const double v[DIM])
{
    printf("(%.1f, %.1f)", v[0], v[1]);
}

double vectorLength(const double v[DIM])
{
    return sqrt(v[0] * v[0] + v[1] * v[1]);
}

void scaleVector2D(double v[DIM], double k)
{
    v[0] *= k;
    v[1] *= k;
}

double dotProduct2D(const double v1[DIM], const double v2[DIM])
{
    return v1[0] * v2[0] + v1[1] * v2[1];
}
