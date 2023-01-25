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
        printf("%s\n", ptr);
        ptr = strtok(NULL, delim);
    }
}

boolean CheckCards(char String[100])
{
    int numCard = 0;
    char delim[] = " ";
    char *ptr = strtok(String, delim);
    int i;

    while (ptr != NULL)
    {
        if (numCard > 3)
        {
            return false;
        }
        else if (numCard == 3)
        {
            if (strlen(ptr) > 3)
            {
                return false;
            }
            else
            {
                if (ptr[1] == 10)
                {
                    if (!CheckLetter(ptr[0]))
                    {
                        return false;
                    }
                }
                else if (ptr[2] == 10)
                {
                    if (ptr[0] != '1' || (ptr[0] < 48 || ptr[0] > 51))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            if (strlen(ptr) > 2)
            {
                return false;
            }
            else
            {
                if (strlen(ptr) == 2)
                {
                    if (ptr[0] != '1' || (ptr[0] < 48 || ptr[0] > 51))
                    {
                        return false;
                    }
                }
                else
                {
                    if (!CheckLetter(ptr[0]))
                    {
                        return false;
                    }
                }
            }
        }
        numCard++;
        ptr = strtok(NULL, delim);
    }
    return true;
}

boolean CheckLetter(char Let)
{
    switch (Let)
    {
    case 49:
        return true;
        break;
    case 50:
        return true;
        break;
    case 51:
        return true;
        break;
    case 52:
        return true;
        break;
    case 53:
        return true;
        break;
    case 54:
        return true;
        break;
    case 55:
        return true;
        break;
    case 56:
        return true;
        break;
    case 57:
        return true;
        break;
    case 65:
        return true;
        break;
    case 74:
        return true;
        break;
    case 75:
        return true;
        break;
    case 81:
        return true;
        break;
    default:
        return false;
        break;
    }
}

void ReadCards(Cards *AC)
{
    char String[100];
    char String2[100];
    printf("Masukkan Kartu Anda\n");
    printf("Format (X X X X)\n");
    printf("Kartu :\n");
    fgets(String, 100, stdin);
    strcpy(String2, String);
    while (!CheckCards(String))
    {
        printf("Input Salah!\n\n");
        printf("Masukkan Kartu Anda\n");
        printf("Format (X X X X)\n");
        printf("Kartu :\n");
        fgets(String, 100, stdin);
        strcpy(String2, String);
    }
    StringToCards(AC, String2);
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

void Reverse(Cards *AC, int i)
{
    float temp;
    if (i == 1)
    {
        temp = card(*AC, 1);
        card(*AC, 1) = card(*AC, 3);
        card(*AC, 3) = temp;
    }
    else // i == 2
    {
        temp = card(*AC, 2);
        card(*AC, 2) = card(*AC, 3);
        card(*AC, 3) = temp;
    }
}

void Swap(Cards *AC, int i, int j)
{
    float temp;
    temp = card(*AC, i - 1);
    card(*AC, i - 1) = card(*AC, j);
    card(*AC, j) = temp;
    if (i != 3)
    {
        Reverse(AC, i);
    }
}

void SortCards(Cards *AC)
{
    int i, j;
    float temp;
    int idxtemp;
    for (i = 0; i < 4; i++)
    {
        temp = 14.0;
        for (j = i; j < 4; j++)
        {
            if (card(*AC, j) < temp)
            {
                temp = card(*AC, j);
                idxtemp = j;
            }
        }
        card(*AC, idxtemp) = card(*AC, i);
        card(*AC, i) = temp;
    }
}