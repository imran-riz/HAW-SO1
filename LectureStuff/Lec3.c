#include <stdio.h>

void divisionByDifferentTypes() {
    int n1 = 100;
    double n2 = 20.5;
    int n3 = 5;

    printf("int n1/ double n2 = %f", n1/n2);
    printf("\ndouble n2 / int n3 = %f", n2/n3);
}


void relationalOperators() {
    int a = 7, b = 4;
    int paranthesis = (a > b) == (a <= b);          // simplifies to: T == F -> F

    printf("true: %d \n", 1==1);
    printf("false: %d \n", 1!=1);
    printf("paranthesis: %d \n", paranthesis);
    printf("Precedence: %d \n", a > b == a <= b);
}


int main(void) {
    relationalOperators();
    return 0;
}