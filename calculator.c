/*
Robert Johnson
CSE-130-50-4262
1/26/2026
Calculator
A Calculator program that can perform addition, subtraction, multiplication and division,
as well as modulus and prime tests.
Only needs to be able to perform on 2 variables.

*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes for UI
int mainMenu(); // Function to display main menu and get user selection
void callOperation(int operation); // Function to call the appropriate operation
int getIntInput(const char *prompt); // Function to get integer input, or modulus, prime test, exponent, and factorial. Validates input.
double getDoubleInput(const char *prompt);// Used to prompt for double input on all operations that allow for decimal input. Validates input.
void printHeader(char *operation); // Function to print operation header formatting
void printOutputDouble(double result); // Function to print output formatting
void printOutputInt(int result); // Function to print output formatting for integer results
void divisionByZeroError(); // Function to print division by zero error message

// Function prototypes for operations
double add(double a, double b); // Function to perform addition
double subtract(double a, double b); // Function to perform subtraction
double multiply(double a, double b); // Function to perform multiplication
double divide(double a, double b); // Function to perform division
int modulus(int a, int b); // Function to perform modulus operation
int isPrime(int n); // Function to test if a number is prime
unsigned long long factorial(int n); // Function to compute factorial of a number, using unsigned long long to allow for larger results since cannot be negative
long long exponent(int base, int exp); // Function to compute base raised to the exp power, remains signed to allow for negatives
void pascalsTriangle(int rows); // Function to print Pascal's triangle up to a given number of rows

int main()
{
    int notExit = 1; // flag to control main loop
    char continueChoice; // variable to store user choice to continue or exit

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

        // Exit if the selection is n or N, or if the input is invalid
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

/* UI */

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
        printf("====================================\n");
        printf("\t(5) Modulus\n");
        printf("\t(6) Test if Prime\n");
        printf("\t(7) Factorial\n");
        printf("\t(8) Exponentiation\n");
        printf("\t(9) Pascal's Triangle\n");
        printf("====================================\n");
        printf("\t(0) Exit\n\n");
        printf("Please select an operation: ");
        selection = getIntInput("Select an operation: ");
        // if selection not in valid range print the error and then go back to the top
        if (selection < 0 || selection > 9)
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
        a = getDoubleInput("Enter first number: ");
        b = getDoubleInput("Enter second number: ");
        printOutputDouble(add(a,b));
        break;
    case 2:
        // Subtraction
        printHeader("Subtraction");
        a = getDoubleInput("Enter first number: ");
        b = getDoubleInput("Enter second number: ");
        printOutputDouble(subtract(a,b));
        break;
    case 3:
        // Multiplication
        printHeader("Multiplication");
        a = getDoubleInput("Enter first number: ");
        b = getDoubleInput("Enter second number: ");
        printOutputDouble(multiply(a,b));
        break;
    case 4:
        // Division
        printHeader("Division");
        a = getDoubleInput("Enter first number: ");
        b = getDoubleInput("Enter second number: ");
        if (b == 0)
        {
            divisionByZeroError();
        }
        else
        {
            printOutputDouble(divide(a,b));
        }
        break;
    case 5:
        // Modulus
        printHeader("Modulus (Whole Numbers Only)");
        c = getIntInput("Enter first integer: ");
        d = getIntInput("Enter second integer: ");
        if (d == 0)
        {
            divisionByZeroError();
            break;
        }
        else
        {
            printOutputInt(modulus(c,d));
        }
        break;
    case 6:
        printHeader("Prime Test (Whole Numbers Only)");
        c = getIntInput("Enter an integer to test for primality: ");
        if (isPrime(c)) // if the function returns 1, it is prime
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
        // Factorial
        printHeader("Factorial (Whole Numbers Only)");
        c = getIntInput("Enter an integer for factorial computation: ");
        do {
            if(c < 0){
                printf("Error: Factorial is not defined for negative numbers. Please enter a non-negative integer: ");
                scanf("%d", &c);
            }
        } while (c < 0);
        printOutputInt(factorial(c));
        break;
    case 8:
        // Exponentiation
        printHeader("Exponentiation (Whole Numbers Only)");
        c = getIntInput("Enter the base integer: ");
        d = getIntInput("Enter the exponent (non-negative integer): ");
        do{
            if(d < 0){
                printf("Error: Exponentiation function only accepts non-negative integers for the exponent. Please enter a non-negative integer: ");
                scanf("%d", &d);
            }
        } while (d < 0);
        printOutputInt(exponent(c,d));
        break;
    case 9:
        // Pascal's Triangle
        c = getIntInput("Enter the number of rows of Pascal's triangle to display(between 2 and 12): ");
        do{
            if(c < 2 || c > 12){
                c = getIntInput("Error: Please enter an integer between 2 and 12: ");
            }
        } while (c < 2 || c > 12);
        pascalsTriangle(c);
        break;
    case 0:
        // Exit
        printf("Exiting calculator. Goodbye!\n");
        exit(0);
        break;
    default:
        printf("Invalid operation selected.\n");
        break;
    }
}

