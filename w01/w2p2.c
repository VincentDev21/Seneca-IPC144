/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double Small_shirt, Medium_shirt, Large_shirt;
    int num_of_small_shirts, num_of_medium_shirts, num_of_large_shirts;
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
    printf("\nPatty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &num_of_small_shirts);
    printf("\nTommy's shirt size is 'L'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &num_of_large_shirts);
    printf("\nSally's shirt size is MS'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &num_of_medium_shirts);
    
    double subtotalp, taxp, totalp, subtotalt, taxt, totalt,subtotals, taxs, totals;
    subtotalp = (Small_shirt * num_of_small_shirts)*100;
    subtotalt = (Large_shirt * num_of_large_shirts)*100;
    subtotals = (Medium_shirt * num_of_medium_shirts)*100;
    taxp = (subtotalp * TAX)+0.5;
    taxt = (subtotalt * TAX)+0.5;
    taxs = (subtotals * TAX)+0.5;
    int taxsp=taxp;
    int taxst=taxt;
    int taxss=taxs;
    double Patty_Final_Tax, Tommy_Final_Tax, Sally_Final_Tax;
    Patty_Final_Tax = (double)taxsp / (double)100;
    Tommy_Final_Tax = (double)taxst / (double)100;
    Sally_Final_Tax = (double)taxss / (double)100;
    totalp = subtotalp/100 + Patty_Final_Tax;
    totalt = subtotalt/100 + Tommy_Final_Tax;
    totals = subtotals/100 + Sally_Final_Tax;
    float Grand_subtotal, Grand_tax, Grand_total;
    Grand_subtotal = (subtotalp + subtotals + subtotalt)/100;
    Grand_tax = Patty_Final_Tax + Sally_Final_Tax + Tommy_Final_Tax;
    Grand_total = totalp + totals + totalt;
    printf("Customer Size Price Qty Sub-Total     Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, Small_shirt, num_of_small_shirts, subtotalp/100, Patty_Final_Tax, totalp);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, Medium_shirt, num_of_medium_shirts, subtotals/100, Sally_Final_Tax, totals);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, Large_shirt, num_of_large_shirts, subtotalt/100, Tommy_Final_Tax, totalt);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", Grand_subtotal, Grand_tax, Grand_total);
    printf("\n\nDaily retail sales represented by coins\n=======================================\n\nSales EXCLUDING tax\nCoin     Qty     Balance\n-------- --- ---------\n");
    float Subtotal_excluding_tax, Subtotal1, Subtotal2, Subtotal3, Subtotal4,Subtotal5,Subtotal6;
    Subtotal_excluding_tax = Grand_subtotal;
    int Toonies, Loonies, Quarters, Dimes, Nickels, Pennies;
    Toonies = (int)Subtotal_excluding_tax / 2;
    Subtotal1 = Subtotal_excluding_tax - ((int)Toonies * 2);
    Loonies = (int)Subtotal1 / 1;
    Subtotal2 = Subtotal1 - (int)Loonies;
    Quarters = Subtotal2 / 0.25;
    Subtotal3 = Subtotal2 - (0.25 * Quarters);
    Dimes = Subtotal3/0.1;
    Subtotal4 = Subtotal3 - (0.1 * Dimes);
    Nickels = Subtotal4/0.05;
    Subtotal5 = Subtotal4 - (0.05 * Nickels);
    Pennies = Subtotal5/0.01;
    Subtotal6 = Subtotal5 - (0.01 * Pennies);
    
    printf("%22.4lf\n", Subtotal_excluding_tax);
    printf("Toonies %3d  %9.4lf\n", Toonies, Subtotal1);
    printf("Loonies %3d  %9.4lf\n", Loonies, Subtotal2);
    printf("Quarters%3d  %9.4lf\n", Quarters, Subtotal3);
    printf("Dimes   %3d  %9.4lf\n", Dimes, Subtotal4);
    printf("Nickles %3d  %9.4lf\n", Nickels, Subtotal5);
    printf("Pennies %3d  %9.4lf\n", Pennies, Subtotal6);
    float average = (Grand_subtotal) / (num_of_large_shirts + num_of_medium_shirts + num_of_small_shirts);
    printf("\nAverage cost/shirt: %.4f", average);
    printf("\n\nSales INCLUDING tax\nCoin     Qty    Balance\n-------- --- ---------");
    float Subtotal_including_tax, Sub1, Sub2, Sub3, Sub4, Sub5, Sub6;
    Subtotal_including_tax = Grand_total;
    int Toonies1, Loonies1, Quarters1, Dimes1, Nickels1, Pennies1;
    Toonies1 = (int)Subtotal_including_tax / 2;
    Sub1 = Subtotal_including_tax - ((int)Toonies1 * 2);
    Loonies1 = (int)Sub1 / 1;
    Sub2 = Sub1 - (int)Loonies1;
    Quarters1 = Sub2 / 0.25;
    Sub3 = Sub2 - (0.25 * Quarters1);
    Dimes1 = Sub3 / 0.1;
    Sub4 = Sub3 - (0.1 * Dimes1);
    Nickels1 = Sub4 / 0.05;
    Sub5 = Sub4 - (0.05 * Nickels1);
    Pennies1 = Sub5 / 0.01;
    Sub6 = Sub5 - (0.01 * Pennies1);
    Subtotal_including_tax = Grand_total;
    printf("\n%22.4lf\n", Grand_total);
    printf("Toonies %3d  %9.4lf\n", Toonies1, Sub1);
    printf("Loonies %3d  %9.4lf\n", Loonies1, Sub2);
    printf("Quarters%3d  %9.4lf\n", Quarters1, Sub3);
    printf("Dimes   %3d  %9.4lf\n", Dimes1, Sub4);
    printf("Nickels %3d  %9.4lf\n", Nickels1, Sub5);
    printf("Pennies %3d  %9.4lf\n", Pennies1, Sub6);
    float average1 = Grand_total / (num_of_large_shirts + num_of_medium_shirts + num_of_small_shirts);
    printf("\nAverage cost/shirt: %.4f", average1);
   

    return 0;
}