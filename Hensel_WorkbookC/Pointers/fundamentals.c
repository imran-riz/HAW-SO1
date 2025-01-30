#include <stdio.h>

void simplePointer();

int main(void)
{
    simplePointer();
    return 0;
}

void simplePointer()
{
    int value = 0;
    int *valuePointer = &value;

    printf("value: %d \n", value);          // 0
    value++;
    printf("value++: %d \n", value);            // 1

    printf("\nPointer access only\n");
    printf("Access value: %d \n", *valuePointer);      // 1
    *valuePointer = *valuePointer + 1;
    printf("value + 1: %d \n", *valuePointer);       // 2
    (*valuePointer)++;
    printf("value + 1: %d \n", *valuePointer);       // 3
}

/*
 *  Ex 59 - bisection
 */
void bisection()
{

}