#ifndef CARDS_H
#define CARDS_H

#include "../boolean.h"

typedef struct
{
    float Card[4];
} Cards;

#define card(In, N) (In).Card[N]

void CreateCards(Cards *AC, float c1, float c2, float c3, float c4);

void StringToCards(Cards *AC, char String[100]);

boolean CheckCards(char String[100]);

void ReadCards(Cards *AC);

void GenerateCards(Cards *AC);

void PrintCards(Cards AC);

void PrintCardsInt(float cards);

int CharToInt(char CC);

#endif