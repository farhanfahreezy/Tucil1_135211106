#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "solution.h"

void CreateSolution(Solution *Sol, Cards solCard)
{
    (*Sol).solCard = solCard;

    (*Sol).op[0] = -1;
    (*Sol).op[1] = 0;
    (*Sol).op[2] = 0;

    (*Sol).brackets = -1;
}

void CopySolution(Solution SolIn, Solution *SolOut)
{
    int i;
    solBr(*SolOut) = solBr(SolIn);
    for (i = 0; i < 4; i++)
    {
        if (i < 3)
        {
            solOp(*SolOut, i) = solOp(SolIn, i);
        }
        solCard(*SolOut, i) = solCard(SolIn, i);
    }
}

void PrintSolution(Solution Sol)
{
    if (solBr(Sol) == 5 || solBr(Sol) == 7 || solBr(Sol) == 8)
    {
        printf("( ");
    }
    if (solBr(Sol) == 1 || solBr(Sol) == 7 || solBr(Sol) == 4)
    {
        printf("( ");
    }
    PrintCardsInt(solCard(Sol, 0));
    printf(" ");
    PrintOp(solOp(Sol, 0));
    printf(" ");
    if (solBr(Sol) == 6 || solBr(Sol) == 9 || solBr(Sol) == 10)
    {
        printf("( ");
    }
    if (solBr(Sol) == 2 || solBr(Sol) == 8 || solBr(Sol) == 9)
    {
        printf("( ");
    }
    PrintCardsInt(solCard(Sol, 1));
    printf(" ");
    if (solBr(Sol) == 1 || solBr(Sol) == 4 || solBr(Sol) == 7)
    {
        printf(") ");
    }
    PrintOp(solOp(Sol, 1));
    printf(" ");
    if (solBr(Sol) == 3 || solBr(Sol) == 4 || solBr(Sol) == 10)
    {
        printf("( ");
    }
    PrintCardsInt(solCard(Sol, 2));
    printf(" ");
    if (solBr(Sol) == 2 || solBr(Sol) == 8 || solBr(Sol) == 9)
    {
        printf(") ");
    }
    if (solBr(Sol) == 5 || solBr(Sol) == 7 || solBr(Sol) == 8)
    {
        printf(") ");
    }
    PrintOp(solOp(Sol, 2));
    printf(" ");
    PrintCardsInt(solCard(Sol, 3));
    printf(" ");
    if (solBr(Sol) == 3 || solBr(Sol) == 4 || solBr(Sol) == 10)
    {
        printf(") ");
    }
    if (solBr(Sol) == 6 || solBr(Sol) == 9 || solBr(Sol) == 10)
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
    float result;
    int br = solBr(Sol);
    switch (br)
    {
    case 0:
        result = Calculate4Card(solOp(Sol, 0), solOp(Sol, 1), solOp(Sol, 2), solCard(Sol, 0), solCard(Sol, 1), solCard(Sol, 2), solCard(Sol, 3));
        break;
    case 1:
        if (solOp(Sol, 0) == 2 || (Sol, 0) == 3)
        {
            result = 0;
        }
        else
        {
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), solCard(Sol, 1));
            result = Calculate3Card(solOp(Sol, 1), solOp(Sol, 2), frac[0], solCard(Sol, 2), solCard(Sol, 3));
        }
        break;
    case 2:
        if ((solOp(Sol, 1) == 2 || solOp(Sol, 1) == 3) && solOp(Sol, 0) != 3)
        {
            result = 0;
        }
        else
        {
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), solCard(Sol, 2));
            result = Calculate3Card(solOp(Sol, 0), solOp(Sol, 2), solCard(Sol, 0), frac[1], solCard(Sol, 3));
        }
        break;
    case 3:
        if ((solOp(Sol, 2) == 2 || solOp(Sol, 2) == 3) && solOp(Sol, 1) != 3)
        {
            result = 0;
        }
        else
        {
            frac[2] = Calculate2Card(solOp(Sol, 2), solCard(Sol, 2), solCard(Sol, 3));
            result = Calculate3Card(solOp(Sol, 0), solOp(Sol, 1), solCard(Sol, 0), solCard(Sol, 1), frac[2]);
        }
        break;
    case 4:
        if ((solOp(Sol, 2) == 2 || solOp(Sol, 2) == 3) && (solOp(Sol, 0) == 2 || solOp(Sol, 0) == 3) && solOp(Sol, 1) != 3)
        {
            result = 0;
        }
        else
        {
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), solCard(Sol, 1));
            frac[2] = Calculate2Card(solOp(Sol, 2), solCard(Sol, 2), solCard(Sol, 3));
            result = Calculate2Card(solOp(Sol, 1), frac[0], frac[2]);
        }
        break;
    case 5:
        if ((solOp(Sol, 0) == 2 || solOp(Sol, 0) == 3) && (solOp(Sol, 1) == 2 || solOp(Sol, 1) == 3))
        {
            result = 0;
        }
        else
        {
            frac[0] = Calculate3Card(solOp(Sol, 0), solOp(Sol, 1), solCard(Sol, 0), solCard(Sol, 1), solCard(Sol, 2));
            result = Calculate2Card(solOp(Sol, 2), frac[0], solCard(Sol, 3));
        }
        break;
    case 6:
        if ((solOp(Sol, 1) == 2 || solOp(Sol, 1) == 3) && (solOp(Sol, 2) == 2 || solOp(Sol, 2) == 3) && solOp(Sol, 0) != 3)
        {
            result = 0;
        }
        else
        {
            frac[1] = Calculate3Card(solOp(Sol, 1), solOp(Sol, 2), solCard(Sol, 1), solCard(Sol, 2), solCard(Sol, 3));
            result = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), frac[1]);
        }
        break;
    case 7:
        if ((solOp(Sol, 0) == 2 || solOp(Sol, 0) == 3))
        {
            result = 0;
        }
        else
        {
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), solCard(Sol, 1));
            frac[1] = Calculate2Card(solOp(Sol, 1), frac[0], solCard(Sol, 2));
            result = Calculate2Card(solOp(Sol, 2), frac[1], solOp(Sol, 3));
        }
        break;
    case 8:
        if (((solOp(Sol, 1) == 2 || solOp(Sol, 1) == 3) && solOp(Sol, 0) != 3) || (solOp(Sol, 0) == 0 && solOp(Sol, 1) == 0))
        {
            result = 0;
        }
        else
        {
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), solCard(Sol, 2));
            frac[0] = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), frac[1]);
            result = Calculate2Card(solOp(Sol, 2), frac[0], solCard(Sol, 3));
        }
        break;
    case 9:
        if ((solOp(Sol, 1) == 2 || solOp(Sol, 1) == 3))
        {
            result = 0;
        }
        else
        {
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), solCard(Sol, 2));
            frac[2] = Calculate2Card(solOp(Sol, 2), frac[1], solCard(Sol, 3));
            result = Calculate2Card(solOp(Sol, 0), solCard(Sol, 0), frac[2]);
        }
        break;
    case 10:
        if ((solOp(Sol, 2) == 2 || solOp(Sol, 2) == 3) && solOp(Sol, 1) != 3)
        {
            result = 0;
        }
        else
        {
            frac[2] = Calculate2Card(solOp(Sol, 2), solCard(Sol, 2), solCard(Sol, 3));
            frac[1] = Calculate2Card(solOp(Sol, 1), solCard(Sol, 1), frac[2]);
            result = Calculate2Card(solOp(Sol, 0), solOp(Sol, 0), frac[1]);
        }
        break;
    default:
        break;
    }
    return result;
}

