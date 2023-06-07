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
#pragma once

#define max_number_of_products 3
#define num_of_grams_in_1_serving 64
#define pounds_to_kg 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double price;
    int calories;
    double weight;
};
struct ReportData {
    int sku;
    double price;
    int calories;
    double weight_lbs;
    double weight_kg;
    int weight_g;
    double servings;
    double cost_per;
    double cost_cal;
};



// ----------------------------------------------------------------------------
// function prototypes
int getIntPositive(int* interger);
double getDoublePositive(double* doublepos);
void openingMessage();
struct CatFoodInfo getCatFoodInfo(int i);
void displayCatFoodHeader();
void displayCatFoodData(int a, double* b, double* c, int d);
double convertLbsKg(double* weight_lbs, double* weight);
int convertLbsG(double* weight_lbs, int*weight);
void convertLbs(double* lbs, double* kg, int* grams);
double calculateServings(int a, int b,double*c);
double calculateCostPerServings(double* a, double* b,double*c);
double calculateCostPerCal(double* a, double* b,double *c);
struct ReportData calculateReportData(const struct CatFoodInfo);
void displayReportHeader();
//void displayReportData(int a, double* b, double* c, double* d, int e, int f, double* g, double* h, double* i, int j);
void displayReportData(struct ReportData, int cheap);
void displayFinalAnalysis(struct ReportData data);
void start();
