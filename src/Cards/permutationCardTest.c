#include <stdio.h>
#include <string.h>
#include "cards.h"

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

void LexicographicPermutation(Cards *AC)
{
    int i;
    int j;
    int lexI, lexJ;
    SortCards(AC);
    PrintCards(*AC);
    printf("\n");
    for (i = 0; i < 23; i++)
    {
        for (j = 1; j < 4; j++)
        {
            if (card(*AC, j - 1) < card(*AC, j))
            {
                lexI = j;
            }
        }
        for (j = lexI; j < 4; j++)
        {
            if (card(*AC, lexI - 1) < card(*AC, j))
            {
                lexJ = j;
            }
        }
        Swap(AC, lexI, lexJ);
        PrintCards(*AC);
        printf("\n");
    }
}

int main()
{
    Cards AC;
    ReadCards(&AC);
    printf("Kartu anda adalah : \n");
    PrintCards(AC);
    printf("\n");
    printf("Kombinasi Kartu: \n\n");
    LexicographicPermutation(&AC);
    return 0;
}