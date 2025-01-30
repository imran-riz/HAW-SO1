#include <stdio.h>
#include <math.h>

// Ex 5. Used the pow function to calculate the weights of binary numbers as I was lazy
void binaryWeights() {
    for (int n = 1; n < 8; ++n) {
        int weight = (int) pow(2, n);
        printf("2 ^ %d = %d\n", n, weight);
    }
}

// Ex 6.
void teamPlayers() {
    int pupilCount = 26;
    int pupilsPerTeam = 4;
    int teams = pupilCount / pupilsPerTeam;
    int pupilsLeftOut = pupilCount % pupilsPerTeam;

    printf("For class of %d pupils there can %d teams of %d pupils each, with %d pupils left out. \n", pupilCount, teams, pupilsPerTeam, pupilsLeftOut);
}

// Ex 9.
void resistorsParallel() {
    const double r1 = 150.0;
    const double r2 = 220.0;
    const double totalResistance = (r1 * r2) / (r1 + r2);

    printf("Total resistance of two resistors in parallel is %.2f \n", totalResistance);
}



int main() {
    binaryWeights();
}