#include <stdio.h>

void divisionByDifferentTypes() {
    int n1 = 100;
    double n2 = 20.5;
    int n3 = 5;

    printf("int n1/ double n2 = %f", n1/n2);
    printf("\ndouble n2 / int n3 = %f", n2/n3);
}



int main(void) {
    divisionByDifferentTypes();
    return 0;
}