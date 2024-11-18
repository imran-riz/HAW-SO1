#include <stdio.h>

int main(void) {
    const int MAX_EXPONENT = 16;
    int n, ret, weight;

    printf("Calculation of 2^n with n in [0, %d]:\n", MAX_EXPONENT);

    do {
        // get user input
        printf("Enter n: ");
        ret = scanf("%d", &n);
        getchar();              // empty keyboard line buffer after user input

        // if n's data type is invalid, break out of loop and end program
        if (ret == 0) break;

        // if n is not in range, show error message
        if (n < 0 || n > MAX_EXPONENT) {
            printf("Incorrect input: Not in [0, %d]\n", MAX_EXPONENT);
        }
        else {
            // otherwise, calculate the weight
            weight = 1;
            for (int i = 1; i <= n; ++i) {
                weight = weight * 2;
            }

            // display formatted result
            printf("2^%d = %d\n", n, weight);
        }
    } while (1);
}
