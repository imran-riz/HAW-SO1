#include <stdio.h>
#include <string.h>

int main(void)
{
    const int NAME_LENGTH = 50;

    // declaration of a struct, date
    struct date
    {
        int dayOfMonth;
        int month;
        int year;
        char name[NAME_LENGTH];
    };

    // declaring 2 struct variables of type date
    struct date birthSarah;

    // declaring and initialising birthAlisa
    struct date birthAlisa = {11, 12, 2004, "Alisa"};

    // initialising birthSarah
    birthSarah.year = 2005;
    birthSarah.month = 10;
    birthSarah.dayOfMonth = 1;
    // birthSarah.name = "Sarah";   // this does not work!
    strncpy(birthSarah.name, "Sarah", NAME_LENGTH);

    // displaying the birthdays
    printf("%s was born on %d-%2d-%2d \n", birthAlisa.name, birthAlisa.year, birthAlisa.month, birthAlisa.dayOfMonth);
    printf("%s was born on %d-%2d-%2d \n", birthSarah.name, birthSarah.year, birthSarah.month, birthSarah.dayOfMonth);

    return 0;
}