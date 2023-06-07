/*
*****************************************************************************
						  Workshop - #8 (P1)
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


// System Libraries
#include "w8p1.h"

#include <stdio.h>

// User Libraries
int main(void);

int getIntPositive(int* interger) {
    int aaa;
    scanf("%d", &aaa);
    if (interger == NULL) {
        while (aaa <= 0) {
            if (aaa <= 0) {
                printf("ERROR: Enter a positive value: ");
                scanf("%d", &aaa);
            }
        }
        interger = &aaa;
        int b = *interger;
        return b;
    }
    *interger += aaa;
    while (aaa <= 0) {
        if (aaa <= 0) {
            printf("ERROR: Enter a positive value: ");
            scanf("%d", &aaa);
            

        }
    }
    *interger = aaa;
    int* a = interger;
    return *a;
}
double getDoublePositive(double* value) {
    double ccc;
    scanf("%lf", &ccc);
    if (value == NULL) {
        while (ccc <= 0) {
            if (ccc <= 0) {
                printf("ERROR: Enter a positive value: ");
                scanf("%lf", &ccc);
            }

        }
        value = &ccc;
        double b = *value;
        return b;
    }
    *value = ccc;
    while (ccc <= 0) {
        if (ccc <= 0) {
            printf("ERROR: Enter a positive value: ");
            scanf("%lf", &ccc);

        }
    }
    *value = ccc;
    double* c = &ccc;
    return *c;

}

void openingMessage() {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\nEnter the details for %d dry food bags of product data for analysis.", max_number_of_products);
    printf("\nNOTE: A 'serving' is %dg\n", num_of_grams_in_1_serving);
}
struct CatFoodInfo getCatFoodInfo(int i) {
    struct CatFoodInfo CatFoodInfo;
    
    printf("\nCat Food Product #%d",i);
    printf("\n--------------------\n");
    printf("SKU           : ");
    CatFoodInfo.sku = getIntPositive(&CatFoodInfo.sku);
    printf("PRICE         : $");
    CatFoodInfo.price = getDoublePositive(&CatFoodInfo.price);
    printf("WEIGHT (LBS)  : ");
    CatFoodInfo.weight = getDoublePositive(&CatFoodInfo.weight);
    printf("CALORIES/SERV.: ");
    CatFoodInfo.calories = getIntPositive(&CatFoodInfo.calories);
    
    return CatFoodInfo;
}
void displayCatFoodHeader(void)
{
    printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int a, double *b, double *c, int d) {
    printf("%07d %10.2lf %10.1lf %8d\n", a,*b,*c,d);
}
void start() {
    openingMessage();
    int i;
    struct CatFoodInfo info[max_number_of_products];
    for (i = 0; i < max_number_of_products; i++) {
        struct CatFoodInfo CatFoodInfo = getCatFoodInfo(i + 1);
        info[i].sku = CatFoodInfo.sku;
        info[i].price = CatFoodInfo.price;
        info[i].weight = CatFoodInfo.weight;
        info[i].calories = CatFoodInfo.calories;
    }
    displayCatFoodHeader();
    for (i = 0; i < max_number_of_products; i++) {
        int a = info[i].sku;
        double b = info[i].price;
        double c = info[i].weight;
        int d = info[i].calories;
        displayCatFoodData(a, &b, &c, d);
    }
    
    

}

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 3. Opening Message (include the number of products that need entering)


// 4. Get user input for the details of cat food product


// 5. Display the formatted table header

// 6. Display a formatted record of cat food data


// 7. Logic entry point