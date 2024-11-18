#include <stdio.h>

void maxValue() {
    int num1, num2, max;

    printf("Enter 2 integers separated by a comma: ");
    scanf("%d,%d", &num1, &num2);
    getchar();

    max = (num1 > num2) ? num1 : num2;

    printf("%d is the max number", max);
}

void martyMcFly() {
    int birthYear, currentYear, age;

    printf("Enter your year of birth: ");
    scanf("%d", &birthYear);
    getchar();

    printf("Enter the current year: ");
    scanf("%d", &currentYear);
    getchar();

    age = currentYear - birthYear;

    if (age > 0)
        printf("At the end of year %d you will %d years old. \n", currentYear, age);
    else
        printf("Hello Marty, are you ready to travel \"Back to the future\"?");
}


void weekday() {
    int weekday;

    printf("Enter a day number (1: Monday, 2: Tuesday, .... , 7: Sunday): ");
    scanf("%d", &weekday);
    getchar();

    // switch (weekday) {
    //     case 1:
    //         printf("Monday\n");
    //         break;
    //     case 2:
    //         printf("Tuesday\n");
    //         break;
    //     case 3:
    //         printf("Wednesday\n");
    //         break;
    //     case 4:
    //         printf("Thursday\n");
    //         break;
    //     case 5:
    //         printf("Friday\n");
    //         break;
    //     case 6:
    //         printf("Saturday\n");
    //         break;
    //     case 7:
    //         printf("Sunday\n");
    //         break;
    //     default:
    //         printf("Wait. I don't know that day...\n");
    // }
    switch (weekday) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Go work. \n");
            break;
        case 6:
            printf("Go shopping. \n");
            break;
        case 7:
            printf("Relax. \n");
            break;
        default:
            printf("I don't know that day...");
    }
}

void underlineText() {
    int charCount = printf("Please give me a floor to stand upon\n");

    while (charCount > 1) {
        printf("-");
        --charCount;
    }
}

void averageValue() {
    double num, count = 0, sum = 0;
    int inputOK;

    printf("Enter numbers (any other character to stop): ");
    inputOK = scanf("%lf", &num);                   // the lf specifier is used for double data type
    getchar();

    while (inputOK) {
        count++;
        sum += num;

        inputOK = scanf("%lf", &num);
        getchar();
    }

    if (count > 0)
        printf("The average value is %.2f", sum / count);
}

int main(void) {
    averageValue();
}