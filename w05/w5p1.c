/*
*****************************************************************************
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month, a;
    a = 1;
    printf("General Well-being Log");
    printf("\n======================");
    while (a == 1)
    {
        printf("\nSet the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &month);

        if ((year>MAX_YEAR && month > DEC) || (year > MAX_YEAR && month < JAN )|| (year < MIN_YEAR && month > DEC) || (year < MIN_YEAR && month < JAN)) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)");

        }
        
        else if (year<MIN_YEAR || year>MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive");
        }
        else if (month <= 0 || month > 12)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)");
        }
        
        if (year>=MIN_YEAR&& year<=MAX_YEAR &&month>0&&month<=12) {
            printf("\n*** Log date set! ***\n");

            switch (month) {
                printf("\n*** Log date set! ***\n");

            case 1:
                printf("\nLog starting date: %d-JAN-01", year);
                break;
            case 2:
                printf("\nLog starting date: %d-FEB-01", year);
                break;
            case 3:
                printf("\nLog starting date: %d-MAR-01", year);
                break;
            case 4:
                printf("\nLog starting date: %d-APR-01", year);
                break;
            case 5:
                printf("\nLog starting date: %d-MAY-01", year);
                break;
            case 6:
                printf("\nLog starting date: %d-JUN-01", year);
                break;
            case 7:
                printf("\nLog starting date: %d-JUL-01", year);
                break;
            case 8:
                printf("\nLog starting date: %d-AUG-01", year);
                break;
            case 9:
                printf("\nLog starting date: %d-SEP-01", year);
                break;
            case 10:
                printf("\nLog starting date: %d-OCT-01", year);
                break;
            case 11:
                printf("\nLog starting date: %d-NOV-01", year);
                break;
            case 12:
                printf("\nLog starting date: %d-DEC-01", year);
                break;
            }
            break;
            


        }
    }
    printf("\n");
    return 0;
}