float Calculate4Card(int op1, int op2, int op3, float c1, float c2, float c3, float c4)
{
    float frac;
    if ((op2 == 0 || op2 == 1) && (op3 == 2 || op3 == 3)) // kanan
    {
        frac = Calculate2Card(op3, c3, c4);
        return Calculate3Card(op1, op2, c1, c2, frac);
    }
    else if ((op1 == 0 || op1 == 1) && (op2 == 2 || op2 == 3) && (op3 == 0 || op3 == 1)) // tengah
    {
        frac = Calculate2Card(op2, c2, c3);
        return Calculate3Card(op1, op3, c1, frac, c4);
    }
    else if ((op1 == 0 || op1 == 1) && (op2 == 2 || op2 == 3) && (op3 == 2 || op3 == 3)) // tengah kanan
    {
        frac = Calculate2Card(op2, c2, c3);
        frac = Calculate2Card(op3, frac, c4);
        return Calculate2Card(op1, c1, frac);
    }
    else // lurus
    {
        frac = Calculate2Card(op1, c1, c2);
        frac = Calculate2Card(op2, frac, c3);
        return Calculate2Card(op3, frac, c4);
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

void NextOp(Solution *Sol)
{
    if (solOp(*Sol, 0) == 3)
    {
        solOp(*Sol, 0) = 0;
        if (solOp(*Sol, 1) == 3)
        {
            solOp(*Sol, 1) = 0;
            if (solOp(*Sol, 2) == 3)
            {
                solOp(*Sol, 2) = 0;
            }
            else
            {
                solOp(*Sol, 2)++;
            }
        }
        else
        {
            solOp(*Sol, 1)++;
        }
    }
    else
    {
        solOp(*Sol, 0)++;
    }
}

// 0 0 0 lurus
// 0 0 1 kanan
// 0 1 0 tengah
// 0 1 1 tengah kanan
// 1 0 0 lurus
// 1 0 1 kanan kiri
// 1 1 0 lurus
// 1 1 1 lurus
// lurus 4 ad
// kanan 2 ad
// tengah 1 ad
// tengah kanan 1 ad