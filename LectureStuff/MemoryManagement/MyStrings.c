#include <stdio.h>
#include <stdlib.h>

int getStringLength(const char *str);
char* cloneString(const char *str);
char* concatStrings(const char *str1, const char *str2);

int main(void)
{
    char *string = "Hello";
    char *string2 = "World!";
    char *clonedString = cloneString(string);
    char *newString = concatStrings(string, string2);

    // if memory allocation was unsuccessful, then exit
    if (clonedString == NULL || newString == NULL)
    {
        printf("Failed to allocated memory! \n");
        exit(EXIT_FAILURE);
    }

    printf("Original string: \n %s \n Length = %d \n", string, getStringLength(string));
    printf("Cloned string: \n %s \n Length = %d \n", clonedString, getStringLength(clonedString));
    printf("New string: \n %s \n Length = %d \n", newString, getStringLength(newString));

    // free allocated memory
    free(clonedString);
    free(newString);

    return 0;
}

int getStringLength(const char *str)
{
    int charCount = 0;

    while (*str != '\0')
    {
        ++charCount;
        str++;
    }

    return charCount;
}

char* cloneString(const char *str)
{
    int elements = getStringLength(str);
    char *clone = (char *) malloc(elements * sizeof(char));

    if (clone != NULL)
    {
        for (int i = 0; i < elements; ++i)
            clone[i] = str[i];
    }

    return clone;
}

char* concatStrings(const char *str1, const char *str2)
{
    int str1Length = getStringLength(str1);
    int elements = str1Length + getStringLength(str2);
    char *newString = (char *) calloc(elements, sizeof(char));

    if (newString != NULL)
    {
        for (int i = 0; i < str1Length; ++i)
            newString[i] = str1[i];

        for (int i = str1Length; i < elements; ++i)
            newString[i] = str2[i - str1Length];
    }

    return newString;
}