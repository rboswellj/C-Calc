/*
Robert Johnson
CSE-130-50-4262
1/26/2026
Calculator
A Calculator program that can perform addition, subtraction, multiplication and division,
as well as modulus and prime tests.
Only needs to be able to perform on 2 variables.

TODO:
Figure out how to confirm input in an integer for modulus and prime test functions
Figure out how to confirm input in a double for other functions
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int mainMenu();
double collectFirstDouble();
double collectSecondDouble();
int testPrime(int n);
void printHeader(char *operation);
void printOutput(double result);
void callOperation(int operation);

int main()
{
    int notExit = 1;
    char continueChoice;

    do
    {
        // set the operation value by calling the mainMenu function
        int operationSelection = mainMenu();

        // Calls switch function that launches the proper operation
        callOperation(operationSelection);
        printf("\n");

        // Ask user if they want to continue or exit
        printf("Would you like to perform another operation? (<y/n>): ");
        scanf(" %c", &continueChoice);
        if (continueChoice == 'n' || continueChoice == 'N')
        {
            notExit = 0;
            printf("Exiting calculator. Goodbye!\n");
            break;
        }
        else if (continueChoice != 'y' && continueChoice != 'Y')
        {
            printf("Invalid choice. Exiting calculator. Goodbye!\n");
            break;
        }
        printf("\n");
        printf("====================================\n\n");
        printf("Returning to main menu...\n\n");

    } while (notExit);

    return 0;
}

// Function to display the main menu and get user selection
int mainMenu()
{
    int selection;
    int valid = 0;
    // Runs through loop once and then checks for valid input
    do
    {
        printf("\n");
        printf("Calculator Menu:\n\n");
        printf("\t(1) Addition\n");
        printf("\t(2) Subtraction\n");
        printf("\t(3) Multiplication\n");
        printf("\t(4) Division\n");
        printf("\t(5) Modulus\n");
        printf("\t(6) Test if Prime\n");
        printf("\t(7) Exit\n\n");
        printf("Please select an operation: ");
        scanf("%d", &selection);
        // if selection not in valid range print the error and then go back to the top
        if (selection < 1 || selection > 7)
        {
            printf("\nInvalid selection. Please select a valid operation\n");
        }
        else
        {
            // if selection is valid flag to truthy value
            valid = 1;
        }
    } while (!valid);
    return selection;
}

// Used to prompt for first double input on all operations except modulus and prime test
double collectFirstDouble()
{
    double a;
    printf("Enter first number: ");
    scanf("%lf", &a);
    return a;
}

// Used to prompt for second double input on all operations except modulus and prime test
double collectSecondDouble()
{
    double b;
    printf("Enter second number: ");
    scanf("%lf", &b);
    return b;
}

// Function to test if a number is prime
int testPrime(int n)
{
    if (n <= 1)
        return 0; // numbers less than or equal to 1 are not prime
    if (n == 2)
        return 1; // 2 is prime
    if (n % 2 == 0)
        return 0; // even numbers > 2 are not prime
    for (int i = 3; i * i <= n; i += 2)
    { // only check odd numbers. Check up to sqrt(n)
        if (n % i == 0)
            return 0; // found a divisor, not prime
    }
    return 1; // no divisors found, is prime
}

// Function to print operation header formatting
void printHeader(char *operation)
{
    printf("\n");
    printf("====================================\n\n");
    printf("You selected %s\n\n", operation);
    printf("====================================\n\n");
    printf("Please enter your number(s)\n\n");
}

// Function to print output formatting
void printOutput(double result)
{
    printf("\n");
    printf("====================================\n\n");
    printf("Result: %lf\n\n", result);
    printf("====================================\n\n");
    printf("\n");
}

// Function to call the appropriate operation based on user selection
void callOperation(int operation)
{
    double a, b;
    int c, d;
    switch (operation)
    {
    case 1:
        // Addition
        printHeader("Addition");
        a = collectFirstDouble();
        b = collectSecondDouble();
        printOutput(a + b);
        break;
    case 2:
        // Subtraction
        printHeader("Subtraction");
        a = collectFirstDouble();
        b = collectSecondDouble();
        printOutput(a - b);
        break;
    case 3:
        // Multiplication
        printHeader("Multiplication");
        a = collectFirstDouble();
        b = collectSecondDouble();
        printOutput(a * b);
        break;
    case 4:
        // Division
        printHeader("Division");
        a = collectFirstDouble();
        b = collectSecondDouble();
        if (b == 0)
        {
            printf("\n");
            printf("====================================\n");
            printf("Error: Division by zero is not allowed.\n");
            printf("====================================\n");
            printf("\n");
        }
        else
        {
            printOutput(a / b);
        }
        break;
    case 5:
        // Modulus
        printHeader("Modulus (Whole Numbers Only)");
        printf("Enter first integer: ");
        scanf("%d", &c);
        printf("\nEnter second integer: ");
        scanf("%d", &d);
        if (d == 0)
        {
            printf("\n");
            printf("====================================\n");
            printf("Error: Division by zero is not allowed.\n");
            printf("====================================\n");
            printf("\n");
            break;
        }
        else
        {
            printf("\n");
            printf("====================================\n\n");
            printf("Result: %d\n\n", c % d);
            printf("====================================\n\n");
            printf("\n");
        }
        break;
    case 6:
        printHeader("Prime Test (Whole Numbers Only)");
        printf("Enter an integer to test for primality: ");
        scanf("%d", &c);
        if (testPrime(c))
        {
            printf("\n");
            printf("====================================\n");
            printf("%d is prime.\n", c);
            printf("====================================\n\n");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("====================================\n");
            printf("%d is not prime.\n", c);
            printf("====================================\n\n");
            printf("\n");
        }
        break;
    case 7:
        // Exit
        printf("\n");
        printf("====================================\n\n");
        printf("You selected Exit\n\n");
        printf("====================================\n\n");
        printf("Exiting calculator. Goodbye!\n");
        exit(0);
    default:
        printf("Invalid operation selected.\n");
        break;
    }
}
