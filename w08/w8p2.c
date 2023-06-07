/*
*****************************************************************************
                          Workshop - #8 (P2)
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
#include <stdio.h>

// User Libraries
#include "w8p2.h"


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

    printf("\nCat Food Product #%d", i);
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

void displayCatFoodData(int a, double* b, double* c, int d) {
    printf("%07d %10.2lf %10.1lf %8d\n", a, *b, *c, d);
}
double convertLbsKg(double* weight_lbs, double* weight) {
    if (weight == NULL) {
        double d = *weight_lbs / pounds_to_kg;
        double* a = &d;
        return *a;
    }

    *weight = *weight_lbs / pounds_to_kg;
    double c = *weight;
    return c;
}
int convertLbsG(double* weight_lbs, int* weight) {
    double a = convertLbsKg(weight_lbs, 0);
    if (weight == NULL) {
        int d = a * 1000;
        int* b = &d;
        return *b;
    }
    *weight = a * 1000;
    int* c = weight;

    return *c;
}
void convertLbs(double* lbs, double* kg, int* grams) {
    *kg = convertLbsKg(lbs, 0);
    *grams = convertLbsG(lbs, 0);
}

double calculateServings(int a, int b, double* c) {
    double d = (double)a / (double)b;
    double* e = &d;
    return *e;
}

double calculateCostPerServings(double* a, double* b, double* c) {
    double d = *a / *b;
    double* e = &d;
    return *e;

}
double calculateCostPerCal(double* a, double* b, double* c) {
    double d = *a / *b;
    double* e = &d;
    return *e;
}


struct ReportData calculateReportData(struct CatFoodInfo CatFoodInfo) {
    struct ReportData ReportData;
    ReportData.sku = CatFoodInfo.sku;
    ReportData.price = CatFoodInfo.price;
    ReportData.calories = CatFoodInfo.calories;
    ReportData.weight_lbs = CatFoodInfo.weight;
    ReportData.weight_g = convertLbsG(&CatFoodInfo.weight, 0);
    ReportData.weight_kg = convertLbsKg(&CatFoodInfo.weight, 0);
    ReportData.servings = calculateServings(ReportData.weight_g, num_of_grams_in_1_serving, 0);
    ReportData.cost_per = calculateCostPerServings(&CatFoodInfo.price, &ReportData.servings, 0);
    double b = CatFoodInfo.calories * ReportData.servings;
    ReportData.cost_cal = calculateCostPerCal(&CatFoodInfo.price, &b, 0);

    return ReportData;
}
void displayReportHeader(void)
{
    printf("\nAnalysis Report (Note: Serving = %dg)\n", num_of_grams_in_1_serving);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------");
}

void displayReportData(struct ReportData ReportData, int cheap) {
    printf("\n%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", ReportData.sku, ReportData.price, ReportData.weight_lbs, ReportData.weight_kg, ReportData.weight_g, ReportData.calories, ReportData.servings, ReportData.cost_per, ReportData.cost_cal);
}
        
void displayFinalAnalysis(struct ReportData data) {
    printf("\n\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n", data.sku, data.price);
    printf("\nHappy shopping!\n\n");
}
void start() {
    openingMessage();
    int i;
    struct CatFoodInfo info[max_number_of_products];
    struct ReportData data[max_number_of_products];


    for (i = 0; i < max_number_of_products; i++) {

        struct CatFoodInfo CatFoodInfo = getCatFoodInfo(i + 1);
        
        info[i].sku = CatFoodInfo.sku;
        info[i].price = CatFoodInfo.price;
        info[i].weight = CatFoodInfo.weight;
        info[i].calories = CatFoodInfo.calories;
        struct ReportData ReportData =calculateReportData(CatFoodInfo);
        data[i].sku = ReportData.sku;
        data[i].price = ReportData.price;
        data[i].calories = ReportData.calories;
        data[i].weight_lbs = ReportData.weight_lbs;
        data[i].weight_g = ReportData.weight_g;
        data[i].weight_kg = ReportData.weight_kg;
        data[i].servings = ReportData.servings;
        data[i].cost_per = ReportData.cost_per;
        data[i].cost_cal = ReportData.cost_cal;
        
    }

    displayCatFoodHeader();
    for (i = 0; i < max_number_of_products; i++) {
        displayCatFoodData(info[i].sku, &info[i].price, &info[i].weight, info[i].calories);
    }
    double min = data[0].cost_per;
    int cheap;
    for (i = 0; i < max_number_of_products; i++) {
        if (data[i].cost_per < min) {
            min = data[i].cost_per;
            cheap = i;
        }
    }
    displayReportHeader();
    for (i = 0; i < max_number_of_products; i++) {
        displayReportData(data[i], cheap);
        if (i == cheap) {
            printf(" ***");
        }

    }
    displayFinalAnalysis(data[cheap]);
}

// printf("%d %d %d %d %d %d %d %d %d", data[i].sku, data[i].price, data[i].calories, data[i].weight_lbs, data[i].weight_g, data[i].weight_lbs, data[i].servings, data[i].cost_per, data[i].cost_cal);

