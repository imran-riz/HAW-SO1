#include <stdio.h>

/*
   A simple  project to refresh my C programming skills.

   This program is a simple calculator that can perform the following operations:
   - Addition
   - Subtraction
   - Multiplication
   - Division

   Each operation is performed by a separate function.

   The program should display a menu to the user, allowing them to choose the operation they want to perform.

   The program should then prompt the user to enter the two numbers on which the operation will be performed.
   - The numbers can be integers or floating-point numbers.
   - The result should be shown with only two decimal places.
   - The program should handle division by zero.

*/


void displayMenu() {
   printf("Calculator Menu\n");
   printf("1. Addition\n");
   printf("2. Subtraction\n");
   printf("3. Multiplication\n");
   printf("4. Division\n");
   printf("0. Exit\n");
}


float division(float num1, float num2) {
   if (num2 == 0) {
      printf("Error: Division by zero.\n");
      return 0;
   }
   return num1 / num2;
}


int main(void) {
   int choice;
   float num1, num2;

   displayMenu();

   do {
      printf("Enter your choice: ");
      scanf("%d", &choice);

      if (choice < 0 || choice > 4) {
         printf("Invalid choice. Please enter a number between 0 and 4.\n");
      }
      else if (choice == 0) {
         printf("Goodbye, human!\n");
      }
      else {
         printf("Enter the first number: ");
         scanf("%f", &num1);
         printf("Enter the second number: ");
         scanf("%f", &num2);

         switch (choice) {
            case 1:
               printf("Result: %.2f\n", num1 + num2);
               break;
            case 2:
               printf("Result: %.2f\n", num1 - num2);
               break;
            case 3:
               printf("Result: %.2f\n", num1 * num2);
               break;
            case 4:
               printf("Result: %.2f\n", division(num1, num2));
               break;
         }

         printf("\n");
         displayMenu();
      }

   } while (choice != 0);

   return 0;
}