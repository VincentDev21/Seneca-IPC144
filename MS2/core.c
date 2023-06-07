/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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
#include "core.h"
#include <string.h>
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt() {
    int interger;
    char character='X';
    while(character!='\n') {
        scanf("%d%c", &interger, &character);
        if (character!='\n') {
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
            printf("ERROR! Value must be between %d and %d inclusive: ",min,max);
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
    int TF=0;
    while (stop != 0) {
        scanf(" %c", &character);
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] == character) {
                TF += 1;
            }
            
        }
        if (TF != 0) {
            stop = 0;
        }
        else {
            printf("ERROR: Character must be one of [%s]: ",str);
            clearInputBuffer();
        }
    }           
    return character;
}

void inputCString(char *string, int min, int max) {
    char str[7 + 1];
    int i;
    int stop = 1;
    while (stop != 0) {
        scanf(" %7[^\n]", str);
        int length = 0;
        length = strlen(str);
        
        if (min == max) {
            if (length > max || length < min) {
                printf("ERROR: String length must be exactly %d chars: ",max);
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

    
    for (i = 0; str[i] != '\0'; i++) {
        string[i] = str[i];
    }
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