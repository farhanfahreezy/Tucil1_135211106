#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "solution.h"

void CreateSolution(Solution *Sol, Cards solCard, int op1, int op2, int op3, int br1, int br2, int br3, int br4, int br5, int br6, int br7, int br8, int br9, int br10)
{
    (*Sol).solCard = solCard;

    (*Sol).op[0] = op1;
    (*Sol).op[1] = op2;
    (*Sol).op[2] = op3;

    (*Sol).brackets[0] = br1;
    (*Sol).brackets[1] = br2;
    (*Sol).brackets[2] = br3;
    (*Sol).brackets[3] = br4;
    (*Sol).brackets[4] = br5;
    (*Sol).brackets[5] = br6;
    (*Sol).brackets[6] = br7;
    (*Sol).brackets[7] = br8;
    (*Sol).brackets[8] = br9;
    (*Sol).brackets[9] = br10;
}

void CopySolution(Solution SolIn, Solution *SolOut)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (i < 3)
        {
            solOp(*SolOut, i) = solOp(SolIn, i);
        }
        if (i < 4)
        {
            solCard(*SolOut, i) = solCard(SolIn, i);
        }
        solBr(*SolOut, i) = solBr(SolIn, i);
    }
}
void PrintSolution(Solution Sol)
{
    if (solBr(Sol, 0) == 1)
    {
        printf("( ");
    }
    if (solBr(Sol, 1) == 1)
    {
        printf("( ");
    }
    PrintCardsInt(solCard(Sol, 0));
    printf(" ");
    PrintOp(solOp(Sol, 0));
    printf(" ");
    if (solBr(Sol, 2) == 1)
    {
        printf("( ");
    }
    if (solBr(Sol, 3) == 1)
    {
        printf("( ");
    }
    PrintCardsInt(solCard(Sol, 1));
    printf(" ");
    if (solBr(Sol, 4) == 1)
    {
        printf(") ");
    }
    PrintOp(solOp(Sol, 1));
    printf(" ");
    if (solBr(Sol, 5) == 1)
    {
        printf("( ");
    }
    PrintCardsInt(solCard(Sol, 2));
    printf(" ");
    if (solBr(Sol, 6) == 1)
    {
        printf(") ");
    }
    if (solBr(Sol, 7) == 1)
    {
        printf(") ");
    }
    PrintOp(solOp(Sol, 2));
    printf(" ");
    PrintCardsInt(solCard(Sol, 3));
    printf(" ");
    if (solBr(Sol, 8) == 1)
    {
        printf(") ");
    }
    if (solBr(Sol, 9) == 1)
    {
        printf(") ");
    }
    printf("\n");

    // . . a + . . b . + . c . . + d . .
    // 0 1 0 0 2 3 1 4 1 5 2 6 7 2 3 8 9
}

void PrintOp(int op)
{
    switch (op)
    {
    case 0:
        printf("+");
        break;
    case 1:
        printf("-");
        break;
    case 2:
        printf("x");
        break;
    case 3:
        printf("/");
        break;
    default:
        break;
    }
}

