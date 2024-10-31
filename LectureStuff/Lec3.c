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
    const float PI = 3.141592;
    float radius, circumference, area;

    printf("Enter a radius: ");
    scanf("%f", &radius);
    getchar();

    circumference = 2 * PI * radius;
    area = PI * (radius * radius);

    printf("Circumference: %.2f units \n", circumference);
    printf("Area: %.2f units^2 \n", area);
}



int main(void) {
    calculateAge();

    return 0;
}