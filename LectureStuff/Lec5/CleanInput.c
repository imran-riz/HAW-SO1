/*
 * A program that with the following function:
 *      - User shall enter a sentence
 *      - Print cleaned user input to the console.
 *
 * Cleaning rules:
 *      - Not more than 1 adjacent space character
 *      - No space character at the beginning of the sentence
 *      - No space character left of a period
 */

#include <stdio.h>

void cleanInput();

int main(void)
{
    printf("Enter sentence (cleans spaces): ");
    cleanInput();

    return 0;
}

void cleanInput()
{
    char current, last = '\n';
    int isDoubleSpace, isLeadingSpace;

    while ((current = getchar()) != '\n')  // getchar used as it reads one char at a time from the input buffer
    {
        isDoubleSpace = last == ' ' && current == ' ';
        isLeadingSpace = last == '\n' && current == ' ';

        if (last == ' ' && current == '.')          // remove the space before the period
        {
            printf("\b.");
        }
        else if (!isDoubleSpace && !isLeadingSpace)         // ignore double and leading spaces
        {
            putchar(current);
        }

        last = current;
    }
}

/*
 * NOTE:
 *  - The output from the printf and putchar statements do not appear immediately.
 *  - Instead, it will only appear after I hit enter during my input.
 *  - This is because of "line buffering."
 *  - Functions like getchar and printf use buffers to improve efficiency.
 *  - They collect input/output in memory until a newline (\n) is encountered, the buffer is full,
 *    or the program explicitly flushes the buffer.
 *  - Output from printf and putchar is stored in the output buffer. This buffer is flushed (printed to the screen)
 *    when:
        A newline (\n) is printed.
        The program terminates.
        The buffer is explicitly flushed using fflush(stdout);.
 */