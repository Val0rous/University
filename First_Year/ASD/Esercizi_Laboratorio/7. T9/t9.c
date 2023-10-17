/****************************************************************************
 *
 * t9.c -- Codifica T9
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
% LabASD - T9
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-02-27

Realizzare una funzione `t9()` secondo le specifiche seguenti. La
funzione accetta in input una stringa `s` composta esclusivamente
dalle lettere minuscole `a`...`z`. La funzione restituisce un
puntatore ad una nuova stringa, allocata con `malloc()`, avente la
stessa lunghezza di `s`. Tale stringa deve essere composta dai
caratteri `2`...`9` in modo tale che ad ogni lettera di `s`
corrisponda un carattere numerico secondo la codifica seguente:

Ognuno dei caratteri    corrisponde a          
----------------------  ---------------
`abc`                   `2`
`def`                   `3`
`ghi`                   `4`
`jkl`                   `5`
`mno`                   `6`
`pqrs`                  `7`
`tuv`                   `8`
`wxyz`                  `9`
---------------------   --------------

Quindi i caratteri `a`, `b` e `c` vengono rappresentati da un singolo
carattere `2`, i caratteri `d`, `e`, `f` da un singolo carattere `3` e
così via. La codifica descritta sopra è quella utilizzata dal T9 dei
vecchi cellulari.

Il programma deve leggere una serie di stringhe da standard input, una
per riga e ciascuna avente lunghezza massima 99 caratteri, e stampare
le codifiche T9 corrispondenti. Le stringhe non contengono spazi.

Alcuni esempi:

La stringa      diventa 
--------------  -------------
`informatica`   `46367628422`
`algoritmi`     `254674864`
`ciao`          `2426`
--------------  -------------

Si noti che la codifica T9 non è invertibile, dato che esistono più
sequenze di caratteri che hanno la stessa codifica.

## File

- [t9.c](t9.c)
- [t9.in](t9.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *t9(char* s)
{
    return NULL;
}

#define LEN 100

int main( void )
{
    char s[LEN];
    /* NOTA: fare scanf() di una stringa espone ad un possibile buffer
       overflow. Noi ignoriamo il problema; in applicazioni vere è
       necessario prendere provvedimenti */
    while (1 == scanf("%s", s)) {
        char *t = t9(s);
        printf("%s\n", t);
        free(t);
    }
    return EXIT_SUCCESS;
}
