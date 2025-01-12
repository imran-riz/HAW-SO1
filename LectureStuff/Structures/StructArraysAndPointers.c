#include <stdio.h>

int main(void)
{
    const int SIZE = 3;
    struct name
    {
        char firstName[50];
        char lastName[50];
    };
    // declare and initialise an array of structs
    struct name people[SIZE] = {
        {"John", "Doe"},
        {"Peter", "Parker"},
        {"Harry", "Potter"}
    };

    // print out the names of the people
    for (int i = 0; i < SIZE; ++i)
        printf("%d - %s %s \n", i, people[i].firstName, people[i].lastName);


    printf("\n\n");

    // pointers to structs
    struct name name1 = {"James", "Bond"};
    struct name *name1Ptr = &name1;

    // access members using the struct pointer
    printf("name1Ptr->firstName: %s \n", name1Ptr->firstName);
    printf("(*name1Ptr).lastName: %s \n", (*name1Ptr).lastName);



    return 0;
}