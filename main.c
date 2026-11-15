#include <stdio.h>

int main() {
    int choice;
    char tryAgain;

    do {
        // Main Menu Display
        printf("\n=========================================\n");
        printf("      IT101 - PROGRAMMING 1 PORTFOLIO      \n");
        printf("       Multi-Tool Console Application      \n");
        printf("=========================================\n");
        printf("[1] The Pattern Generator\n");
        printf("[2] Pascal's Triangle\n");
        printf("[3] Grade Calculator & Evaluator\n");
        printf("[4] Palindrome Checker\n");
        printf("[5] Exit Program\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-5): ");
        
        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        // Handle menu selection using if-else statements
        if (choice == 1) {
            // ==========================================
            // MODULE 1: THE PATTERN GENERATOR
            // ==========================================
            int size, subChoice;
            printf("\n--- THE PATTERN GENERATOR ---\n");
            printf("Enter the size/height of the shape (positive numbers only): ");
            
            if (scanf("%d", &size) != 1 || size <= 0) {
                printf("\n[Error] Invalid size. Size must be a strictly positive integer (> 0).\n");
                while (getchar() != '\n');
            } else {
                printf("\nSelect Shape:\n");
                printf("[1] Right Triangle\n");
                printf("[2] Square\n");
                printf("[3] Isosceles Triangle\n");
                printf("[4] Inverted Right Triangle\n");
                printf("[5] Christmas Tree\n");
                printf("Enter choice (1-5): ");
                scanf("%d", &subChoice);

                if (subChoice == 1) { // Right Triangle
                    printf("\nRight Triangle:\n");
                    for (int i = 1; i <= size; i++) {
                        for (int j = 1; j <= i; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                } 
                else if (subChoice == 2) { // Square
                    printf("\nSquare (%dx%d):\n", size, size);
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                } 
                else if (subChoice == 3) { // Isosceles Triangle
                    printf("\nIsosceles Triangle:\n");
                    for (int i = 1; i <= size; i++) {
                        for (int j = i; j < size; j++) {
                            printf(" ");
                        }
                        for (int j = 1; j <= (2 * i - 1); j++) {
                            printf("*");
                        }
                        printf("\n");
                    }
                } 
                else if (subChoice == 4) { // Inverted Right Triangle
                    printf("\nInverted Right Triangle:\n");
                    for (int i = size; i >= 1; i--) {
                        for (int j = 1; j <= i; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                } 
                else if (subChoice == 5) { // Christmas Tree
                    printf("\nChristmas Tree:\n");
                    for (int t = 1; t <= 3; t++) {
                        int startRow = (t == 1) ? 1 : (t == 2) ? 2 : 3;
                        for (int i = startRow; i <= size; i++) {
                            for (int j = i; j < size + 2; j++) {
                                printf(" ");
                            }
                            for (int j = 1; j <= (2 * i - 1); j++) {
                                printf("*");
                            }
                            printf("\n");
                        }
                    }
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < size; j++) {
                            printf(" ");
                        }
                        printf("| |\n");
                    }
                } 
                else {
                    printf("Invalid sub-menu selection.\n");
                }
            }
        }
        else if (choice == 2) {
            // ==========================================
            // MODULE 2: PASCAL'S TRIANGLE
            // ==========================================
            int rows;
            printf("\n--- PASCAL'S TRIANGLE ---\n");
            printf("Enter the number of rows: ");
            if (scanf("%d", &rows) != 1 || rows < 0) {
                printf("Invalid number of rows.\n");
                while (getchar() != '\n');
            } else {
                printf("\nPascal's Triangle (%d rows):\n", rows);
                for (int i = 0; i < rows; i++) {
                    for (int space = 0; space < rows - i; space++) {
                        printf("  ");
                    }

                    long long val = 1;
                    for (int j = 0; j <= i; j++) {
                        printf("%4lld", val);
                        val = val * (i - j) / (j + 1);
                    }
                    printf("\n");
                }
            }
        }
        else if (choice == 3) {
            // ==========================================
            // MODULE 3: GRADE CALCULATOR & EVALUATOR
            // ==========================================
            float prelim, midterm, prefinal, finalGrade, average;
            
            printf("\n--- GRADE CALCULATOR & EVALUATOR ---\n");
            printf("Enter Prelim grade: ");
            scanf("%f", &prelim);
            printf("Enter Midterm grade: ");
            scanf("%f", &midterm);
            printf("Enter Pre-Final grade: ");
            scanf("%f", &prefinal);
            printf("Enter Final grade: ");
            scanf("%f", &finalGrade);

            average = (prelim + midterm + prefinal + finalGrade) / 4.0f;

            printf("\n-----------------------------------------\n");
            printf("Final Grade Average: %.2f%%\n", average);
            
            if (average >= 75.0f) {
                printf("Status Indicator: [ PASS ]\n");
            } else {
                printf("Status Indicator: [ FAIL ]\n");
            }
            printf("-----------------------------------------\n");
        }
        else if (choice == 4) {
            // ==========================================
            // MODULE 4: PALINDROME CHECKER
            // ==========================================
            char word[100];
            int length = 0;
            int isPalindrome = 1;
            int isValidWord = 1;
            
            printf("\n--- PALINDROME CHECKER ---\n");
            printf("Enter a single word (letters only): ");
            scanf("%s", word);

            // Calculate length and validate that every character is a letter (A-Z or a-z)
            while (word[length] != '\0') {
                char ch = word[length];
                if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
                    isValidWord = 0;
                    break;
                }
                length++;
            }

            if (!isValidWord || length == 0) {
                printf("\n[Error] Invalid input! Only alphabetical letters are allowed (no numbers or symbols).\n");
            } else {
                // Check if palindrome
                for (int i = 0; i < length / 2; i++) {
                    char leftChar = word[i];
                    char rightChar = word[length - i - 1];

                    // Convert to lowercase for case-insensitive check
                    if (leftChar >= 'A' && leftChar <= 'Z') leftChar += 32;
                    if (rightChar >= 'A' && rightChar <= 'Z') rightChar += 32;

                    if (leftChar != rightChar) {
                        isPalindrome = 0;
                        break;
                    }
                }

                printf("\nResult for \"%s\":\n", word);
                if (isPalindrome) {
                    printf("It is a PALINDROME! (Reads the same forwards and backwards)\n");
                } else {
                    printf("It is NOT a palindrome.\n");
                }
            }
        }
        else if (choice == 5) {
            printf("\nExiting program\n");
            return 0;
        }
        else {
            printf("\n[Error] Invalid choice. Please select between 1 and 5.\n");
            continue;
        }

        // Mandatory "Try Again" Loop Constraint
        printf("\nDo you want to try another operation? (Y/N): ");
        scanf(" %c", &tryAgain);

        while (getchar() != '\n');

    } while (tryAgain == 'Y' || tryAgain == 'y');

    printf("\nProgram terminated. Goodbye!\n");
    return 0;
}
