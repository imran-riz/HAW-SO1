#include <stdio.h>


/*
    - On Jan 1, the balance is 1000 EUR.
    - The rate of return is 2% every year.
    - Print the balance after 1, 2 and 3 years.
*/
void bankAccount() {
    int balance = 1000;
    int rate = 2;

    printf("Initial balance: %d EUR \n", balance);

    balance = balance * (100 + rate)/100;
    printf("Balance after 1 year: %d EUR \n", balance);

    balance = balance * (100 + rate)/100;
    printf("Balance after 2 years: %d EUR \n", balance);

    balance = balance * (100 + rate)/100;
    printf("Balance after 3 years: %d EUR \n", balance);
}

/*
    Done using floats rounded off to 2dp
*/
void bankAccount2() {
    float balance = 1000;
    float rate = 0.02;

    printf("Initial balance: %.2f EUR \n", balance);

    balance = balance * (1 + rate);
    printf("Balance after 1 year: %.2f EUR \n", balance);

    balance = balance * (1 + rate);
    printf("Balance after 2 years: %.2f EUR \n", balance);

    balance = balance * (1 + rate);
    printf("Balance after 3 years: %.2f EUR \n", balance);
}

/*
    - You've run and covered 4.87km in 29:30 minutes
    - Calculate and print your average pace in km/h
*/
void running() {
    float distance = 4.87;
    float timeMinutes = 29.5;
    float timeHours = timeMinutes / 60;

    float avgPace = distance / timeHours;

    printf("Average pace: %.2f km/h \n", avgPace);
}


void running2() {
    float distanceKm, timeHours;
    int timeMinutes, timeSeconds, ret;

    printf("Distance covered in km: ");
    scanf("%f", &distanceKm);
    getchar();
    printf("Time taken (minutes): ");
    scanf("%d", &timeMinutes);
    getchar();
    printf("Time taken (seconds): ");
    scanf("%d", &timeSeconds);
    getchar();

    timeHours = (timeSeconds/60.0 + timeMinutes) / 60.0;

    printf("Average pace: %.2f km/h \n", distanceKm / timeHours);
}


void circle() {
    const float PI = 3.141592;
    float radius, circumference, area;

    radius = 1.5;
    circumference = 2 * PI * radius;
    area = PI * (radius * radius);

    printf("Circumference: %.2f units \n", circumference);
    printf("Area: %.2f units^2 \n", area);
}


void calculateAge() {
    int yearOfBirth, currentYear;

    printf("What year were you born in? ");
    scanf("%d", &yearOfBirth);
    getchar();      // used after scanf to consume the newline character (when the user hits Enter) left in the buffer

    printf("Whats the current year? ");
    scanf("%d", &currentYear);
    getchar();

    printf("You are %d years old by the end of %d \n", (currentYear - yearOfBirth), currentYear);
}


void circle2() {
    const double PI = 3.141592;
    float radius, circumference, area;

    printf("Enter a radius: ");
    scanf("%f", &radius);
    getchar();

    circumference = 2 * PI * radius;
    area = PI * (radius * radius);

    printf("Circumference: %.2f units \n", circumference);
    printf("Area: %.2f units^2 \n", area);
}


void printCharCodes() {
    char input;

    printf("Enter any character: ");
    scanf("%c", &input);
    getchar();

    printf("Entered character is %c and its ASCII code is %d \n", input, input);
}


void incrementAndDecrementOperators() {
    int a = 1;
    float b = 1.25;

    printf("a: %d \n", a);          // 1
    printf("++a: %d \n", ++a);      // 2        -- prefix increment operator (increments the value of a and then returns the incremented value)
    printf("a++: %d \n", a++);      // 2        -- postfix increment operator (returns the value of a and then increments the value of a)
    printf("--a: %d \n\n", --a);    // 2
    printf("a--: %d \n", a--);      // 2

    printf("b: %.2f \n", b);        // 1.25
    printf("++b: %.2f \n", ++b);    // 2.25
}


int main(void) {
    incrementAndDecrementOperators();

    return 0;
}