// Used to prompt for integer input on modulus, prime test, exponent, and factorial operations. Validates input.
int getIntInput(const char *prompt)
{
    char buffer[100];
    char *endptr;
    long value;

    while (1)
    {
        printf("%s", prompt);

        if (!fgets(buffer, sizeof(buffer), stdin))
            continue;

        value = strtol(buffer, &endptr, 10);

        /* 
           Invalid if:
           - no digits were read
           - leftover characters (like .5 or abc)
        */
        if (endptr == buffer || *endptr != '\n')
        {
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }

        return (int)value;
    }
}
// Used to prompt for double input on all operations that allow for decimal input. Validates input.
double getDoubleInput(const char *prompt)
{
    char buffer[100];
    char *endptr;
    double value;

    while (1)
    {
        printf("%s", prompt);

        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            printf("Input error.\n");
            continue;
        }

        // Ignore empty input (just Enter)
        if (buffer[0] == '\n')
            continue;

        value = strtod(buffer, &endptr);

        /*
          Invalid if:
          - no number was read
          - extra characters remain (like abc)
        */
        if (endptr == buffer || *endptr != '\n')
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        return value;
    }
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
void printOutputDouble(double result)
{
    printf("\n");
    printf("====================================\n\n");
    printf("Result: %lf\n\n", result);
    printf("====================================\n\n");
    printf("\n");
}
// Function to print output formatting for integer results
void printOutputInt(int result)
{
    printf("\n");
    printf("====================================\n\n");
    printf("Result: %d\n\n", result);
    printf("====================================\n\n");
    printf("\n");
}

void divisionByZeroError()
{
    printf("\n");
    printf("====================================\n");
    printf("Error: Division by zero is not allowed.\n");
    printf("====================================\n");
    printf("\n");
}

/* OPERATIONS */

// Function to perform addition
double add(double a, double b)
{
    return a + b;
}
// Function to perform subtraction
double subtract(double a, double b)
{
    return a - b;
}
// Function to perform multiplication
double multiply(double a, double b)
{
    return a * b;
}
// Function to perform division
double divide(double a, double b)
{
    return a / b;
}
// Function to perform modulus operation
int modulus(int a, int b)
{
    return a % b;
}

// Function to test if a number is prime
int isPrime(int n)
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

// Function to compute factorial of a number
unsigned long long factorial(int n){
    // Must be positive integer
    if(n < 0){
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 0;
    }
    // Factorial of 0 is 1 so result starts from 1
    unsigned long long result = 1;
    // Multiply result by each integer up to n
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    // return factorial result
    return result;
}

long long exponent(int base, int exp){
    // Initialize result to 1
    int result = 1;
    // Multiply result by base exp times
    for(int i = 0; i < exp; i++){
        result *= base;
    }
    return result;
}

void pascalsTriangle(int rows)
{
    int triangle[20][20];   // 2D array to store values
    int i, j, s;

    // Build the triangle and STORE values in the array
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                triangle[i][j] = 1; // First and last value in each row is 1
            }
            else
            {
                // Each value is the sum of the two values directly above it in the previous row
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; 
            }
        }
    }

    // Print the triangle with spacing
    printf("\nPascal's Triangle:\n");
    for (i = 0; i < rows; i++)
    {
        // Print leading spaces to center the row
        for (s = 0; s < rows - i - 1; s++)
        {
            printf("  ");
        }

        // Print row values
        for (j = 0; j <= i; j++)
        {
            printf("%4d", triangle[i][j]);
        }

        printf("\n");
    }
}
