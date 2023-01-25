#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arraySolution.h"

void CreateArraySolution(ArraySolution *AS, int cap)
{
    Cap(*AS) = cap;
    Neff(*AS) = 0;
    ArrSol(*AS) = (ArrSolEl *)malloc(cap * sizeof(ArrSolEl));
}

void DeallocArraySolution(ArraySolution *AS)
{
    free(ArrSol(*AS));
    Cap(*AS) = 0;
    Neff(*AS) = 0;
}

void AddArray(ArraySolution *AS, Solution Sol)
{
    Solution SolNew;
    CopySolution(Sol, &SolNew);
    ElmtSol(*AS, Neff(*AS)) = SolNew;
    Neff(*AS)++;
}

void PrintArraySolution(ArraySolution AS)
{
    int i;
    for (i = 0; i < Neff(AS); i++)
    {
        PrintSolution(ElmtSol(AS, i));
    }
}

void EmptyPermutationArray(int *array)
{
    int i;
    for (i = 0; i < 24; i++)
    {
        array[i] = -1;
    }
}

int CheckInArray(Cards Card, int *array)
{
    int i;
    int cardValue = ((int)card(Card, 0)) + ((int)card(Card, 1) * 100) + ((int)card(Card, 2) * 10000) + ((int)card(Card, 3) * 1000000);
    for (i = 0; i < 24; i++)
    {
        if (array[i] == cardValue)
        {
            return -1;
        }
        else if (array[i] == -1)
        {
            return i;
        }
    }
}

void InsertatArray(int *array, Cards Card, int index)
{
    int cardValue = ((int)card(Card, 0)) + ((int)card(Card, 1) * 100) + ((int)card(Card, 2) * 10000) + ((int)card(Card, 3) * 1000000);
    array[index] = cardValue;
}

void LexicographicPermutation(ArraySolution *AS, Solution *Sol, int *ArrayPermutation)
{
    int i;
    int j;
    int lexI, lexJ;
    int allAdd = 0;
    int allTimes = 0;
    int idxArrayPerm = 0;
    SortCards(&((*Sol).solCard));
    InsertatArray(ArrayPermutation, (*Sol).solCard, idxArrayPerm);
    FindAnswer(AS, Sol, &allAdd, &allTimes);
    for (i = 0; i < 23; i++)
    {
        for (j = 1; j < 4; j++)
        {
            if (solCard(*Sol, j - 1) < solCard(*Sol, j))
            {
                lexI = j;
            }
        }
        for (j = lexI; j < 4; j++)
        {
            if (solCard(*Sol, lexI - 1) < solCard(*Sol, j))
            {
                lexJ = j;
            }
        }
        Swap(&((*Sol).solCard), lexI, lexJ);
        idxArrayPerm = CheckInArray((*Sol).solCard, ArrayPermutation);
        if (idxArrayPerm != -1)
        {
            InsertatArray(ArrayPermutation, (*Sol).solCard, idxArrayPerm);
            FindAnswer(AS, Sol, &allAdd, &allTimes);
        }
    }
}

void FindAnswer(ArraySolution *AS, Solution *Sol, int *allAdd, int *allTimes)
{
    int i, j;

    for (i = 0; i < 64; i++)
    {
        NextOp(Sol);
        solBr(*Sol) = -1;
        if ((solOp(*Sol, 0) == 0 && solOp(*Sol, 1) == 0 && solOp(*Sol, 2) == 0) && *allAdd == 0)
        {
            solBr(*Sol)++;
            *allAdd = 1;
            if (Calculate(*Sol) == 24.0)
            {
                AddArray(AS, *Sol);
            }
        }
        else if ((solOp(*Sol, 0) == 0 && solOp(*Sol, 1) == 0 && solOp(*Sol, 2) == 0) && *allAdd == 1)
        {
            continue;
        }
        else if ((solOp(*Sol, 0) == 2 && solOp(*Sol, 1) == 2 && solOp(*Sol, 2) == 2) && *allTimes == 0)
        {
            solBr(*Sol)++;
            *allTimes = 1;
            if (Calculate(*Sol) == 24.0)
            {
                AddArray(AS, *Sol);
            }
        }
        else if ((solOp(*Sol, 0) == 2 && solOp(*Sol, 1) == 2 && solOp(*Sol, 2) == 2) && *allAdd == 1)
        {
            continue;
        }
        else
        {
            for (j = 0; j < 11; j++)
            {
                solBr(*Sol)++;
                if (Calculate(*Sol) == 24.0)
                {
                    AddArray(AS, *Sol);
                }
            }
        }
    }
}