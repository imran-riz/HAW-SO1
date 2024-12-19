#include <math.h>
#include <stdio.h>

float sine(float alpha, int upperK);
float principalValue(float alpha);

int main(void)
{
    int kMax;
    float x;
    char ltr;

    do
    {
        printf("\nSeries expansion for sin(x * PI) with k > 0 terms.");
        printf("\nPlease enter <x>,<k>: ");
        scanf("%f,%d", &x, &kMax);
        getchar();

        if (kMax < 0)
        {
            printf("Invalid input. Retry: ");
            scanf("%f,%d", &x, &kMax);
            getchar();
        }
        else
        {
            printf("Approximations of sin(%.2f * pi):", x);
            for (int k = 1; k <= kMax; ++k)
            {
                printf("\n\tk = %2d: sin(x * PI) = %.6f", k, sine(x * M_PI, k));
            }

            printf("\nPrincipal value: %.2f * pi", principalValue(x * M_PI) / M_PI);

            printf("\nEnter <q> to quit, any other key to continue. ");
            scanf("%c", &ltr);
            getchar();

            if (ltr == 'q' || ltr == 'Q') break;
        }
    }
    while (1);

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