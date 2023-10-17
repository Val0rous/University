/****************************************************************************
 *
 * bilanciate.c --Parentesi bilanciate
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
% LabASD - Parentesi bilanciate
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: LASTUPDATED

Scrivere un programma che legge da standard input una sequenza di
righe, ciascuna contenente una stringa di caratteri di lunghezza
massima `(LEN-1)`; le stringhe non contengono spazi o tabulazioni. Per
ciascuna riga dell'input, il programma deve controllare se le
parentesi tonde eventualmente presenti sono bilanciate oppure no. Nel
caso in cui le parentesi siano bilanciate, il programma stampa
`BILANCIATE`, altrimenti stampa `NON BILANCIATE`. La stringa vuota si
considera bilanciata.

Alcuni esempi:

Input                            Output           
-------------------------------  ----------------
`abcdef`                         `BILANCIATE`
`AB((2x)cd())eF2()`              `BILANCIATE`
`(a+b)*(a-(b+f+g-(g/h)/(2*g)))`  `BILANCIATE`
`(((())))efGH2x(*))`             `NON BILANCIATE`
`(ab(cd(e(f*g)))`                `NON BILANCIATE`
`)(`                             `NON BILANCIATE`

Per compilare il programma:

        gcc -std=c90 -Wall -Wpedantic bilanciate.c -o bilanciate

Per eseguire:

        ./bilanciate < bilanciate.in

oppure

        ./bilanciate bilanciate.in

## File

- [bilanciate.c](bilanciate.c)
- [bilanciate.in](bilanciate.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

/* Ritorna 1 se le parentesi eventualmente presenti in s sono
   bilanciate, 0 altrimenti. */
int bilanciate(const char* s)
{
    return -1;
}

int main( int argc, char *argv[] )
{
    char s[LEN];
    FILE *filein = stdin;

     if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }
    
    while ( fgets(s, LEN, filein) ) {
        if ( bilanciate(s) ) {
            printf("BILANCIATE\n");
        } else {
            printf("NON BILANCIATE\n");
        }
    }

    return EXIT_SUCCESS;
}
