/**
 *  A program that will check the user's input string to see if it contains
 *  any word from a quote.
 */

#include <stdio.h>

int main(void)
{
    char word[256];
    char quote[] = "Life is what happens while you are busy making other plans.";
    int size = sizeof quote / sizeof quote[0];
    int substringStartsAt = -1;

    printf("The quote is \"%s\"", quote);
    printf("\nEnter a word: ");
    scanf("%s", word);
    // while (getchar() != '\n')           // discard the rest of the keyboard input
    //     continue;

    for (int i = 0; i < size; ++i)
    {
        // if the 1st character of the substring is found,
        // store its index
        if (substringStartsAt == -1 && quote[i] == word[0])
            substringStartsAt = i;

        // if we have a partially matching substring
        if (substringStartsAt != -1)
        {
            // break if we reached the end of the word
            if (word[i - substringStartsAt] == '\0')
                break;

            // if a different character is found
            if (quote[i] != word[i - substringStartsAt])
            {
                i = substringStartsAt;
                substringStartsAt = -1;     // mark that we have not found a potential starting index for a substring
            }
        }
    }

    if (substringStartsAt != -1)
        printf("\nThe string contains \"%s\" at index %d.", word, substringStartsAt);
    else
        printf("\nThe string does contain the substring \"%s\".", word);


    return 0;
}
