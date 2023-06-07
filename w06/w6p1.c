/*
*****************************************************************************
                          Workshop - #6 (P1)
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
/**/
#define _CRT_SECURE_NO_WARNINGS
#define MIN 500
#define MAX 400000
#define MIN_ITEMS 1
#define MAX_ITEMS 10
#define MIN_COST 100

#include <stdio.h>

int main(void)
{
    double income;
    int items, i;
    int itemPriority[10];
    char itemCanFinance[10];
    double itemCost[10];
    double sum = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    while (1)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < MIN)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (income > MAX)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &items);
        if (items > MAX_ITEMS || items < MIN_ITEMS){
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else {
            break;
        }
    }

    

    for (i = 1; i < items+1; i++) {
        printf("\nItem-%d Details:\n",i);
        while (1) {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            if (itemCost[i] < MIN_COST) {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else {
                break;
            }
        }
        while (1) {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);
            if (itemPriority[i] > 3 || itemPriority[i] < 1)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else {
                break;
            }
        }
        while (1) {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemCanFinance[i]);
            if (itemCanFinance[i] != 'n' && itemCanFinance[i] != 'y') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else {
                break;
            }
        }
        sum += itemCost[i];
    }
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    for (i = 1; i < items+1; i++) {
    
        printf("%3d  %5d    %5c    %11.2lf\n", i, itemPriority[i], itemCanFinance[i], itemCost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", sum);
    printf("\nBest of luck in all your future endeavours!\n\n");

    return 0;
}

/*   PDF Provided Formatting:

Step #7 (a):
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

Step #7 (b):
    printf("%3d  %5d    %5c    %11.2lf\n", i + 1, itemPriority[i], itemCanFinance[i], itemCost[i]);

*/