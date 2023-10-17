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
% Ultimo aggiornamento: 2021-03-25

Realizzare un programma che stampa tutte le parole presenti nel file
[wordlist.txt](wordlist.txt) che hanno la stessa codifica T9 di una
parola specificata sulla riga di comando.

La codifica T9 associa a ciascuna delle 26 lettere dell'alfabeto un
numero, come da tabella seguente:

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
----------------------  --------------

Quindi le lettere `a`, `b` e `c` vengono tutte codificate con il
singolo carattere `2`, le lettere `d`, `e`, `f` dal carattere `3` e
così via; non si fa distinzione tra lettere maiuscole e
minuscole. Questo tipo di codifica era utilizzato dai vecchi
cellulari.

Alcuni esempi:

La stringa      diventa 
--------------  -------------
`Informatica`   `46367628422`
`algoritmi`     `254674864`
`ciao`          `2426`
--------------  -------------

Si può assumere che le stringhe date in input a questo programma
abbiano lunghezza strettamente minore di `MAXLEN`, e che contengano
esclusivamente lettere maiuscole o minuscole; come detto sopra, non si
fa distinzione fra maiuscole e minuscole. Ricordiamo che per
convertire un carattere $c$ in minuscolo si può usare la funzione `int
tolower(int c)` dichiarata in `<ctype.h>`.

Alcuni esempi di esecuzione del programma:

+---------------------+-------------------------------------+
| Input               | Output                              |
+=====================+=====================================+
| `./t9 ciao`         | ```                                 |
|                     | ciao 2426                           |
|                     | cibo 2426                           |
|                     | 2 occorrenze                        |
|                     | ```                                 |
+---------------------+-------------------------------------+
| `./t9 tavolo`       | ```                                 |
|                     | tavolo 828656                       |
|                     | 1 occorrenza                        |
|                     | ```                                 |
+---------------------+-------------------------------------+
| `./t9 etna`         | ```                                 |
|                     | duna 3862                           |
|                     | etna 3862                           |
|                     | fuma 3862                           |
|                     | 3 occorrenze                        |
|                     | ```                                 |
+---------------------+-------------------------------------+
| `./t9 tablet`       | ```                                 |
|                     | 0 occorrenze                        |
|                     | ```                                 |
+---------------------+-------------------------------------+

Si noti che la parola specificata sulla riga di comando non deve
necessariamente comparire nel file `wordlist.txt`.

## File

- [t9.c](t9.c)
- [wordlist.txt](wordlist.txt)

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


#define MAXLEN 100

int main( int argc, char *argv[] )
{
    FILE *f;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s parola\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    if ((f = fopen("wordlist.txt", "r")) == NULL) {
        fprintf(stderr, "Errore nell'apertura di \"wordlist.txt\"\n");
        return EXIT_FAILURE;
    }

    /* TODO */
    fclose(f);
    return EXIT_SUCCESS;
}
