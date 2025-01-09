#include <stdio.h>

void dataSizes();
void dataTypes();

int main(void)
{
    dataTypes();
    return 0;
}


/*
 *  A program to determine the size of the data types char and int in standard bytes.
 */
void dataSizes()
{
    char charArr[] = {'a', 'b'};
    int intArr[] = {0, 1};
    unsigned long sizeChar, sizeInt;

    printf("Address of charArr[0]: %p \n", charArr);       // equivalent to &charArr[0]
    printf("Address of charArr[1]: %p \n", charArr+1);     // equivalent to &charArr[1]

    sizeChar = (unsigned long) charArr+1 - (unsigned long) charArr;
    printf("Size of char = %lu bytes \n", sizeChar);

    printf("\nAddress of intArr[0]: %p \n", &intArr[0]);
    printf("Address of intArr[1]: %p \n", &intArr[1]);

    sizeInt = (unsigned long) &intArr[1] -  (unsigned long) &intArr[0];
    printf("Size of int = %lu bytes \n", sizeInt);

}

/*
 *  Updating the value held at every byte of a variable's address
 *  This can only be done using char pointers
 *
 *  A unsigned is typically 4 bytes long
 *  When you print the address of an unsigned variable, it will only show the address of the first byte.
 *  However, we can access all 4 bytes individually and change their values
 */
void dataTypes()
{
    unsigned value = 0;
    unsigned *valuePointer = &value;
    char *valuePointerChar = (char *) &value;

    printf("valuePointer = %p \n", valuePointer);
    printf("valuePointerChar = %p \n", valuePointerChar);

    for (int byte = 0; byte < sizeof value; byte++)
    {
        // update the value held at that byte to be 1
        *(valuePointerChar + byte) = 1;
        printf("Set byte %d at address %p to 1: %u \n", byte+1, valuePointerChar+byte, value);
        value = 0;
    }
}
