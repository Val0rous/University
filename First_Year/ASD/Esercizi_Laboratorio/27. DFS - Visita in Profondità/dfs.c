/****************************************************************************
 *
 * bfs.c -- Visita in profondità di grafi orientati
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
% LabASD - Visita in profondità (DFS)
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-13

Realizziamo l'algoritmo di visita in profondità (_Depth-First Search_,
DFS) di un grafo orientato $G=(V,E)$ con $n$ nodi e $m$ archi.  La
visita in profondità parte da un nodo $v$ ed esplora tutti i cammini
orientati "il più a lungo possibile". Attenzione: **la visita in
profondità non trova i cammini di lunghezza massima**.

In [questa pagina](https://bl.ocks.org/mbostock/949c772b81296f8e4188)
è presente una interessante visualizzazione dell'algoritmo DFS mentre
esplora un labirinto (che può essere descritto tramite un grafo).

Questa implementazione dell'algoritmo DFS segue quanto descritto nel
libro di testo, e visita l'intero grafo.  Per ogni nodo $v$ viene
calcolato l'istante `discover[v]` in cui il nodo viene incontrato per
la prima volta, e l'istante `finish[v]` in cui tutti i nodi
raggiungibili da $v$ sono stati esplorati. Si avrà sempre che
`discover[v]` $\leq$ `finish[v]`.

Durante la visita ogni nodo viene colorato di bianco, grigio o
nero. Tutti i nodi sono inizialmente bianchi, ad indicare che non sono
ancora stati visitati. Un nodo raggiunto per la prima volta viene
colorato di grigio; un nodo diventa nero quando sono esplorati tutti i
nodi da esso raggiungibili.

Sebbene l'algoritmo di visita in profondità possa essere realizzato in
modo iterativo con l'uso di una pila (stack), risulta più semplice
implementarlo in forma ricorsiva come mostrato sul libro.

Si suggerisce di iniziare ignorando gli array `discover[]` e
`finish[]`; sarà possibile calcolarne il valore in seguito.

Per compilare:

        gcc -std=c90 -Wall -Wpedantic graph.c dfs.c -o dfs

Per eseguire:

        ./dfs < graph10.in

oppure

        ./dfs graph10.in

## File

- [dfs.c](dfs.c)
- [graph.c](graph.c)
- [graph.h](graph.h)
- [graph10.in](graph10.in)
- [graph100.in](graph100.in)
- [graph1000.in](graph1000.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "graph.h"

typedef enum { WHITE, GREY, BLACK } Color; /* colori dei nodi */

Graph G;
int *p;         /* array di predecessori */
int t;          /* tempo corrente (per gli array discover[], finish[]) */
int *discover;  /* discover[v] e' l'istante in cui il nodo v e' stato visitato per la prima volta */
int *finish;    /* finish[v] e' l'istante in cui tutti i discendenti di v sono stati visitati */
Color *color;   /* color[v] e' il colore del nodo v (vedi Cormen et al.) */


/* Visita il grafo g usando l'algoritmo di visita in profondità (DFS)
   partendo da tutti i nodi. */
void dfs( void )
{
    /* [TODO] */
}

/* Stampa i predecessori di ciascun nodo lungo l'albero di visita */
void print_dfs( void )
{
    const int n = graph_n_nodes(&G);
    int v;

    printf("     v   p[v]   disc finish\n");
    printf("------ ------ ------ ------\n");
    for (v=0; v<n; v++) {
        printf("%6d %6d %6d %6d\n", v, p[v], discover[v], finish[v]);
    }
}

int main( int argc, char *argv[] )
{
    FILE *filein = stdin;
    int n;

    if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    graph_read_from_file(filein, &G);
    n = graph_n_nodes(&G);
    p = (int*)malloc( n * sizeof(*p) ); assert(p != NULL);
    discover = (int*)malloc( n * sizeof(*discover) ); assert(discover != NULL);
    finish = (int*)malloc( n * sizeof(*finish) ); assert(finish != NULL);
    color = (Color*)malloc( n * sizeof(*color) ); assert(color != NULL);
    dfs( );
    print_dfs( );
    graph_destroy(&G);
    free(p);
    free(discover);
    free(finish);
    free(color);

    return EXIT_SUCCESS;
}
