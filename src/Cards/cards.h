#ifndef CARDS_H
#define CARDS_H

#include "../boolean.h"

typedef struct
{
    int Card[4];
} Cards;

#define card(In, N) (In).Card[N]

void CreateCards(Cards *AC, int c1, int c2, int c3, int c4);

void StringToCards(Cards *AC, char String[100]);

boolean CheckCards(char String[100]);

void ReadCards(Cards *AC);

void GenerateCards(Cards *AC);

void PrintCards(Cards AC);

void PrintCardsInt(int cards);

int CharToInt(char CC);

#endif