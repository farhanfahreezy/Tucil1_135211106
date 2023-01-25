#include <stdio.h>
#include <string.h>
#include "solution.h"

int main()
{
    Cards AC;
    Solution S1;
    Solution S2;
    GenerateCards(&AC);
    printf("Solusi anda Adalah : \n");
    CreateSolution(&S1, AC);
    printf("%.0f = ", Calculate(S1));
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    PrintSolution(S1);
    NextOp(&S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
    // CreateSolution(&S1, AC, 1, 2, 3, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1);
    // printf("%.0f = ", Calculate(S1));
    // PrintSolution(S1);
}

// gcc -o main src\Solution\driverSol.c src\Solution\solution.c src\Cards\cards.c

// . . a + . . b . + . c . . + d . .
// 0 1 0 0 2 3 1 4 1 5 2 6 7 2 3 8 9
// . . a + ( . b . + ( c . . + d ) )

// . ( a + . . b ) + . c . . + d . .    0, 1, 0, 0, 1, 0, 0, 0, 0, 0
// . . a + . ( b . + . c ) . + d . .    0, 0, 0, 1, 0, 0, 1, 0, 0, 0
// . . a + . . b . + ( c . . + d ) .    0, 0, 0, 0, 0, 1, 0, 0, 1, 0
// . ( a + . . b ) + ( c . . + d ) .    0, 1, 0, 0, 1, 1, 0, 0, 1, 0
// ( . a + . . b . + . c . ) + d . .    1, 0, 0, 0, 0, 0, 0, 1, 0, 0
// . . a + ( . b . + . c . . + d . )    0, 0, 1, 0, 0, 0, 0, 0, 0, 1
// ( ( a + . . b ) + . c . ) + d . .    1, 1, 0, 0, 1, 0, 0, 1, 0, 0
// ( . a + . ( b . + . c ) ) + d . .    1, 0, 0, 1, 0, 0, 1, 1, 0, 0
// . . a + ( ( b . + . c ) . + d . )    0, 0, 1, 1, 0, 0, 1, 0, 0, 1
// . . a + ( . b . + ( c . . + d ) )    0, 0, 1, 0, 0, 1, 0, 0, 1, 1