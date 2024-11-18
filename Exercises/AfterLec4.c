#include <stdio.h>

// Ex. 17
void checkCharacter() {
    char input;

    printf("Enter a character: ");
    scanf("%c", &input);
    getchar();

    if (input >= '0' && input <= '9') {
        printf("You entered a digit");
    }
    else if (input >= 'a' && input <= 'z') {
        printf("You entered a simple letter.");
    }
    else if (input >= 'A' && input <= 'Z') {
        printf("You entered a capital letter.");
    }
    else {
        printf("Your entered character is neither a digit nor a letter");
    }
}

// Ex. 18
void leapYear() {
    int year, isLeapYear = 0;

    printf("Enter a year to check: ");
    scanf("%d", &year);
    getchar();

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        isLeapYear = 1;
    }

    if (isLeapYear)
        printf("It's a leap year!");
    else
        printf("Not a leap year.");
}

// Ex 21.
void printNumbers() {
    for (int i = 1; i < 21; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // print odd numbers
    for (int i = 1; i < 21; i+=2) {
        printf("%d ", i);
    }
    printf("\n");

    // print even numbers
    for (int i = 2; i < 21; i+=2) {
        printf("%d ", i);
    }
    printf("\n");
}

// Ex. 22
void codeTable() {
    char small, capital;

    printf("Letter | Small | Capital\n");
    printf("-------+-------+--------");

    for (small = 'a', capital = 'A'; small <= 'z'; small++, capital++) {
        printf("\n   %c   |  %3d  |  %3d ", small, small, capital);
    }
}

// Ex 23.
void binaryWeights2() {
    int weight = 1;

    for (int i = 1; i <= 8; i++) {
        printf("2 ^ %d = %d \n", i, weight*=2);
    }
}

// Ex 26.
void leibnizSeries() {

}

// Ex 27.
void mathSeries() {
    double sum = 0.0, summand = 1, delta = 1.0e-10;
    int summandCount = 0;

    while (summand > delta) {
        sum += summand;
        summand = summand * 0.5;
        summandCount += 1;
    }

    printf("Approximate sum: %.11f\n", sum);
    printf("Summands added: %3d\n", summandCount);
    printf("Stopped at: %.1e\n", delta);
}

// Ex 28.
void bisectionMethod() {

}


int main(void) {
    mathSeries();
}