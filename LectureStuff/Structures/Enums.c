#include <stdio.h>

void months();

int main(void)
{
    enum month {
        JAN, FEB, MAR, APR, MAY, JUN, JUL,
        AUG, SEP, OCT, NOV, DEC,
    };

    char *monthNames[12] =  {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    // printing out the names of the months
    for (int i = JAN; i <= DEC; ++i)
        printf("%-10s: %d \n", monthNames[i], i);


    printf("\n\n");
    typedef enum month month;

    struct date {
        int year;
        month month;
        int dayOfMonth;
    };

    typedef struct date date;

    date alisaBirth = { 2004, DEC, 11};
    printf("Alisa's birthdate is in %s \n", monthNames[alisaBirth.month]);



    return 0;
}


void months()
{
}