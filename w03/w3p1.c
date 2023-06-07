/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  :
Student ID#:
Email      :
Section    :
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
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    int Product_ID1, Product_ID2, Product_ID3;
    double Product_1, Product_2, Product_3, Average;
    char tax1, tax2, tax3;
    Product_ID1 = 111;
    Product_ID2 = 222;
    Product_ID3 = 111;
    Product_1 = 111.49;
    Product_2 = 222.99;
    Product_3 = 334.49;
    tax1 = 'Y';
    tax2 = 'N';
    tax3 = 'N';
    Average = (Product_1 + Product_2 + Product_3) / 3;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n",Product_ID1);
    printf("  Taxed: %c\n", tax1);
    printf("  Price: $%.4lf\n", Product_1);
    printf("\nProduct-2 (ID:%d)\n", Product_ID2);
    printf("  Taxed: %c\n", tax2);
    printf("  Price: $%.4lf\n", Product_2);
    printf("\nProduct-3 (ID:%d)\n", Product_ID3);
    printf("  Taxed: %c\n", tax3);
    printf("  Price: $%.4lf\n", Product_3);
    printf("\nThe average of all prices is: $%.4lf\n", Average);
    printf("\nAbout Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\nSome Data Analysis...\n=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", tax1=='Y');
    printf("\n2. Are products 2 and 3 both NOT taxable (N)? -> %d\n",tax1 &&tax2!='Y');
    printf("\n3. Is product 3 less than testValue ($%.2lf)? -> %d\n",testValue,Product_3<testValue);
    printf("\n4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n",Product_3>(Product_2+Product_1));
    printf("\n5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n",Product_1>=(Product_3-Product_2),Product_3-Product_2);
    printf("\n6. Is the price of product 2 equal to or more than the average price? -> %d\n",Product_2>=Average);
    printf("\n7. Based on product ID, product 1 is unique -> %d\n",Product_ID1!=Product_ID2&&Product_ID1!=Product_ID3);
    printf("\n8. Based on product ID, product 2 is unique -> %d\n", Product_ID2 != Product_ID3 && Product_ID2 != Product_ID1);
    printf("\n9. Based on product ID, product 3 is unique -> %d\n", Product_ID3 != Product_ID1 && Product_ID3 != Product_ID2);

    
    return 0;
}