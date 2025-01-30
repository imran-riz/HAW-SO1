#include <stdio.h>

void stringAnalysis(char *text, int *vowels, int *consonants, int *digits);

int main(void)
{
    int vowels = 0, consonants = 0, digits = 0;

    char *str = "HEllo 1234 5";
    stringAnalysis(str, &vowels, &consonants, &digits);

    printf("Text checked: %s \n", str);
    printf("Vowels: %d \n", vowels);
    printf("Consonants: %d \n", consonants);
    printf("Digits: %d \n", digits);

    return 0;
}


/*
 *  A function that determines the number of vowels, consonants and digits in a string
 */
void stringAnalysis(const char *text, int *vowels, int *consonants, int *digits)
{
    int isUpper = 0, isLower = 0;
    char ltr  = '';

    // while EOL is not reached
    while (*text != '\0')
    {
        // get the current letter and check if upper or lowercase
        ltr = *text;
        isUpper = ltr >= 'A' && ltr <= 'Z';
        isLower = ltr >= 'a' && ltr <= 'z';

        if (isUpper || isLower)
        {
            if (isUpper) ltr = ltr + ('a' - 'A');

            if (ltr == 'a' || ltr == 'e' || ltr == 'i' || ltr == 'o' || ltr == 'u')
                (*vowels)++;
            else
                (*consonants)++;
        }
        else if (ltr >= '0' && ltr <= '9')
        {
            (*digits)++;
        }

        // next letter
        text++;
    }
}