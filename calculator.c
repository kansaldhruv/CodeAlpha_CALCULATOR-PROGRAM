#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 128

static void showMenu(void);
static int readInt(const char *prompt, int *value);
static int readDouble(const char *prompt, double *value);

int main(void) {
    int choice;
    double first;
    double second;
    double result;

    for (;;) {
        showMenu();

        if (!readInt("Choose an option (1-5): ", &choice)) {
            puts("Invalid choice. Please enter a number from 1 to 5.");
            continue;
        }

        if (choice == 5) {
            puts("Goodbye.");
            break;
        }

        if (choice < 1 || choice > 5) {
            puts("Please select a valid option.");
            continue;
        }

        if (!readDouble("Enter the first number: ", &first)) {
            puts("That is not a valid number.");
            continue;
        }

        if (!readDouble("Enter the second number: ", &second)) {
            puts("That is not a valid number.");
            continue;
        }

        switch (choice) {
            case 1:
                result = first + second;
                printf("Result: %.2f + %.2f = %.2f\n", first, second, result);
                break;
            case 2:
                result = first - second;
                printf("Result: %.2f - %.2f = %.2f\n", first, second, result);
                break;
            case 3:
                result = first * second;
                printf("Result: %.2f * %.2f = %.2f\n", first, second, result);
                break;
            case 4:
                if (second == 0.0) {
                    puts("Division by zero is not allowed.");
                    break;
                }

                result = first / second;
                printf("Result: %.2f / %.2f = %.2f\n", first, second, result);
                break;
            default:
                puts("Please select a valid option.");
                break;
        }
    }

    return 0;
}

static void showMenu(void) {
    puts("");
    puts("====================");
    puts("    Calculator");
    puts("====================");
    puts("1. Add");
    puts("2. Subtract");
    puts("3. Multiply");
    puts("4. Divide");
    puts("5. Exit");
}

static int readInt(const char *prompt, int *value) {
    char buffer[INPUT_SIZE];
    char *end;
    long parsed;

    fputs(prompt, stdout);

    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return 0;
    }

    errno = 0;
    parsed = strtol(buffer, &end, 10);

    if (buffer == end) {
        return 0;
    }

    while (*end == ' ' || *end == '\t' || *end == '\n') {
        end++;
    }

    if (errno != 0 || *end != '\0') {
        return 0;
    }

    *value = (int)parsed;
    return 1;
}

static int readDouble(const char *prompt, double *value) {
    char buffer[INPUT_SIZE];
    char *end;
    double parsed;

    fputs(prompt, stdout);

    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return 0;
    }

    errno = 0;
    parsed = strtod(buffer, &end);

    if (buffer == end) {
        return 0;
    }

    while (*end == ' ' || *end == '\t' || *end == '\n') {
        end++;
    }

    if (errno != 0 || *end != '\0') {
        return 0;
    }

    *value = parsed;
    return 1;
}
