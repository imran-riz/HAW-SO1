#include <math.h>
#include <stdio.h>

float sine(float alpha, int upperK);
float principalValue(float alpha);

int main(void)
{
    int count, maxK;
    float x, alpha;
    char ltr;

    do
    {
        printf("\nSeries expansion for sin(x * PI) with k > 0 terms.");
        printf("\nPlease enter <x>,<k>: ");
        count = scanf("%f,%d", &x, &maxK);
        getchar();

        // iteratively validate the inputs and allow the user input again
        while (count != 2 || maxK < 0)
        {
            printf("Invalid input. Retry: ");
            count = scanf("%f,%d", &x, &maxK);
            getchar();
        }

        alpha = x * M_PI;

        printf("Approximations of sin(%.2f * pi):", x);
        for (int k = 1; k <= maxK; ++k)
            printf("\n\tk = %2d: sin(x * PI) = %.6f", k, sine(alpha, k));


        printf("\nPrincipal value: %.2f * pi", principalValue(alpha) / M_PI);

        printf("\nEnter <q> to quit, any other key to continue. ");
        scanf("%c", &ltr);
        getchar();
    }
    while (ltr != 'q' && ltr != 'Q');

    return 0;
}

float sine(const float alpha, const int upperK)
{
    float currentProduct = 1.0;

    for (int k = 1; k <= upperK; ++k)
        currentProduct *= 1 - ((alpha * alpha) / (k*k * M_PI*M_PI));

    return alpha * currentProduct;
}

// sin(alpa) = sin(alpha + n*2PI)
// The value alpha in 0 <= alpa < 2PI, is known as the principal value
float principalValue(float alpha)
{
    if (alpha == 0.0) return 0.0;

    if (alpha > 0)
    {
        while (alpha > 2 * M_PI)
            alpha -= 2.0 * M_PI;
    }
    else
    {
        while (alpha < 0.0)
            alpha += 2.0 * M_PI;
    }

    return alpha;
}