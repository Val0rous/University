/****************************************************************************
 *
 * resto-greedy.c -- Il problema del resto (soluzione greedy)
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
% LabASD - Il problema del resto
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-15

Disponiamo di $n$ monete di valori interi rispettivamente $m_0,
\ldots, m_{n-1}$. Supponiamo che le monete appartengano ad un [sistema
monetario canonico](https://arxiv.org/pdf/0809.0400), cioè un sistema
monetario per il quale l'algorimo _greedy_ che descriviamo a breve
produce la soluzione ottima. Dobbiamo erogare un resto $R$ usando il
minor numero possibile di monete. Scivere un programma che determina
se ciò è possibile, e in caso affermativo elenca quali monete fanno
parte della soluzione ottima. Ogni moneta può essere usata al massimo
una volta, ma possono essere presenti più monete con lo stesso valore.
 
Per i sistemi monetari _canonici_ esiste un semplice algoritmo greedy,
che consiste nel considerare le monete in ordine _decrescente_ di
valore. Se il resto ancora da erogare è maggiore o uguale al valore
della moneta, allora la usiamo, altrimenti la scartiamo e passiamo
alla moneta successiva.

Supponiamo ad esempio di disporre delle nove monete seguenti:

50, 50, 20, 10, 10, 10, 5, 2, 1

e vogliamo erogare un resto $R=86$. La tabella seguente mostra il
comportamento dell'algoritmo greedy: la colonna "Residuo" indica il
resto ancora da erogare; la colonna "Moneta" indica il valore della
moneta che stiamo consideranto; infine, la colonna "Usata?" indica se
usiamo la moneta o la scartiamo.

:Esempio problema del resto

Residuo  Moneta   Usata?  
-------- -------- --------
86       50       sì
36       50       no
36       20       sì
16       10       sì
6        10       no
6        10       no
6        5        sì
1        2        no
1        1        sì
0

Quindi, il numero minimo di monete necessarie per erogare il resto è
5.

Il programma legge i parametri di input dallo standard input o da file
secondo il formato seguente:

```
R n
m[0]
...
m[n-1]
```

I valori delle monete non sono necessariamente ordinati. Per ordinarli
si può usare un qualunque algoritmo di ordinamento efficiente visto a
lezione, oppure si può usare la funzione `qsort()` dichiarata
nell'header file `<stdlib.h>`. La segnatura della funzione è la
seguente:

```C
#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size,
           int (*compare)(const void *, const void *));
```

dove:

- `base` è un puntatore all'inizio dell'array da ordinare;

- `nmemb` è il numero di elementi dell'array da ordinare (attenzione,
  non il numero di byte!)

- `size` è la dimensione in byte di ciascuno degli elementi dell'array

- `compare` è un puntatore ad una funzione che accetta due parametri
  di tipo `const void *` e restituisce un `int`. Il risultato deve
  essere negativo se il primo parametro è "minore" del secondo,
  positivo se il primo parametro è "maggiore" del secondo, e zero se i
  parametri hanno lo stesso valore.

Occorre prestare attenzione alla funzione di confronto.  Dobbiamo
infatti ordinare le monete in senso _decrescente_ di valore; di
conseguenza, la funzione di confronto deve restituire un valore
negativo se il primo parametro è **maggiore** del secondo, un valore
positivo se il primo parametro è **minore** del secondo, e zero se
sono uguali.

:Esempi

+---------+------------------------------------------------------+
|Input    |Output                                                |
+=========+======================================================+
|```      |```                                                   |
|13 8     |Resto 13 erogabile con 3 monete:                      |
|20       |10 2 1                                                |
|20       |```                                                   |
|20       |                                                      |
|10       |                                                      |
|5        |                                                      |
|2        |                                                      |
|1        |                                                      |
|1        |                                                      |
|```      |                                                      |
+---------+------------------------------------------------------+
|```      |```                                                   |
|27 4     |Resto 27 non erogabile con le monete a disposizione   |
|50       |```                                                   |
|1        |                                                      |
|5        |                                                      |
|20       |                                                      |
|```      |                                                      |
+---------+------------------------------------------------------+

## File

- [resto-greedy.c](resto-greedy.c)
- [resto-greedy1.in](resto-greedy1.in) ([risultato atteso](resto-greedy1.out))
- [resto-greedy2.in](resto-greedy2.in)
- [resto-greedy3.in](resto-greedy3.in)
- [resto-greedy4.in](resto-greedy4.in)

***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/* Date n monete i cui valori sono memorizzati nell'array m[] (non
   necessariamente ordinato), restituisce il minimo numero di pezzi
   necessari per erogare un resto R. Se il resto non è erogabile
   restituisce -1. La funzione deve anche stampare quali monete devono
   essere usate, se possibile. */
int resto(int R, int m[], int n)
{
    /* [TODO] */
    return -1;
}

int main( int argc, char *argv[] )
{
    int R, n, i;
    int *m;
    FILE *filein = stdin;

    if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    fscanf(filein, "%d %d", &R, &n);
    m = (int*)malloc(n * sizeof(*m));
    assert(m != NULL);
    for (i=0; i<n; i++) {
        if (1 != fscanf(filein, "%d", &m[i])) {
            fprintf(stderr, "Errore durante la lettura della moneta %d\n", i);
            return EXIT_FAILURE;
        }
    }

    resto(R, m, n);
    free(m);

    return EXIT_SUCCESS;
}
