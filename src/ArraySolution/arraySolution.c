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