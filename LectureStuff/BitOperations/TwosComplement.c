#include <stdio.h>

int main(void)
{
    int x = 9;

    printf("Change the sign once (one's complement): \n");
    printf("% hhd -> % hhd \n", x, ~x);
    printf("Change the sign twice (two's complement): \n");
    printf("% hhd -> % hhd \n", ~x, ~x+1);

    return 0;
}