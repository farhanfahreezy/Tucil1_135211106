#include <stdio.h>
#include <string.h>
#include "arraySolution.h"

int main()
{
    Cards AC;
    Solution S1;
    ArraySolution AS;
    CreateArraySolution(&AS, 100);
    GenerateCards(&AC);

    CreateSolution(&S1, AC);
    AddArray(&AS, S1);
    CreateSolution(&S1, AC);
    AddArray(&AS, S1);
    printf("Solusi anda Adalah : \n");
    PrintArraySolution(AS);
}

// gcc -o main src\ArraySolution\driverAS.c src\Solution\solution.c src\Cards\cards.c src\ArraySolution\arraySolution.c