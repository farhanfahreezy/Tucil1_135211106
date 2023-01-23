#ifndef SOLUTION_H
#define SOLUTION_H

#include "../boolean.h"
#include "../Cards/cards.h"

typedef struct
{
    Cards solCard;
    int op[3];
    int brackets[10];
} Solution;

#define solCard(Sol, N) card((Sol).solCard, N)
#define solOp(Sol, N) (Sol).op[N]
#define solBr(Sol, N) (Sol).brackets[N]

void CreateSolution(Solution *Sol, Cards solCard, int op1, int op2, int op3, int br1, int br2, int br3, int br4, int br5, int br6, int br7, int br8, int br9, int br10);

void CopySolution(Solution SolIn, Solution *SolOut);

void PrintSolution(Solution Sol);

void PrintOp(int op);

float Calculate(Solution Sol);

float Calculate4Card(int op1, int op2, int op3, float c1, float c2, float c3, float c4);

float Calculate3Card(int op1, int op2, float c1, float c2, float c3);

float Calculate2Card(int op, float c1, float c2);

#endif