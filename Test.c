#include <stdio.h>
#include <limits.h>

void printBinary(unsigned int n);

int main(void)
{
    unsigned int x = UINT_MAX; // 0000 0110
    unsigned int z = (x << 1) >> 1;

    printf("x = %u\n", x);
    printf("z = %u\n", z);

    printBinary(x);
    printBinary(z);

    return 0;
}

void printBinary(unsigned int n)
{
    for (int i = sizeof(n) * CHAR_BIT - 1; i >= 0; i--)
    {
        unsigned int mask = 1u << i;
        printf("%u", (n & mask) ? 1 : 0);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}