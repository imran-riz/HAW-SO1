#include <stdio.h>


// Ex 11.
void fahrenheit() {
    float tempFahrenheit, tempCelsius;

    printf("Enter a temperature in Fahrenheit: ");
    scanf("%f", &tempFahrenheit);
    getchar();

    tempCelsius = (tempFahrenheit - 32.0) * 5.0/9.0;

    printf("The temperature in Celsius is %.2f \n", tempCelsius);
}


// Ex 12.
void charToNumeric() {
    char input;

    printf("Enter any character: ");
    scanf("%c", &input);
    getchar();

    printf("Entered character is %c and its ASCII code is %d \n", input, input);
}


// Ex 13.
void lower2Upper() {
    char input;

    printf("Enter a lowercase character (a-z): ");
    scanf("%c", &input);
    getchar();

    // ASCII code of 'a' is 97 and 'A' is 65. The difference is 32.
    printf("The character %c in uppercase is %c \n", input, input - 32);
}


// Ex. 14
void timeSeconds() {
    unsigned seconds, minutes, hours;

    printf("Enter a time period in seconds: ");
    scanf("%d", &seconds);
    getchar();

    // calculate and print the formated time as hh:mm:ss
    hours = seconds / 3600;
    minutes = (seconds / 60) - (hours * 60);
    seconds = seconds - (minutes * 60) - (hours * 3600);
    printf("The formatted time is: %02u:%02u:%02u", hours, minutes, seconds);
}


// Ex. 15 - without a loop
void averageGrade() {
    int grade1Count, grade2Count, grade3Count, grade4Count, grade5Count, grade6Count;
    int studentCount = 0, weightedSum = 0;

    printf("Please enter number of grades 1 to 6 separated by commas: ");
    scanf("%d,%d,%d,%d,%d,%d", &grade1Count, &grade2Count, &grade3Count, &grade4Count, &grade5Count, &grade6Count);
    getchar();

    studentCount = grade1Count + grade2Count + grade3Count + grade4Count + grade5Count + grade6Count;
    weightedSum = grade1Count + 2*grade2Count + 3*grade3Count + 4*grade4Count + 5*grade5Count + 6*grade6Count;

    printf("The average grade is %.2f", (float) weightedSum / (float) studentCount);
}


// Ex. 16
void logicLevel() {
    double r1, r2, iRX, uRX, u0 = 5.0;

    printf("Enter the resistance for r1: ");
    scanf("%f", &r1);
    getchar();
    printf("Enter the resistance for r2: ");
    scanf("%f", &r2);
    getchar();

    iRX = 0.0;
    uRX = (r2 / (r1 + r2)) * (u0 - r1 * iRX);
    printf("\nWhen iRX = 0 mA, uRX = %.1f V", uRX);

    iRX = 0.5e-3;
    uRX = (r2 / (r1 + r2)) * (u0 - r1 * iRX);
    printf("\nWhen iRX = 0.5 mA, uRX = %.1f V", uRX);
}

void logicLevelAns() {

    int r1, r2;
    double u0 = 5.0, uRX, iRX;

    // Get user input: grade counts
    printf("Please enter resistances R1 and R2 separated by a comma: ");
    scanf("%d,%d", &r1, &r2);
    getchar();

    // Calculate and print results for I_RX = 0 mA
    iRX = 0;
    uRX = r2 / (double)(r1 + r2) * (u0 - r1 * iRX);
    printf("U_RX = %.1f V for I_RX = %.1f mA.\n", uRX, 1.0e3 * iRX);

    // Calculate and print results for I_RX = 0.5 mA
    iRX = 0.5e-3;
    uRX = r2 / (double)(r1 + r2) * (u0 - r1 * iRX);
    printf("U_RX = %.1f V for I_RX = %.1f mA.\n", uRX, 1.0e3 * iRX);

    getchar();
}

int main(void) {
    timeSeconds();
    return 0;
}