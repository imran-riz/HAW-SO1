/*
 * Lab 2 on Nov 18, 2024
 * Question 14.2 - Wheat on chessboard problem
 * Author - Imran Rizwan, Gibriel Zibo
 */

#include <stdio.h>

int main(void)
{
    const unsigned short FIELD_MAX = 64;

    int field = 1;
    unsigned long long grainsOnField = 1;
    unsigned long long sumOfGrains = 1;
    double totalWeight = 0;
    double p = 0;

    printf(" Field |  On Field            |  Sum \n");
    printf("-----------------------------------------------------------------\n");
    printf(" %5d | %20llu | %20llu (= %.2e)\n", field, grainsOnField, sumOfGrains, (double) sumOfGrains);

    for (field = 2; field <= FIELD_MAX; ++field)
    {
        grainsOnField *= 2;
        sumOfGrains += grainsOnField;

        printf(" %5d | %20llu | %20llu (= %.2e)\n", field, grainsOnField, sumOfGrains, (double) sumOfGrains);

        if (field % 8 == 0)
            printf("-----------------------------------------------------------------\n");
    }

    // calculate the total weight (in tonnes) given that its 55mg per grain
    totalWeight = (double) sumOfGrains * (55 * 10e-9);

    // calculate the ratio of the total weight to the worldwide wheat production in 2015, 735.8 million tonnes
    p = totalWeight / (753.8 * 10e6);

    printf("Total weight of wheat = %.3e tonnes\n", totalWeight);
    printf("Ratio p = %.2f\n", p);

    return 0;
}


/*
 *  We observe the limitations of the following data types:
 *          Data type       | Size        | Max value                             | Max number of values
 *      -------------------------------------------------------------------------------------------------
 *       int                |  32 bits    | 2^31 - 1 = 2,147,483,647              |   2^32 values
 *       unsigned int       |  32 bits    | 2^32 - 1 = 4,294,967,295              |   2^32 values
 *       short              |  16 bits    | 2^15 - 1 = 32,767                     |   2^16 values
 *       unsigned short     |  16 bits    | 2^16 - 1 = 65,535                     |   2^16 values
 *       long               |  64 bits    | 2^63 - 1 = 9,223,372,036,854,775,807  |   2^64 values
 *       unsigned long      |  64 bits    | 2^64 - 1 = 18,446,744,073,709,551,615 |   2^64 values
 *       unsigned long long |  64 bits    | 2^64 - 1 = 18,446,744,073,709,551,615 |   2^64 values
 */