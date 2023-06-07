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

#define _CRT_SECURE_NO_WARNINGS
#define MIN 500
#define MAX 400000
#define MIN_ITEMS 1
#define MAX_ITEMS 10
#define MIN_COST 100

#include <stdio.h>
int main(void)
{
    double income, amount;
    int items, i, selection, years, months, filter,count_finance;
    int itemPriority[10];
    char itemCanFinance[10];
    double itemCost[10];
    double sum = 0;
    count_finance = 0;
    



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
        if (items > MAX_ITEMS || items < MIN_ITEMS) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else {
            break;
        }
    }



    for (i = 0; i < items ; i++) {
        printf("\nItem-%d Details:\n", i+1);
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

    for (i = 0; i < items; i++) {

        printf("%3d  %5d    %5c    %11.2lf\n", i+1, itemPriority[i], itemCanFinance[i], itemCost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", sum);
    
    while (1) {
        while (1) {
            printf("\nHow do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &selection);
            if (selection != 1 && selection != 2 && selection != 0) {
                printf("\nERROR: Invalid menu selection.\n");
            }
            else {
                break;
            }
        }
        if (selection == 0) {
            printf("\nBest of luck in all your future endeavours!\n\n");
            break;
        }
        else {
            switch (selection) {
            case 1:
                
                years = (sum / income) / 12;
                months = (((((sum / income) / 12) + 0.05) - (int)years) * 12) + 0.5;

                printf("\n====================================================");
                printf("\nFilter:   All items");
                printf("\nAmount:   $%.2lf", sum);
                printf("\nForecast: %d years, %d months\n", (int)years, (int)months);
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
                printf("====================================================\n");

                amount = years = months = 0;
                break;
            case 2:
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &filter);
                for (i = 0; i < items; i++) {
                    if (itemPriority[i] == filter) {
                        amount += itemCost[i];
                        if (itemCanFinance[i] == 'y') {
                            count_finance++;
                        }
                    }
                    
                }
                years = (amount / income)/12;
                months = (((((amount / income) / 12)+0.05)-(int)years)*12)+0.5;
                  
                

                printf("\n====================================================");
                printf("\nFilter:   by priority (%d)", filter);
                printf("\nAmount:   $%.2lf", amount);
                printf("\nForecast: %d years, %d months\n",(int)years,(int)months);
                if (count_finance >=1) {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");

                amount = years = months = count_finance = 0;

                break;
            }
        }
    }
    return 0;
}

/*   PDF Provided Formatting:

Step #7 (a):
    printf("====================================================\n");

Step #7 (b):
    printf("Filter:   All items\n");           // [option-1]
    printf("Filter:   by priority (%d)\n"...   // [option-2]

Step #7 (c):
    printf("Amount:   $%1.2lf\n"...

*/