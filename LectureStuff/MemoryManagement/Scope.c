#include <stdio.h>

void knowWho();

void dontKnowWho()
{
    // printf("Who? %s", who);     // does not know who
}

char *who = "It's me, Mario!";      // file scope variable

int main(void)
{
    printf("\nI know who: %s", who);        // works
    dontKnowWho();
    knowWho();

    int max = 10;       // block scope until end of main

    printf("\n");
    for (int counter = 0; counter < max; ++counter)     // counter - block scope until end of for loop
        printf("%d ", counter);

    printf("%d", max);

    return 0;
}

void knowWho()
{
    printf("\nMe too: %s", who);
}