/****************************************************************************
 *
 * mfset.c -- Strutture Merge-Find
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
% LabASD - Strutture Merge-Find
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-23

In questo esercizio implementiamo una struttura dati per insiemi
disgiunti, detta _struttura Merge-Find_ o _Union-Find_ o
_Up-Tree_. L'interfaccia è descritta nel file [mfset.h](mfset.h) e
viene implementata in [nfset.c](mfset.c).

Una struttura merge-find di dimensione $n$ è inizialmente costituita
da $n$ insiemi disgiunti $\{0\}, \{1\}, \ldots, \{n-1\}$; ogni insieme
è rappresentato da un albero. La foresta di alberi è realizzata con un
_vettore di padri_ `p[]`. Dato un elemento $x \in \{0, \ldots, n-1\}$,
`p[x]` denota il padre di $x$, se esiste. Nel caso in cui $x$ sia la
radice di un albero si può porre `p[x] = -1`.

Il programma [mfset-main.c](mfset-main.c) contiene una funzione
`main()` che legge da standard input (oppure da un file il cui nome
viene passato su riga di comando) una sequenza di comandi che
manipolano una struttura merge-find. I comandi riconosciuti sono i
seguenti (le lettere _in corsivo_ indicano valori numerici):

------------------------------------------------------------------
Comando       Significato
-----------   ----------------------------------------------------
_n_           Crea una struttura MF con _n_ nodi; questo comando
              è sempre il primo e compare una sola volta

`m` _i j_     Fonde gli insiemi contenenti _i_ e _j_

`q` _i j_     Determina se _i_ e _j_ appartengono allo
              stesso insieme
------------------------------------------------------------------

dove $n$ è un intero positivo, e $i, j$ sono interi compresi tra 0 e
$n-1$ (inclusi).

Per compilare il programma dalla riga di comando:

        gcc -std=c90 -Wall -Wpedantic mfset.c mfset-main.c -o mfset

Per eseguire:

        ./mfset-main < mfset.in

oppure:

        ./mfset-main mfset.in

## Per approfondire

Chi lo desidera può implementare qualche euristica tra quelle viste a
lezione. Ad esempio, l'euristica _union by rank_ consiste nel tenere
traccia dell'altezza di ciascun albero, e realizzare l'operazione
`mfset_merge()` facendo in modo che la radice dell'albero più basso
diventi figlia di quella dell'albero più alto.

L'altezza degli alberi può essere mantenuta nell'array ausiliario
`h[]` definito nella struttura `MFSet`:

```C
typedef struct {
    int n;
    int *p;
    int *h;
} MFSet;
```

`h[]` ha lunghezza $n$, e `h[x]` deve rappresentare l'altezza
dell'albero radicato in $x$, per ogni radice $x$.

## File

- [mfset.c](mfset.c)
- [mfset.h](mfset.h)
- [mfset-main.c](mfset-main.c)
- [mfset.in](mfset.in) ([output atteso](mfset.out))
- [mfset1.in](mfset1.in)
- [mfset2.in](mfset2.in)
- [mfset3.in](mfset3.in)

***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mfset.h"

void mfset_init(MFSet *s, int n)
{
    int i;

    assert(s != NULL);

    s->n = n;
    s->p = (int*)malloc(n * sizeof(*(s->p)));
    assert(s->p != NULL);
    s->h = NULL; /* Per iniziare suggerisco di ignorare questo array */
    for (i=0; i<n; i++) {
        s->p[i] = -1;
    }
}

void mfset_destroy(MFSet *s)
{
    assert(s != NULL);

    s->n = 0;
    free(s->p);
    s->p = NULL; /* Non necessario */
}

void mfset_merge(MFSet *s, int x, int y)
{
    /* [TODO] */
}

int mfset_find(MFSet *s, int x)
{
    /* [TODO] */
    return -1;
}
