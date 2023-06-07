/*
*****************************************************************************
                          Workshop - #7 (P1)
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

#define Multiple 5
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MAX_MOVES 26
#define MIN_MOVES 3
#define max 10
#define min 1
int i,ii,iii;

struct Playerinfo {
    char sym;
    int lives;
    int history[MAX_PATH_LENGTH];
    int treasures;

};
struct Gameinfo {
    int path_length;
    int num_moves;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
};

int main(void)
{
    
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    struct Playerinfo info;
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &info.sym);
    
    
    while (1) {
        printf("Set the number of lives: ");
        scanf("%d", &info.lives);
        if (info.lives > max || info.lives < min) {
            printf("     Must be between %d and %d!\n",min,max);
        }
        else {
            printf("Player configuration set-up is complete\n");
            break;
        }
    }

    printf("\nGAME Configuration\n");
    printf("------------------\n");
    struct Gameinfo info2;
    while (1) {
        printf("Set the path length (a multiple of %d between %d-%d): ", Multiple,MIN_PATH_LENGTH,MAX_PATH_LENGTH);
        scanf("%d", &info2.path_length);
        if (info2.path_length > MAX_PATH_LENGTH || info2.path_length < MIN_PATH_LENGTH|| info2.path_length% Multiple !=0) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", Multiple,MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
        else {
            break;
        }
    }
    while (1) {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &info2.num_moves);
        if (info2.num_moves > MAX_MOVES || info2.num_moves < MIN_MOVES) {
            printf("    Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
        }
        else {
            break;
        }
    }
    

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",info2.path_length);
    ii = 1;
    iii = 5;
    
    for (i = 0; i < info2.path_length; i+=5) {
        printf("   Positions [%2d-%2d]: ",ii,iii);
        scanf("%d %d %d %d %d", &info2.bombs[i], &info2.bombs[i + 1], &info2.bombs[i + 2], &info2.bombs[i + 3], &info2.bombs[i + 4]);
        ii += 5;
        iii += 5;

    }
    printf("BOMB placement set\n");
    
    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",info2.path_length);
    ii = 1;
    iii = 5;

    for (i = 0; i < info2.path_length; i += 5) {
        printf("   Positions [%2d-%2d]: ", ii, iii);
        scanf("%d %d %d %d %d", &info2.treasure[i], &info2.treasure[i + 1], &info2.treasure[i + 2], &info2.treasure[i + 3], &info2.treasure[i + 4]);
        ii += 5;
        iii += 5;

    }
    printf("TREASURE placement set\n");
    printf("\nGAME configuration set-up is complete...\n");
    printf("\n------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n",info.sym);
    printf("   Lives      : %d\n",info.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\nGame:\n");
    printf("   Path Length: %d\n", info2.path_length);
    printf("   Bombs      : ");
   
    for (i = 0; i < info2.path_length; i++) {
        printf("%d", info2.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < info2.path_length; i++) {
        printf("%d", info2.treasure[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    return 0;
}