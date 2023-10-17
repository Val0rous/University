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
% Ultimo aggiornamento: 2021-05-04

Nel gioco degli scacchi, la torre è in grado di attaccare un altro
pezzo che occupi la stessa riga oppure la stessa colonna.

![By Alan Light - Own work by the original uploader, CC BY-SA 3.0, <https://commons.wikimedia.org/w/index.php?curid=20299>](ChessSet.jpg)

Questo programma legge da standard input (o da file) un intero $n$ e
una matrice di caratteri di dimensioni $n \times n$, con $1 \leq n
\leq 100$. La matrice viene letta riga per riga. Ogni riga contiene
$n$ caratteri, ciascuno dei quali può essere `.` per indicare una
casella vuota, oppure `T` per indicare che sulla casella è presente
una torre.

Il programma deve stampare `ATTACCO` se e solo se le torri
eventualmente presenti sulla scacchiera sono disposte in modo tale che
ne esista almeno una coppia in grado di attaccarsi a vicenda, `NO
ATTACCO` altrimenti. Formalmente, il programma deve stampare `ATTACCO`
se e solo se vale _almeno una_ delle condizioni seguenti:

1. Esiste una riga della scacchiera che contiene almeno due caratteri
   `T`;

2. Esiste una colonna della scacchiera che contiene almeno due
   caratteri `T`.

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
- [torri1.in](torri1.in)
- [torri2.in](torri2.in)
- [torri3.in](torri3.in)
- [torri4.in](torri4.in)

***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N 100

int main( int argc, char *argv[] )
{
    char s[N][N];
    FILE *filein = stdin;
    int i, j, n;
    int r[N] = {0}, c[N] = {0};
    int attacco = 0;

    /* se passo due argomenti sulla riga di comando:

       ./torri n rho

       il programma genera una scacchiera casuale di dimensione data e
       con una data densità di torri. La densità rho è un valore reale
       compreso tra 0 (nessuna torre) e 1 (tutte torri). */
    if (argc == 3) {
        const double rho = atof(argv[2]);
        assert((rho >= 0.0) && (rho <= 1.0));
        n = atoi(argv[1]);
        assert(n <= N);
        printf("%d\n", n);
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                if (rand() / (double)RAND_MAX < rho)
                    printf("T");
                else
                    printf(".");
            }
            printf("\n");
        }
        return EXIT_SUCCESS;
    } else if (argc == 2) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    fscanf(filein, "%d", &n);
    for (i=0; i<n; i++) {
        fscanf(filein, "%s", &s[i][0]);
        assert( strlen(s[i]) == n);
    }

    /*
      I cicli mantengono le seguenti invarianti:
      per ogni 0 <= i < n, r[i] e' il numero di torri nella riga i;
      per ogni 0 <= j < n, c[j] e' il numero di torri nella colonna j;

      Questo consente di risolvere il problema in tempo O(n^2)
      e spazio aggiuntivo O(n)
    */
    for (i=0; i<n && !attacco; i++) {
        for (j=0; j<n && !attacco; j++) {
            /* L'if seguente serve a me per essere sicuro che i casi
               di test non contengano caratteri diversi da 'T' e
               punto. */
            if ((s[i][j] != 'T') && (s[i][j] != '.')) {
                fprintf(stderr, "Carattere '%x' non valido riga %d colonna %d\n", (unsigned int)s[i][j], i, j);
                return EXIT_FAILURE;
            }

            if (s[i][j] == 'T') {
                if (r[i]>0 || c[j]>0) {
                    attacco = 1;
                } else {
                    r[i] = c[j] = 1;
                }
            }
        }
    }
    if (attacco)
        printf("ATTACCO\n");
    else
        printf("NO ATTACCO\n");
    return EXIT_SUCCESS;
}
