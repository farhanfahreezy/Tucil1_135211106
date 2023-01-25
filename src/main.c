#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "ArraySolution/arraySolution.h"
#include "Cards/cards.h"
#include "Solution/solution.h"

void WritetoTxt(ArraySolution AS)
{
    int i;
    char *Filename = "doc/Sool.txt";
    FILE *file = fopen(Filename, "w");
    if (file == NULL)
    {
        printf("Tidak ada folder bernama. %s", Filename);
        return;
    }
    for (i = 0; i < Neff(AS); i++)
    {
        SolToString(AS.ArrSol[i], file);
    }

    fclose(file);
}

void Solver24(Cards AC)
{
    clock_t start, end;
    start = clock();

    int Choice;
    Solution Sol, SolC;
    ArraySolution AS;
    int ArrayPermutation[24];
    CreateSolution(&Sol, AC);
    CreateArraySolution(&AS, 1000);
    EmptyPermutationArray(ArrayPermutation);

    printf("Kartu anda adalah : \n");
    PrintCards(AC);

    LexicographicPermutation(&AS, &Sol, ArrayPermutation);

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    printf("\n\nDitemukan %d Solusi!\n", Neff(AS));
    PrintArraySolution(AS);
    printf("\n");
    printf("Waktu eksekusi : %f", duration);
    printf("\n");
    printf("Apakah Solusi ingin disimpan?\n");
    printf("(1) Ya\n(2) Tidak\n");
    scanf("%d", &Choice);
    if (Choice == 1)
    {
        WritetoTxt(AS);
    }
}

int main()
{
    Cards AC;
    int Choice;
    printf("24-Solver\n");
    printf("(1) Masukkan Kartu\n");
    printf("(2) Generate Kartu\n");
    printf("(3) Keluar\n");
    while (Choice < 1 || Choice > 3)
    {
        printf("Masukkan pilihan : ");
        scanf("%d", &Choice);
        if (Choice < 1 || Choice > 3)
        {
            printf("Input tidak sesuai!\nSilahkah Ulangi Input.\n\n");
        }
    }

    if (Choice == 1)
    {
        scanf("\n", &Choice);
        ReadCards(&AC);
    }
    else if (Choice == 2)
    {
        GenerateCards(&AC);
    }
    else
    {
        printf("Program Selesai.\n");
        return 0;
    }
    Solver24(AC);
    printf("\nTerimakasih\n");

    return 0;
}

// gcc -o main src\main.c src\Solution\solution.c src\Cards\cards.c src\ArraySolution\arraySolution.c