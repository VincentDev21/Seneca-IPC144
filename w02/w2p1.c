/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name  :Vincent Le
Student ID#:131117228
Email      :vle21@myseneca.ca
Section    :NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double Small_shirt, Medium_shirt, Large_shirt;
    int num_of_shirts;
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &Small_shirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &Medium_shirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &Large_shirt);
    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2lf\n", Small_shirt);
    printf("MEDIUM : $%.2lf\n", Medium_shirt);
    printf("LARGE  : $%.2lf\n", Large_shirt);
    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &num_of_shirts);



    float subtotal, tax, total;
    subtotal = Small_shirt * num_of_shirts;
    tax = subtotal * TAX;
    int tax1 = (tax + 0.005) * 100;
    double tax2;
    tax2 = (double)tax1 / (double)100;
    total = subtotal + tax2;
    printf("\nPatty's shopping cart...\nContains : ");
    printf("%d shirts\n", num_of_shirts);
    printf("Sub-total: $%8.4lf\n", subtotal);
    printf("Taxes    : $%8.4lf\n", tax2);
    printf("Total    : $%8.4lf\n", total);
    
    return 0;
}