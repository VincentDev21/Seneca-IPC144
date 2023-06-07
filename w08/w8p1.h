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


#define max_number_of_products 3
#define num_of_grams_in_1_serving 64
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double price;
    int calories;
    double weight;
};




// ----------------------------------------------------------------------------
// function prototypes
int getIntPositive(int* interger);
double getDoublePositive(double* doublepos);
void openingMessage();
struct CatFoodInfo getCatFoodInfo(int i);
void displayCatFoodHeader();
void displayCatFoodData(int a, double* b, double* c, int d);
void start();
// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 3. Opening Message (include the number of products that need entering)


// 4. Get user input for the details of cat food product


// 5. Display the formatted table header


// 6. Display a formatted record of cat food data


// 7. Logic entry point
