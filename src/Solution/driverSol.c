#include <stdio.h>
#include <string.h>
#include "solution.h"

int main()
{
    Cards AC;
    Solution S1;
    Solution S2;
    GenerateCards(&AC);
    CreateSolution(&S1, AC, 1, 2, 3, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1);

    printf("Solusi anda Adalah : \n");
    PrintSolution(S1);
    CopySolution(S1, &S2);
    PrintSolution(S2);
}

// gcc -o main src\Cards\cards.c src\Cards\driverAC.c

// . . a + . . b . + . c . . + d . .
// 0 1 0 0 2 3 1 4 1 5 2 6 7 2 3 8 9
// . . a + ( . b . + ( c . . + d ) )