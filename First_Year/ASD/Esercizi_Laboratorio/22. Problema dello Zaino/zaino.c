/****************************************************************************
 *
 * zaino.c -- Problema dello zaino 0-1
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
% LabASD - Problema dello zaino 0-1
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-23

![](zaino.png)

Risolviamo il problema dello zaino 0-1 utilizzando la programmazione
dinamica. Disponiamo di $n$ oggetti di pesi interi $p_0, \ldots,
p_{n-1}$ e valori reali $v_0, \ldots, v_{n-1}$. Vogliamo determinare
il sottoinsieme di oggetti di peso complessivo minore o uguale a $C$
il cui valore totale sia massimo possibile.

Il programma legge i dati di input da standard input secondo il
seguente formato:

```
C n
p[0]   v[0]
...
p[n-1] v[n-1]
```

## Suggerimento

Questo problema si risolve usando la programmazione dinamica. Per
farlo, consideriamo la famiglia di problemi $P(i,j)$, $i=0, \ldots,
(n-1)$, $j=0, \ldots, C$ definiti nel modo seguente:

> $P(i,j)$ consiste nel determinare il sottoinsieme degli oggetti
> scelti tra $\{0, \ldots, i\}$ aventi peso complessivo minore o
> uguale a $j$ e valore totale massimo possibile.

La soluzione del nostro problema è $P(n-1, C)$.

Sia $V(i,j)$ la soluzione di $P(i,j)$; in altre parole, $V(i,j)$ è il
massimo valore ottenibile da un opportuno sottoinsieme di oggetti
scelti tra $\{0, \ldots, i\}$ il cui peso totale sia minore o uguale a
$j$.

Sappiamo che $V(i,0) = 0$ per ogni $i$ (in un contenitore di capienza
zero non possiamo inserire alcun oggetto, per cui il valore totale
sarà zero).

Che cosa possiamo dire di $V(0,j)$? Avendo a disposizione solo il
primo oggetto, di peso $p_0$ e valore $v_0$, l'unica scelta è di
usarlo oppure no. Lo possiamo inserire nel contenitore se la capienza
$j$ è maggiore o uguale a $p_0$, e in tal caso il valore massimo
ottenibile è $v_0$. Possiamo quindi scrivere:

$$
V(0,j) = \begin{cases}
0 & \mbox{se}\ j < p_0\\
v_0 & \mbox{altrimenti}
\end{cases}
$$

Cosa possiamo dire di $V(i,j)$ nel caso generale? Supponiamo di
conoscere le soluzioni di tutti i problemi "più piccoli", e
concentriamoci sull'oggetto $i$-esimo. Abbiamo due possibilità:

1. Se il peso $p_i$ dell'oggetto $i$ è maggiore della capienza $j$,
   allora sicuramente non possiamo inserirlo nello zaino.  Di
   conseguenza il valore ottimo della soluzione $V(i,j)$ coincide con
   il valore della soluzione $V(i-1, j)$, in cui  ci limitiamo
   a scegliere tra gli oggetti $\{0, 1, \ldots, i-1\}$:

2. Se il peso $p_i$ dell'oggetto $i$ è minore o uguale alla capienza
   $j$, allora potremmo usarlo oppure no.

    a. Se usiamo l'oggetto $i$, il valore massimo degli oggetti nello
       zaino sarà uguale a $v_i$ più il valore massimo che possiamo
       ottenere inserendo un sottoinsieme dei rimanenti $i-1$ oggetti
       nel contenitore, che a questo punto ha capienza residua $j -
       p_i$. Quindi, se usiamo l'oggetto $i$, il valore massimo
       ottenibile è $V(i-1,j-p_i)+v_i$.

    b. Se non usiamo l'oggetto $i$, il valore massimo ottenibile è
       $V(i-1,j)$ (come il caso 1 sopra).

Tra le due opzioni 2.a e 2.b scegliamo quella che produce il valore
massimo. Otteniamo quindi la seguente relazione generale, che vale per
ogni $i=1, \ldots, (n-1)$, $j=0, \ldots, C$:

$$
V(i,j) = \begin{cases}
V(i-1, j) & \mbox{se}\ j < p_i\\
\max\{V(i-1, j), V(i-1, j-p_i) + v_i\} & \mbox{altrimenti}
\end{cases}
$$

## File

- [zaino.c](zaino.c)
- [zaino.in](zaino.in) ([soluzione ottima](zaino.out))
- [zaino1.in](zaino1.in)
- [zaino2.in](zaino2.in)
- [zaino3.in](zaino3.in)

***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Non è una buona pratica di programmazione, ma usiamo ugualmente
   variabili globali per evitare di passare parametri alle funzioni.
   Questo può essere accettabile vista la relativa semplicità di
   questo programma. */

int *p;         /* p[i] è il peso dell'oggetto i-esimo */
double *v;      /* v[i] è il valore dell'oggetto i-esimo */
int n;          /* numero di oggetti */
int C;          /* capienza dello zaino */
double **V;     /* V[i][j] è il valore massimo ottenibile inserendo
                   un opportuno sottoinsieme degli oggetti {0, ... i}
                   in un contenitore di capienza massima C. */
int **use;      /* use[i][j] = 1 se e solo se l'oggetto i-esimo fa
                   parte della soluzione ottima del problema
                   P(i,j). */
FILE *filein;

/* Legge l'input dal file `filein` */
void init( void )
{
    int i;
    fscanf(filein, "%d %d", &C, &n);
    p = (int*)malloc(n * sizeof(*p)); assert(p != NULL);
    v = (double*)malloc(n * sizeof(*v)); assert(v != NULL);
    for ( i=0; i<n; i++ ) {
        fscanf(filein, "%d %lf", &p[i], &v[i]);
    }
}

/* Determina la soluzione ottima del problema dello zaino.
   Restituisce il valore massimo degli oggetti selezionati. */
double solve( void )
{
    /* [TODO] */
    return 0.0;
}

/* Stampa la soluzione del problema dello zaino, elencando gli oggetti
   selezionati e il loro valore complessivo. */
void print( void )
{
    /* [TODO] */
}


/* Dealloca tutta la memoria allocata dinamicamente. */
void destroy( void )
{
    free(p);
    free(v);
    /* [TODO]: Liberare ogni altro blocco di memoria allocato con malloc() */
}

int main( int argc, char *argv[] )
{
    filein = stdin;

    if (argc == 2) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    init( );
    (void)solve( ); /* il cast a void serve a evitare possibil warning da compilatori particolarmente pignoli che si accorgono che non usiamo il valore di ritorno di questa funzione */
    print( );
    destroy( );
    return EXIT_SUCCESS;
}
