/****************************************************************************
 *
 * torri.c -- Torri sotto attacco
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
% LabASD - Torri sotto attacco
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: LASTUPDATED

Nel gioco degli scacchi, la torre è in grado di attaccare un altro
pezzo che occupi la stessa riga oppure la stessa colonna. 

Questo programma legge da standard input (o da file) un intero $n$ e
una matrice di caratteri di dimensioni $n \times n$, con $1 \leq n
\leq 100$. La matrice viene letta riga per riga. Ogni riga contiene
$n$ caratteri, ciascuno dei quali può essere `.` per indicare una
casella vuota, oppure `T` per indicare che sulla casella è presente
una torre.

Il programma deve stampare `ATTACCO` se e solo se le torri
eventualmente presenti sulla scacchiera sono disposte in modo tale da
non attaccarsi a vicenda, `NO ATTACCO` altrimenti. Formalmente, il
programma deve stampare `NO ATTACCO` se e solo se valgono _entrambe_
le condizioni seguenti:

1. Ogni riga della scacchiera $n \times n$ contiene al più un
   carattere `T` (cioè zero o un carattere `T`);
 
2. Ogni colonna della scacchiera $n \times n$ contiene al più un
   carattere `T` (cioè zero o un carattere `T`);

Ad esempio, data questa configurazione:

```
8
T.......
.T......
........
........
T.......
.....T..
....T...
.......T
```

il programma deve stampare `ATTACCO`, in quanto nella prima colonna
a sinistra ci sono due `T`.

Se la configurazione fosse:

```
8
T.......
.T......
........
........
........
.....T..
....T...
.......T
```

allora il programma stampa `NO ATTACCO`.

Viene fornito un programma [torri.c](torri.c) e alcuni casi di
test. Se lo si ritiene opportuno è possibile definire ulteriori
funzioni di supporto.

## File

- [torri.c](torri.c)
- [torri1.in](torri1.in), [torri2.in](torri2.in), [torri3.in](torri3.in)

***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N 100

int main(int argc, char *argv[])
{
    // initializing matrix n*n (100*100)
    char s[N][N];
    FILE *filein = stdin;
    int n;

    // valid number of arguments
    if (argc > 1)
    {
        // opening file in read mode
        filein = fopen(argv[1], "r");
        // if we can't open file
        if (filein == NULL)
        {
            // rip
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    //gets first character (n) -> #rows #columns
    fscanf(filein, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(filein, "%s", &s[i][0]);
        assert(strlen(s[i]) == n);
    }

    /* TODO: completare il programma */


    return EXIT_SUCCESS;
}
