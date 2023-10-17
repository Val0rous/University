//DEPRECATED

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int varInt;
    float varFloat;
    double varDouble;
    char varChar;
    int vet[5] = {10, 20, 30, 40, 50};

    int *pInt = &varInt;
    float *pFloat = &varFloat;
    double *pDouble = &varDouble;
    char *pChar = &varChar;
    int(*pvet)[5] = &vet;

    printf("\nInserisci il valore per la variabile intera varInt : ");
    scanf("%d", &varInt);
    fflush(stdin);
    printf("\nInserisci il valore per la variabile float varFloat : ");
    scanf("%f", &varFloat);
    fflush(stdin);
    printf("\nInserisci il valore per la variabile double varDouble : ");
    scanf("%lf", &varDouble);
    fflush(stdin);
    printf("\nInserisci il valore per la variabile char varChar : ");
    scanf("%c", &varChar);
    fflush(stdin);

    printf("\n\nAccesso diretto\n\n");
    printf("\nvarInt : %d", varInt);
    printf("\nvarFloat : %f", varFloat);
    printf("\nvarDouble : %lf", varDouble);
    printf("\nvarChar : %c", varChar);
    printf("\nvet : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d |", vet[i]);
    }
    printf("\n\nAccesso coi puntatori\n\n");
    printf("\n*pInt : %d", *pInt);
    printf("\n*pFloat : %f", *pInt);
    printf("\n*pDouble : %lf", *pDouble);
    printf("\n*pChar : %c", *pChar);
    printf("\n*vet : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  |", (*pvet)[i]);
    }

    printf("\nvarInt | indirizzo tramite variabile : %p e tramite puntatore :%p", &varInt, pInt);
    printf("\nvarFloat  |indirizzo tramite variabile : %p e tramite puntatore :%p", &varFloat, pFloat);
    printf("\nvarDouble | indirizzo tramite variabile : %p e tramite puntatore :%p", &varDouble, pDouble);
    printf("\nvarChar | indirizzo tramite variabile : %p e tramite puntatore :%p", &varChar, pChar);
    printf("\nvet | indirizzo tramite variabile : %p e tramite puntatore :%p", &vet, pvet);

    printf("\n\nIndirizzi puntatori\n\n");
    printf("\npInt : %p", &pInt);
    printf("\npFloat : %p", &pInt);
    printf("\npDouble : %p", &pDouble);
    printf("\npChar : %p", &pChar);
    printf("\npvet : %p", &pvet);

    return 0;
}