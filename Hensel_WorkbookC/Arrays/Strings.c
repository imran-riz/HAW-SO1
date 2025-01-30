#include <stdio.h>

int countLetter(char text[], int size, char ltr);
void textStatistics(char text[], int size);
void displayArr(char arr[], int size);

int main(void) {
    char text[256];
    char ltr = 'l';
    int elementCount = 0;

    printf("Enter some text: ");
    scanf("%s", text);          // reads until the next whitespace (space, tab, new line), which is excluded

    elementCount = sizeof(text) / sizeof(text[0]);

    printf("\nText checked: \"%s\"", text);
    printf("\n\nChar to find: %c", ltr);
    printf("\nOccurrences: %d", countLetter(text, elementCount, ltr));

    printf("\n");
    // textStatistics(text, elementCount);

    return 0;
}

/*!
 * Counts the number of times a specific character is in a given string
 */
int countLetter(char text[], int size, char ltr)
{
    int ltrCount = 0;

    for (int i = 0; i < size; ++i)
    {
        ltrCount += (text[i] == ltr);
    }


    return ltrCount;
}

/**
 * Counts the number of lowercase letters, uppercase letters, digits and
 * other symbols in a given string
 */
void textStatistics(char text[], int size)
{
    int lower = 0, upper = 0, digits = 0, other = 0;

    for (int i = 0; i < size; ++i)
    {
        if (text[i] == ' ') continue;       // ignore spaces

        if (text[i] >= 'a' && text[i] <= 'z')
            ++lower;
        else if (text[i] >= 'A' && text[i] <= 'Z')
            ++upper;
        else if (text[i] >= '0' && text[i] <= '9')
            ++digits;
        else if (text[i] != '\0')       // ignore the end of line char '\0' and count as other symbol
            ++other;
    }

    printf("\nLowercase: %d", lower);
    printf("\nUppercase: %d", upper);
    printf("\nDigits: %d", digits);
    printf("\nOther symbols: %d", other);
}


void displayArr(char arr[], int size)
{
    printf("\n[");

    for (int i = 0; i < size; ++i)
        printf("\'%c\'%c ", arr[i], i != size-1 ? ',' : ' ');

    printf("]");
}