float Calculate(Solution Sol)
{
    float frac[3];
    if (solBr(Sol, 1) == 1 && solBr(Sol, 4) == 1)
    {
        if (solBr(Sol, 5) == 1 && solBr(Sol, 8) == 1)
        {
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), solCard(Sol, 1));
            frac[2] = Calculate2Card(solOp(Sol, 2), solCard(Sol, 2), solCard(Sol, 3));
            return Calculate2Card(solOp(Sol, 1), frac[0], frac[2]);
        }
        else if (solBr(Sol, 0) == 1 && solBr(Sol, 7) == 1)
        {
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), solCard(Sol, 1));
            frac[1] = Calculate2Card(solOp(Sol, 1), frac[0], solCard(Sol, 2));
            return Calculate2Card(solOp(Sol, 2), frac[1], solOp(Sol, 3));
        }
        else
        {
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), solCard(Sol, 1));
            return Calculate3Card(solOp(Sol, 1), solOp(Sol, 2), frac[0], solCard(Sol, 2), solCard(Sol, 3));
        }
    }
    else if (solBr(Sol, 3) == 1 && solBr(Sol, 6) == 1)
    {
        if (solBr(Sol, 0) == 1 && solBr(Sol, 7) == 1)
        {
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), solCard(Sol, 2));
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), frac[1]);
            return Calculate2Card(solOp(Sol, 2), frac[0], solCard(Sol, 3));
        }
        else if (solBr(Sol, 2) == 1 && solBr(Sol, 9) == 1)
        {
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), solCard(Sol, 2));
            frac[2] = Calculate2Card(solOp(Sol, 2), frac[1], solCard(Sol, 3));
            return Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), frac[2]);
        }
        else
        {
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), solCard(Sol, 2));
            return Calculate3Card(solOp(Sol, 0), solOp(Sol, 2), solCard(Sol, 0), frac[1], solCard(Sol, 3));
        }
    }
    else if (solBr(Sol, 5) == 1 && solBr(Sol, 8) == 1)
    {
        if (solBr(Sol, 2) == 1 && solBr(Sol, 9) == 1)
        {
            frac[2] = Calculate2Card(solOp(Sol, 2), solCard(Sol, 2), solCard(Sol, 3));
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), frac[2]);
            return Calculate2Card(solOp(Sol, 0), solOp(Sol, 0), frac[1]);
        }
        else
        {
            frac[2] = Calculate2Card(solOp(Sol, 2), solCard(Sol, 2), solCard(Sol, 3));
            return Calculate3Card(solOp(Sol, 0), solOp(Sol, 1), solCard(Sol, 0), solCard(Sol, 1), frac[2]);
        }
    }
    else if (solBr(Sol, 0) == 1 && solBr(Sol, 7) == 1)
    {
        frac[0] = Calculate3Card(solOp(Sol, 0), solOp(Sol, 1), solCard(Sol, 0), solCard(Sol, 1), solCard(Sol, 2));
        return Calculate2Card(solOp(Sol, 2), frac[0], solCard(Sol, 3));
    }
    else if (solBr(Sol, 2) == 1 && solBr(Sol, 9) == 1)
    {
        frac[1] = Calculate3Card(solOp(Sol, 1), solOp(Sol, 2), solCard(Sol, 1), solCard(Sol, 2), solCard(Sol, 3));
        return Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), frac[1]);
    }
    else
    {
        return Calculate4Card(solOp(Sol, 0), solOp(Sol, 1), solOp(Sol, 2), solCard(Sol, 0), solCard(Sol, 1), solCard(Sol, 2), solCard(Sol, 3));
    }
}

float Calculate4Card(int op1, int op2, int op3, float c1, float c2, float c3, float c4)
{
    float frac;
    if ((op2 == 0 || op2 == 1) && (op3 == 2 || op3 == 3))
    {
        frac = Calculate2Card(op3, c3, c4);
        return Calculate3Card(op1, op2, c1, c2, frac);
    }
    else if ((op1 == 0 || op1 == 1) && (op2 == 2 || op2 == 3) && (op3 == 0 || op3 == 1))
    {
        frac = Calculate2Card(op2, c2, c3);
        return Calculate3Card(op1, op3, c1, frac, c4);
    }
    else if ((op1 == 0 || op1 == 1) && (op2 == 2 || op2 == 3) && (op3 == 2 || op3 == 3))
    {
        frac = Calculate2Card(op2, c2, c3);
        frac = Calculate2Card(op3, frac, c4);
        return Calculate2Card(op1, c1, frac);
    }
    else
    {
        frac = Calculate2Card(op1, c1, c2);
        frac = Calculate2Card(op2, frac, c3);
        return Calculate2Card(op2, frac, c4);
    }
}

float Calculate3Card(int op1, int op2, float c1, float c2, float c3)
{
    float frac;
    if ((op1 == 0 || op1 == 1) && (op2 == 2 || op2 == 3))
    {
        frac = Calculate2Card(op2, c2, c3);
        return Calculate2Card(op1, c1, frac);
    }
    else
    {
        frac = Calculate2Card(op1, c1, c2);
        return Calculate2Card(op2, frac, c3);
    }
}

float Calculate2Card(int op, float c1, float c2)
{
    switch (op)
    {
    case 0:
        return c1 + c2;
        break;
    case 1:
        return c1 - c2;
        break;
    case 2:
        return c1 * c2;
        break;
    case 3:
        return c1 / c2;
        break;
    default:
        break;
    }
}