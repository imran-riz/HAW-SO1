#include <stdio.h>

int main() {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("Base address: %p\n", (void*)arr);
    printf("arr[0][0]: %p\n", (void*)&arr[0][0]);
    printf("arr[0][1]: %p\n", (void*)&arr[0][1]);
    printf("arr[0][2]: %p\n", (void*)&arr[0][2]);
    printf("arr[1][0]: %p\n", (void*)&arr[1][0]);
    printf("arr[1][1]: %p\n", (void*)&arr[1][1]);
    printf("arr[1][2]: %p\n", (void*)&arr[1][2]);

    arr[0][0] = 9;
    arr[0][1] = 8;
    arr[0][2] = 7;
    arr[1][0] = 9;
    arr[1][1] = 8;
    arr[1][2] = 7;

    return 0;
}
