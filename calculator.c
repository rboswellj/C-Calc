/*
Robert Johnson
CSE-130-50-4262
1/26/2026
Calculator
A Calculator program that can perform addition, subtraction, multiplication and division, as well as modulus and prime tests.
Only needs to be able to perform on 2 variables\

TODO:
Figure out how to confirm input in an integer for modulus and prime test functions
*/

#include <stdio.h>
#include <stdlib.h>


// Function to display the main menu and get user selection
int mainMenu(){
    int selection;
    int valid = 0;
    // Runs through loop once and then checks for valid input
    do {
        printf("Calculator Menu:\n");
        printf("\t(1) Addition\n");
        printf("\t(2) Subtraction\n");
        printf("\t(3) Multiplication\n");
        printf("\t(4) Division\n");
        printf("\t(5) Modulus\n");
        printf("\t(6) Test if Prime\n");
        printf("\t(7) Exit\n");
        printf("Please select an operation:");
        scanf("%d", &selection);
        // if selection not in valid range print the error and then go back to the top
        if (selection < 1 || selection > 7)
        {
            printf("\nInvalid selection. Please select a valid operation");
        } else {
            //if selection is valid flag to truthy value
            valid = 1;
        }
    } while (!valid);
    return selection;    
}

double collectFirstDouble() {
    double a;
    printf("Enter first number: ");
    scanf("%lf", &a);
    return a;
}

double collectSecondDouble() {
    double b;
    printf("Enter second number: ");
    scanf("%lf", &b);
    return b;
}

int testPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;        // 2 is prime
    if (n % 2 == 0) return 0;    // even numbers > 2 are not prime
    for (int i = 3; i * i <= n; i += 2) {  // only check odd numbers
        if (n % i == 0) return 0;
    }
    return 1;
}

void callOperation(int operation) {
    double a, b;
    int c,d;
    switch (operation) {
        case 1:
            // Addition
            a = collectFirstDouble();
            b = collectSecondDouble();
            printf("Result: %.2lf\n", a + b);
            break;
        case 2:
            // Subtraction
            a = collectFirstDouble();
            b = collectSecondDouble();
            printf("Result: %.2lf\n", a - b);
            break;
        case 3:
            // Multiplication
            a = collectFirstDouble();
            b = collectSecondDouble();
            printf("Result: %.2lf\n", a * b);
            break;
        case 4:
            // Division
            a = collectFirstDouble();
            b = collectSecondDouble();
            if (b == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                printf("Result: %.2lf\n", a / b);
            }
            break;
        case 5:
            // Modulus
            printf("Enter first integer: ");
            scanf("%d", &c);
            printf("\nEnter second integer: ");
            scanf("%d", &d);
            if (d == 0) {
                printf("Error: Division by zero is not allowed.\n");
                break;
            } else {
                printf("Result: %d\n", c % d);
            }
            break;
        case 6:
            // Prime Test
            printf("Enter an integer to test for primality: ");
            scanf("%d", &c);
            if (testPrime(c)) {
                printf("%d is prime.\n", c);
            } else {
                printf("%d is not prime.\n", c);
            }
            break;
        case 7:
            // Exit
            exit(0);
        default:
            printf("Invalid operation selected.\n");
            break;
    }
}

int main() {
    int notExit = 1;
    char continueChoice;

    do {
        // set the operation value by calling the mainMenu function
        int operationSelection = mainMenu();
        printf("You selected operation %d\n", operationSelection);

        // Calls switch function that launches the proper operation
        callOperation(operationSelection);
        printf("\n");
        printf("Would you like to perform another operation? (<y/n>): ");
        scanf(" %c", &continueChoice);
        if (continueChoice == 'n' || continueChoice == 'N') {
            notExit = 0;
            printf("Exiting calculator. Goodbye!\n");
            break;
        } else if (continueChoice != 'y' && continueChoice != 'Y') {
            printf("Invalid choice. Exiting calculator. Goodbye!\n");
            break;
        }
        printf("====================================\n\n");
        printf("Returning to main menu...\n\n");
        
    } while (notExit);
    


    return 0;
}

