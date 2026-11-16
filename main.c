#include <stdio.h>

int main() {
    int choice;
    char tryAgain;

    do {
        printf("IT102 - PROGRAMMING 1 PORTFOLIO\n");
        printf("1. Pattern Generator\n");
        printf("2. Pascal's Triangle\n");
        printf("3. Grade Calculator\n");
        printf("4. Palindrome Checker\n");
        printf("5. Exit Program\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
        }

        if (choice == 1) {
            int size, subChoice;

            printf("\nPATTERN GENERATOR\n");
            printf("Enter the size of the shape: ");

            if (scanf("%d", &size) != 1 || size <= 0) {
                printf("Invalid size. Please enter a positive number.\n");
                while (getchar() != '\n');
            }
            else {
                printf("\nSelect Shape:\n");
                printf("1. Right Triangle\n");
                printf("2. Square\n");
                printf("3. Isosceles Triangle\n");
                printf("4. Inverted Right Triangle\n");
                printf("5. Christmas Tree\n");
                printf("Enter your choice: ");

                if (scanf("%d", &subChoice) != 1) {
                    while (getchar() != '\n');
                    subChoice = 0;
                }

                if (subChoice == 1) {
                    printf("\nRight Triangle:\n");

                    for (int i = 1; i <= size; i++) {
                        for (int j = 1; j <= i; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                }
                else if (subChoice == 2) {
                    printf("\nSquare:\n");

                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                }
                else if (subChoice == 3) {
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
                else if (subChoice == 4) {
                    printf("\nInverted Right Triangle:\n");

                    for (int i = size; i >= 1; i--) {
                        for (int j = 1; j <= i; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                }
                else if (subChoice == 5) {
                    printf("\nChristmas Tree:\n");

                    for (int t = 1; t <= 3; t++) {
                        int startRow;

                        if (t == 1) {
                            startRow = 1;
                        }
                        else if (t == 2) {
                            startRow = 2;
                        }
                        else {
                            startRow = 3;
                        }

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
                    printf("Invalid shape selection.\n");
                }
            }
        }

        else if (choice == 2) {
            int rows;

            printf("\nPASCAL'S TRIANGLE\n");
            printf("Enter the number of rows (1-20): ");

            if (scanf("%d", &rows) != 1 || rows < 1 || rows > 20) {
                printf("Invalid number of rows. Enter a number from 1 to 20.\n");
                while (getchar() != '\n');
            }
            else {
                printf("\nPascal's Triangle:\n");

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
            float prelim, midterm, prefinal, finalGrade, average;

            printf("\nGRADE CALCULATOR\n");

            printf("Enter Prelim grade: ");
            if (scanf("%f", &prelim) != 1) {
                printf("Invalid grade input.\n");
                while (getchar() != '\n');
            }
            else {
                printf("Enter Midterm grade: ");
                if (scanf("%f", &midterm) != 1) {
                    printf("Invalid grade input.\n");
                    while (getchar() != '\n');
                }
                else {
                    printf("Enter Pre-Final grade: ");
                    if (scanf("%f", &prefinal) != 1) {
                        printf("Invalid grade input.\n");
                        while (getchar() != '\n');
                    }
                    else {
                        printf("Enter Final grade: ");
                        if (scanf("%f", &finalGrade) != 1) {
                            printf("Invalid grade input.\n");
                            while (getchar() != '\n');
                        }
                        else {
                            average = (prelim + midterm + prefinal + finalGrade) / 4.0;

                            printf("\nFinal Grade Average: %.2f\n", average);

                            if (average >= 75) {
                                printf("Status: PASS\n");
                            }
                            else {
                                printf("Status: FAIL\n");
                            }
                        }
                    }
                }
            }
        }

        else if (choice == 4) {
            char word[100];
            int length = 0;
            int isPalindrome = 1;
            int isValid = 1;

            printf("\nPALINDROME CHECKER\n");
            printf("Enter a word: ");

            if (scanf("%99s", word) != 1) {
                printf("Invalid input.\n");
            }
            else {
                while (word[length] != '\0') {
                    if (!((word[length] >= 'A' && word[length] <= 'Z') ||
                          (word[length] >= 'a' && word[length] <= 'z'))) {
                        isValid = 0;
                    }

                    length++;
                }

                if (isValid == 0 || length == 0) {
                    printf("Invalid input. Please enter letters only.\n");
                }
                else {
                    for (int i = 0; i < length / 2; i++) {
                        if (word[i] != word[length - i - 1]) {
                            isPalindrome = 0;
                        }
                    }

                    if (isPalindrome == 1) {
                        printf("The word is a palindrome!\n");
                    }
                    else {
                        printf("The word is not a palindrome.\n");
                    }
                }
            }
        }

        else if (choice == 5) {
            printf("Exiting program.\n");
            return 0;
        }

        else {
            printf("Invalid choice. Please select from 1 to 5.\n");
        }

        printf("\nDo you want to try again? (Y/N): ");
        scanf(" %c", &tryAgain);

        while (getchar() != '\n');

    } while (tryAgain == 'Y' || tryAgain == 'y');

    printf("\nProgram ended. Goodbye!\n");

    return 0;
}
