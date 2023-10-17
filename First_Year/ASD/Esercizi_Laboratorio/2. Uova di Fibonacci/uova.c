/****************************************************************************
 *
 * uova.c -- Problema delle uova di Fibonacci
 *
 * Copyright (C) 2021 Moreno Marzolla
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/***
% LabASD - Il problema delle uova di Fibonacci
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: LASTUPDATED

Questo problema è un esercizio contenuto nel [Liber
Abbaci](https://it.wikipedia.org/wiki/Liber_abbaci) scritto nel 1202
da [Leonardo Pisano detto
Fibonacci](https://it.wikipedia.org/wiki/Leonardo_Fibonacci). Espresso
in forma moderna, il problema è il seguente:

> Un grosso cesto contiene delle uova. Il numero di uova, $n$, gode
> delle seguenti proprietà: se si contano le uova due a due, oppure
> tre a tre, oppure quattro a quattro, oppure cinque a cinque, oppure
> sei a sei, allora alla fine del conteggio ne resta una.  Se invece
> si contano le uova sette a sette, alla fine del conteggio non ne
> rimane nessuna.

Scrivere un programma che calcoli e stampi il minimo valore intero
positivo $n$ che gode delle proprietà precedenti.

![Leonardo Pisano detto Fibonacci (c. 1170-c. 1240)](Fibonacci.jpg)

## File

- [uova.c](uova.c)

***/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int try = 0;
    while (1)
    {
        if ((try % 2 == 1) &&
            (try % 3 == 1) &&
            (try % 4 == 1) && 
            (try % 5 == 1) && 
            (try % 6 == 1) && 
            (try % 7 == 0))
            break;
        else
            try++;
    }
    printf("The number of eggs is %d", try);
    system("pause");
    return 0;
}
