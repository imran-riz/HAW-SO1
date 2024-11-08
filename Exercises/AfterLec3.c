#include <stdio.h>


// Ex 11.
void fahrenheit() {
    float tempFarenheit, tempCelsius;

    printf("Enter a temperature in Fahrenheit: ");
    scanf("%f", &tempFarenheit);
    getchar();

    tempCelsius = (tempFarenheit - 32) * 5/9;

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
    int seconds, minutes, hours;

    printf("Enter a time period in seconds: ");
    scanf("%d", &seconds);
    getchar();

    // format the time as hh:mm:ss
    hours = seconds / 3600;
    minutes = (seconds / 60) - (hours * 60);
    seconds = seconds - (minutes * 60) - (hours * 3600);

    printf("The formatted time is: %02d:%02d:%02d", hours, minutes, seconds);
}


// Ex. 15 - without a loop
void averageGrade() {
    int grade1Count, grade2Count, grade3Count, grade4Count, grade5Count, grade6Count, studentCount;
    float avgGrade = 0.0;

    printf("Enter the number of students who got a grade of 1: ");
    scanf("%d", &grade1Count);
    getchar();
    printf("Enter the number of students who got a grade of 2: ");
    scanf("%d", &grade2Count);
    getchar();
    printf("Enter the number of students who got a grade of 3: ");
    scanf("%d", &grade3Count);
    getchar();
    printf("Enter the number of students who got a grade of 4: ");
    scanf("%d", &grade4Count);
    getchar();
    printf("Enter the number of students who got a grade of 5: ");
    scanf("%d", &grade5Count);
    getchar();
    printf("Enter the number of students who got a grade of 6: ");
    scanf("%d", &grade6Count);
    getchar();

    studentCount = grade1Count + grade2Count + grade3Count + grade4Count + grade5Count + grade6Count;

    avgGrade = ((1 * (float)grade1Count) + (2 * (float)grade2Count) + (3 * (float)grade3Count) + (4 * (float)grade4Count) + (5 * (float)grade5Count) + (6 * (float)grade6Count)) / studentCount;

    printf("The average grade is %f", avgGrade);
}


// Ex. 16
void logicLevel() {

}

int main(void) {
    averageGrade();
    return 0;
}