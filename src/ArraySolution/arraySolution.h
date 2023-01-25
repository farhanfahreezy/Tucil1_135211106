#ifndef ARRAYSOLUTION_H
#define ARRAYSOLUTION_H

#include "../boolean.h"
#include "../Cards/cards.h"
#include "../Solution/solution.h"

typedef Solution ArrSolEl;

typedef struct
{
    ArrSolEl *ArrSol;
    int Neff;
    int Capacity;
} ArraySolution;

#define ElmtSol(AS, i) (AS).ArrSol[i]
#define ArrSol(AS) (AS).ArrSol
#define Neff(AS) (AS).Neff
#define Cap(AS) (AS).Capacity

void CreateArraySolution(ArraySolution *AS, int cap);

void DeallocArraySolution(ArraySolution *AS);

void AddArray(ArraySolution *AS, Solution Sol);

void PrintArraySolution(ArraySolution AS);

void EmptyPermutationArray(int *array);

int CheckInArray(Cards Card, int *array);

void InsertatArray(int *array, Cards card, int index);

void LexicographicPermutation(ArraySolution *AS, Solution *Sol, int *ArrayPermutation);

void FindAnswer(ArraySolution *AS, Solution *Sol, int *allAdd, int *allTimes);

#endif