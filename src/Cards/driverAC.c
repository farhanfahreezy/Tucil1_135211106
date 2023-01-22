#include <stdio.h>
#include <string.h>
#include "cards.h"

int main()
{
    Cards AC;
    GenerateCards(&AC);
    printf("Kartu anda adalah : \n");
    PrintCards(AC);
}

// gcc -o main src\Cards\cards.c src\Cards\driverAC.c