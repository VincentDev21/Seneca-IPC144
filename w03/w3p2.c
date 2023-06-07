/*
*****************************************************************************
                          Workshop - #3 (P2)
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

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    
    // Note:
    // You can convert Celsius to Fahrenheit given the following formula:
    // fahrenheit = (celsius * 1.8) + 32.0);
    char type1, type2, type3;
    char g1, g2, g3;
    char c1, c2, c3;
    int weight1, weight2, weight3;
    float temp1, temp2, temp3;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\nEnter the coffee product information being sold today...\n");
    printf("\nCOFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &g1);
    printf("Bag weight (g): ");
    scanf("%d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c1);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%f", &temp1);


    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &g2);
    printf("Bag weight (g): ");
    scanf("%d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c2);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%f", &temp2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &g3);
    printf("Bag weight (g): ");
    scanf("%d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c3);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%f", &temp3);
    
    printf("\n---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type1 == 'l' || type1 == 'L', type1 == 'B' || type1 == 'b', g1 == 'c' || g1 == 'C', g1 == 'f' || g1 == 'F', weight1, weight1 / GRAMS_IN_LBS, c1 == 'y' || c1 == 'Y', temp1, temp1 * 1.8 + 32);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type2 == 'l' || type2 == 'L', type2 == 'B' || type2 == 'b', g2 == 'c' || g2 == 'C', g2 == 'f' || g2 == 'F', weight2, weight2 / GRAMS_IN_LBS, c2 == 'y' || c2 == 'Y', temp2, temp2 * 1.8 + 32);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type3 == 'l' || type3 == 'L', type3 == 'B' || type1 == 'b', g3 == 'c' || g3 == 'C', g3 == 'f' || g3 == 'F', weight3, weight3 / GRAMS_IN_LBS, c3 == 'y' || c3 == 'Y', temp3, temp3 * 1.8 + 32);

    char cs, cr, m;
    int d;

    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &cs);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cr);
    printf("Typical number of daily servings: ");
    scanf("%d", &d);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &m);
    
    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+--------------------+-------------+-------+--------------");
    printf("\n  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving");
    printf("\nID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature");
    printf("\n--+-----------------+--------------------+-------------+-------+--------------");
    printf("\n 1|       %d         |         %d          |      %d      |   %d   |      %d", cs == 'm' || cs == 'M', m == 'r' || m == 'R', d >= 1 && d <= 4, cr == 'Y' || cr == 'y', m == 'r' || m == 'R');
    printf("\n 2|       %d         |         %d          |      %d      |   %d   |      %d", cs == 'r' || cs == 'R', m == 'c' || m == 'C', d >= 5 && d <= 9, cr == 'n' || cr == 'N', m == 'c' || m == 'C');
    printf("\n 3|       %d         |         %d          |      %d      |   %d   |      %d", cs == 'm' || cs == 'M', m == 'c' || m == 'C', d >= 10, cr == 'n' || cr == 'N', m == 'c' || m == 'C');
    printf("\n\nEnter how you like your coffee and the coffee maker equipment you use...");
    
    printf("\n\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &cs);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cr);
    printf("Typical number of daily servings: ");
    scanf("%d", &d);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &m);
    
    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+--------------------+-------------+-------+--------------");
    printf("\n  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving");
    printf("\nID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature");
    printf("\n--+-----------------+--------------------+-------------+-------+--------------");
    printf("\n 1|       %d         |         %d          |      %d      |   %d   |      %d", cs == 'm' || cs == 'M', m == 'r' || m == 'R', d >= 1 && d <= 4, cr == 'Y' || cr == 'y', m == 'r' || m == 'R');
    printf("\n 2|       %d         |         %d          |      %d      |   %d   |      %d", cs == 'r' || cs == 'R', m == 'c' || m == 'C', d >= 5 && d <= 9, cr == 'n' || cr == 'N', m == 'c' || m == 'C');
    printf("\n 3|       %d         |         %d          |      %d      |   %d   |      %d", cs == 'm' || cs == 'M', m == 'c' || m == 'C', d >= 10, cr == 'n' || cr == 'N', m == 'c' || m == 'C');
    printf("\n\nHope you found a product that suits your likes!\n");
    
    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",

As described in step-10
=======================
printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",

*/