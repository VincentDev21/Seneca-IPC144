/*
*****************************************************************************
                          Workshop - #4 (P1)
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
    int a;
    char i;
    a = 0;
    i = '0';
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+");
    while (i != 'Q' || a != 0)
    {
        printf("\n\nD = do/while | W = while | F = for | Q = quit");
        printf("\nEnter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &i, &a);

        if (i != 'D' && i != 'W' && i != 'F' && i != 'Q')
        {
            printf("ERROR: Invalid entered value(s)!");
        }
        else
        {
            if (i == 'Q' && a != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!");
            }
            else
            {
                if (i == 'Q' && a == 0)
                {
                    printf("\n+--------------------+\n");
                    printf("Loop application ENDED\n");
                    printf("+--------------------+\n");
                }
                else
                {
                    if (a < 3 || a>20)
                    {
                        printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                    }
                    else
                    {
                        if (i == 'D')
                        {
                            printf("DO-WHILE: ");
                            do {
                                a--;
                                printf("D");

                            } while (a > 0);
                        }
                        if (i == 'W')
                        {
                            printf("WHILE   : ");
                            while (a > 0)
                            {
                                a--;
                                printf("W");
                            }
                        }
                        if (i == 'F')
                        {
                            printf("FOR     : ");
                            for (;a > 0;--a)
                            {
                                printf("F");
                            }
                                
                        }
                    }
                }
            }
            
            


        }
    }

    return 0;
}