/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

int inputInt() {
    int interger;
    char character = 'X';
    while (character != '\n') {
        scanf("%d%c", &interger, &character);
        if (character != '\n') {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    }
    return interger;
}

int inputIntPositive() {
    int interger;
    int stop = 1;

    while (stop != 0) {
        scanf("%d", &interger);
        if (interger < 0) {
            printf("ERROR! Value must be > 0: ");
            clearInputBuffer();
        }
        else {
            stop = 0;
        }
    }
    return interger;
}
int inputIntRange(int min, int max) {
    int interger;
    int stop = 1;
    while (stop != 0) {
        interger = inputInt();
        if (interger > max || interger < min) {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
        else {
            stop = 0;
        }
    }
    return interger;
}
char inputCharOption(char str[]) {
    int stop = 1;
    int i;
    char character;
    char Char='X';
    int TF = 0;
    while (stop != 0) {
        scanf(" %c%c", &character,&Char);
        if (Char != '\n') {
            printf("ERROR: Character must be one of [%s]: ", str);
            clearInputBuffer();
        }
        else {
            for (i = 0; str[i] != '\0'; i++) {
                if (str[i] == character) {
                    TF += 1;
                }

            }
            if (TF != 0) {
                stop = 0;
            }
            else {
                printf("ERROR: Character must be one of [%s]: ", str);
                clearInputBuffer();
            }
        }
    }
    return character;
}

void inputCString(char* string, int min, int max) {
    char str[9999];
    int stop = 1;
    while (stop != 0) {
        scanf(" %9999[^\n]", str);
        int length = 0;
        length = strlen(str);

        if (min == max) {
            if (length > max || length < min) {
                printf("ERROR: String length must be exactly %d chars: ", max);
                clearInputBuffer();

            }
            else {
                stop = 0;
            }
        }
        else {
            if (length > max || length < min) {
                if (length > max) {
                    printf("ERROR: String length must be no more than %d chars: ", max);
                    clearInputBuffer();
                }
                if (length < min) {
                    printf("ERROR: String length must be between %d and %d chars: ", min, max);
                    clearInputBuffer();
                }
            }
            else {
                stop = 0;
            }
        }
    }

    strcpy(string, str);
}


void displayFormattedPhone(const char* phone) {
    int i;
    int num = 0;
    if (phone == NULL) {
        printf("(___)___-____");
    }
    else {
        for (i = 0; phone[i] != '\0'; i++) {
            if (phone[i] >= '0' && phone[i] <= '9') {
                num++;
            }
        }
        if (num == 10) {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", phone[0], phone[1], phone[2], phone[3], phone[4], phone[5], phone[6], phone[7], phone[8], phone[9]);

        }
        else {
            printf("(___)___-____");
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
