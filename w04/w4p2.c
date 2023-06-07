/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Vincent Le
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
    int apples, oranges, pears, tomatoes, cabbages, S;
    int a, o, p, t, c;
    a = o = p = t = c= 0;
    apples = oranges = pears = tomatoes = cabbages = 0;
    S = 1;
    while (S != 0)
    {
        printf("Grocery Shopping\n");
        printf("================");
        printf("\nHow many APPLES do you need? : ");
        scanf("%d", &apples);
        while (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
        }
        printf("\nHow many ORANGES do you need? : ");
        scanf("%d", &oranges);
        while (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
        }
        printf("\nHow many PEARS do you need? : ");
        scanf("%d", &pears);
        while (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
        }
        printf("\nHow many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        while (tomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
        }
        printf("\nHow many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        while (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? :");
            scanf("%d", &cabbages);
        }
        printf("\n--------------------------");
        printf("\nTime to pick the products!");
        printf("\n--------------------------\n");
        for (apples; apples != 0;)
        {
            printf("\nPick some APPLES... how many did you pick? : ");
            scanf("%d", &a);
            if (apples>0&&a < apples && a > 0)
            {
                printf("Looks like we still need some APPLES...");
            }
            if (a > apples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.", apples);
                apples += a;

            }
            if (a <= 0)
            {
                printf("ERROR: You must pick at least 1!");

            }
            else
            {
                apples -= a;


            }

            if (apples == 0)
            {
                printf("Great, that's the apples done!\n");

            }
        }
        for (oranges; oranges != 0;)
        {
            printf("\nPick some ORANGES... how many did you pick? : ");
            scanf("%d", &o);
            if (oranges > 0 && o < oranges && o > 0)
            {
                printf("Looks like we still need some ORANGES...");
            }
            if (o > oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.", oranges);
                oranges += o;

            }
            if (o <= 0)
            {
                printf("ERROR: You must pick at least 1!");

            }
            else
            {
                oranges -= o;
            }

        }
        if (oranges == 0)
        {
            printf("Great, that's the oranges done!\n");
        }



        for (pears; pears != 0;)
        {
            printf("\nPick some PEARS... how many did you pick? : ");
            scanf("%d", &p);
            if (pears > 0 && p < pears && p > 0)
            {
                printf("Looks like we still need some PEARS...");
            }
            if (p > pears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.", pears);
                pears += p;

            }
            if (p <= 0)
            {
                printf("ERROR: You must pick at least 1!");

            }
            else
            {
                pears -= p;
            }

            if (pears == 0)
            {
                printf("Great, that's the pears done!\n");
            }
        }
        for (tomatoes; tomatoes != 0;)
        {
            printf("\nPick some TOMATOES... how many did you pick? : ");
            scanf("%d", &t);
            if (tomatoes > 0 && t < tomatoes && t > 0)
            {
                printf("Looks like we still need some TOMATOES...");
            }
            if (t > tomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.",tomatoes);
                tomatoes += t;

            }
            if (t <= 0)
            {
                printf("ERROR: You must pick at least 1!");

            }
            else
            {
                tomatoes -= t;
            }

            if (tomatoes == 0)
            {
                printf("Great, that's the tomatoes done!\n");
            }
        }
        for (cabbages; cabbages != 0;)
        {
            printf("\nPick some CABBAGES... how many did you pick? : ");
            scanf("%d", &c);
            if (cabbages > 0 && c < cabbages && c > 0)
            {
                printf("Looks like we still need some CABBAGES...");
            }
            if (c > cabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.", cabbages);
                cabbages += c;

            }
            if (c <= 0)
            {
                printf("ERROR: You must pick at least 1!");

            }
            else
            {
                cabbages -= c;
            }
            if (cabbages == 0)
            {
                printf("Great, that's the cabbages done!\n");
            }

        }
        printf("\nAll the items are picked!\n");
        
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &S);
        if (S == 0)
        {
            S = 0;
            printf("\nYour tasks are done for today - enjoy your free time!");
        }
        
        
       
    }
    return 0;
}
    
    
