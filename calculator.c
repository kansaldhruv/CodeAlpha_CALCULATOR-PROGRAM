#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void clearInputBuffer();

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        
        // Validate if input is a valid integer
        if (scanf("%d", &choice) != 1) {
            printf("\n[!] Invalid input! Please enter a number between 1 and 5.\n");
            clearInputBuffer();
            continue;
        }

        // Exit condition
        if (choice == 5) {
            printf("\nThank you for using the CodeAlpha Calculator. Goodbye!\n");
            break;
        }

        // Check for out-of-range choices
        if (choice < 1 || choice > 5) {
            printf("\n[!] Error: Invalid choice. Please try again.\n");
            continue;
        }

        // Get numbers from user
        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("[!] Invalid number format.\n");
            clearInputBuffer();
            continue;
        }

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("[!] Invalid number format.\n");
            clearInputBuffer();
            continue;
        }

        // Perform calculation using switch case
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\n>>> Result: %.4lf + %.4lf = %.4lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("\n>>> Result: %.4lf - %.4lf = %.4lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("\n>>> Result: %.4lf * %.4lf = %.4lf\n", num1, num2, result);
                break;
            case 4:
                // Safe division check
                if (num2 == 0) {
                    printf("\n[!] Error: Division by zero is mathematically undefined.\n");
                } else {
                    result = num1 / num2;
                    printf("\n>>> Result: %.4lf / %.4lf = %.4lf\n", num1, num2, result);
                }
                break;
        }
    }

    return 0;
}

// Function to print a clean interface menu
void displayMenu() {
    printf("\n===================================\n");
    printf("         CALCULATOR        \n");
    printf("===================================\n");
    printf(" 1. Addition (+)\n");
    printf(" 2. Subtraction (-)\n");
    printf(" 3. Multiplication (*)\n");
    printf(" 4. Division (/)\n");
    printf(" 5. Exit\n");
    printf("-----------------------------------\n");
}

// Function to clean up bad inputs (like letters) so the program doesn't crash
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}