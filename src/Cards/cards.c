#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cards.h"

void CreateCards(Cards *AC, float c1, float c2, float c3, float c4)
{
    card((*AC), 0) = c1;
    card((*AC), 1) = c2;
    card((*AC), 2) = c3;
    card((*AC), 3) = c4;
}

// Turn string with format 'XX XX XX XX' to cards
void StringToCards(Cards *AC, char String[100])
{
    int numCard = 0;
    int currNum = 0;
    char delim[] = " ";
    char *ptr = strtok(String, delim);

    while (numCard < 4)
    {
        currNum = CharToInt(ptr[0]);
        if (currNum == 1 && (ptr[1] != 10) && (ptr[1] != 0))
        {
            currNum = 10 + CharToInt(ptr[1]);
        }
        card((*AC), numCard) = (float)currNum;
        numCard++;
        ptr = strtok(NULL, delim);
    }
}

boolean CheckCards(char String[100])
{
    return true;
}

void ReadCards(Cards *AC)
{
    char String[100];

    fgets(String, 100, stdin);
    while (!CheckCards(String))
    {
        printf("Input Salah!\n");
        fgets(String, 100, stdin);
    }
    StringToCards(AC, String);
}

void GenerateCards(Cards *AC)
{
    srand(time(NULL));
    int c1 = rand() % 13 + 1;
    int c2 = rand() % 13 + 1;
    int c3 = rand() % 13 + 1;
    int c4 = rand() % 13 + 1;

    CreateCards(AC, (float)c1, (float)c2, (float)c3, (float)c4);
}

void PrintCards(Cards AC)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        PrintCardsInt(card(AC, i));
        printf(" ");
    }
}

void PrintCardsInt(float cards)
{
    if (cards > 10.0 || cards < 2.0)
    {
        if (cards == 11.0)
        {
            printf("J");
        }
        else if (cards == 12.0)
        {
            printf("Q");
        }
        else if (cards == 13.0)
        {
            printf("K");
        }
        else if (cards == 1.0)
        {
            printf("A");
        }
    }
    else
    {
        printf("%.0f", cards);
    }
}

int CharToInt(char CC)
{
    if (CC == 'A')
    {
        return 1;
    }
    else if (CC == '1')
    {
        return 1;
    }
    else if (CC == '2')
    {
        return 2;
    }
    else if (CC == '3')
    {
        return 3;
    }
    else if (CC == '4')
    {
        return 4;
    }
    else if (CC == '5')
    {
        return 5;
    }
    else if (CC == '6')
    {
        return 6;
    }
    else if (CC == '7')
    {
        return 7;
    }
    else if (CC == '8')
    {
        return 8;
    }
    else if (CC == '9')
    {
        return 9;
    }
    else if (CC == '0')
    {
        return 0;
    }
    else if (CC == 'J')
    {
        return 11;
    }
    else if (CC == 'Q')
    {
        return 12;
    }
    else if (CC == 'K')
    {
        return 13;
    }
}