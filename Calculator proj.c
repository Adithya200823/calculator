#include <stdio.h>
#include <math.h>

#define MAX_HISTORY 5

double getNumber(const char *prompt) {
    double n;
    while (printf("%s", prompt), scanf("%lf", &n) != 1) {
        printf("Invalid input! Enter a number.\n");
        while (getchar() != '\n');
    }
    return n;
}

void showMenu(void) {
    printf("\n===== SMART CALCULATOR =====\n");
    printf("1. Add        2. Subtract\n");
    printf("3. Multiply   4. Divide\n");
    printf("5. Modulus    6. Power\n");
    printf("7. Square Root 8. History\n");
    printf("0. Exit\n");
}

int main(void) {
    int choice, count = 0;
    double a, b, result;
    char history[MAX_HISTORY][50];

    do {
        showMenu();
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }
        if (choice == 0) break;
        if (choice == 8) {
            for (int i = 0; i < count && i < MAX_HISTORY; i++) printf("%d) %s\n", i + 1, history[i]);
            if (count == 0) printf("No history yet.\n");
            continue;
        }
        if (choice < 1 || choice > 7) { printf("Invalid choice!\n"); continue; }

        a = getNumber("Enter first number: ");
        if (choice != 7) b = getNumber("Enter second number: ");
        char entry[50];
        switch (choice) {
            case 1: result = a + b; snprintf(entry, 50, "%.2f + %.2f = %.2f", a, b, result); break;
            case 2: result = a - b; snprintf(entry, 50, "%.2f - %.2f = %.2f", a, b, result); break;
            case 3: result = a * b; snprintf(entry, 50, "%.2f * %.2f = %.2f", a, b, result); break;
            case 4:
                if (b == 0) { printf("Error: Division by zero!\n"); continue; }
                result = a / b; snprintf(entry, 50, "%.2f / %.2f = %.2f", a, b, result); break;
            case 5:
                if (b == 0) { printf("Error: Modulus by zero!\n"); continue; }
                result = fmod(a, b); snprintf(entry, 50, "%.2f %% %.2f = %.2f", a, b, result); break;
            case 6: result = pow(a, b); snprintf(entry, 50, "%.2f ^ %.2f = %.2f", a, b, result); break;
            case 7:
                if (a < 0) { printf("Error: Negative number!\n"); continue; }
                result = sqrt(a); snprintf(entry, 50, "sqrt(%.2f) = %.2f", a, result); break;
        }
        printf("Result = %.2f\n", result);
        if (count < MAX_HISTORY) snprintf(history[count++], 50, "%s", entry);
    } while (1);

    printf("Thank you for using Smart Calculator!\n");
    return 0;
}
