/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3
int days = 1;
float Morning, Evening, mtotal,etotal,averageM,averageE;
char months;

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

        if ((year > MAX_YEAR && month > DEC) || (year > MAX_YEAR && month < JAN) || (year < MIN_YEAR && month > DEC) || (year < MIN_YEAR && month < JAN)) {
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

        if (year >= MIN_YEAR && year <= MAX_YEAR && month > 0 && month <= 12) {
            printf("\n*** Log date set! ***\n");

            switch (month) {
                printf("\n*** Log date set! ***\n\n");

            case 1:
                for (days= 1; days != 4; days++)
                {
                    printf("\n%d-JAN-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 2:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-FEB-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 3:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-MAR-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 4:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-APR-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 5:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-MAY-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 6:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-JUN-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 7:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-JUL-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 8:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-AUG-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 9:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-SEP-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 10:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-OCT-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 11:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-NOV-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            case 12:
                for (days = 1; days != 4; days++)
                {
                    printf("\n%d-DEC-%02d\n", year, days);
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &Morning);
                    while (Morning < 0.0 || Morning>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Morning rating (0.0-5.0): ");
                        scanf("%f", &Morning);

                    }
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &Evening);
                    while (Evening < 0.0 || Evening>5.0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%f", &Evening);

                    }
                    mtotal += Morning;
                    etotal += Evening;

                }
                break;
            }
            break;


        }
    }
    
    averageM = mtotal / LOG_DAYS;
    averageE = etotal / LOG_DAYS;
    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3f\n", mtotal);
    printf("Evening total rating:  %.3f\n", etotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3f\n\n", mtotal + etotal);
    printf("Average morning rating:  %.1f\n", averageM);
    printf("Average evening rating:  %.1f\n", averageE);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1f\n", (averageE + averageM)/2);
    return 0;
}