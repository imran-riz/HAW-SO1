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

// Ex 25
void bankAccount()
{
    const double RATE_PER_YEAR = 0.35;          // the % rate per year
    const double INITIAL_BALANCE = 1000;
    double current_balance = INITIAL_BALANCE;
    int year = 0;

    do {
        current_balance = current_balance + (current_balance * RATE_PER_YEAR/100);
        ++year;
    } while (current_balance < 2 * INITIAL_BALANCE);

    printf("\nGiven a rate of %.2f%% it will %d years for a balance of %.2f EUR to be doubled.", RATE_PER_YEAR, year, INITIAL_BALANCE);
    printf("\nBalance now = %.2f EUR", current_balance);
}

// Ex 26.
void leibnizSeries()
{

}

// Ex 27.
void mathSeries()
{

}

// Ex 28.
void bisectionMethod()
{

}


int main(void) {
    bankAccount();
}