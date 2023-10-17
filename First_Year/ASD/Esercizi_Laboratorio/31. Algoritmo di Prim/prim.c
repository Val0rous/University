/****************************************************************************
 *
 * prim.c -- Implementazione algoritmo di Prim per MST
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
% LabASD - Algoritmo di Prim
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-05-07

Implementare l'algoritmo di Prim per il calcolo del _Minimum Spanning
Tree_ (MST) di un grafo non orientato pesato. L'algoritmo di Prim
richiede un nodo di partenza $s$, e opera sfruttando una coda di
priorità (che abbiamo già implementato nei file
[minheap.c](../solutions/minheap.c) e
[minheap.h](../solutions/minheap.h)).

Per inizializzare le distanze a $+\infty$ si può usare il valore
`HUGE_VAL` definito in `<math.h>` che rappresenta l'infinito positivo.
Questo simbolo è definito nello standard C90, per cui _dovrebbe_
essere presente in tutti i compilatori compatibili.

Il programma legge il grafo da standard input, e stampa l'elenco degli
archi che fanno parte del MST su standard output.  Il formato
dell'input è lo stesso utilizzato dal tipo di dato [grafo](graph.html):

```
n m 0
s[0]    d[0]    w[0]
s[1]    d[1]    w[1]
...
s[m-1]  d[m-1]  w[m-1]
```

dove:

- `n` è il numero di nodi del grafo; i nodi sono rappresentati dagli
  interi $0, \ldots, (n-1)$;

- `m` è il numero di archi del grafo

- `0` indica che il grafo è non orientato

- `s, d, w` sono rispettivamente il nodo sorgente, il nodo destinazione,
  e il peso di ciascun arco. I pesi sono valori reali.

Il programma stampa l'elenco degli archi che fanno parte del MST,
nello stesso formato dell'input. È quindi possibile usare l'output di
questo programma come input al programma stesso.

Per compilare:

        gcc -std=c90 -Wall -Wpedantic graph.c minheap.c prim.c -o prim

Per eseguire:

        ./prim < graph10.in

oppure

        ./prim graph10.in

## Domande

- Dato un grafo non orientato pesato con $n$ nodi e $m$ archi, qual è
  il numero massimo di archi che può far parte di un MST?

- Cosa succede se applichiamo l'algoritmo di Prim ad un grafo
  non connesso?

## File

- [prim.c](prim.c)
- [minheap.c](../solutions/minheap.c)
- [minheap.h](../solutions/minheap.h)
- [graph.c](../solutions/graph.c)
- [graph.h](../solutions/graph.h)
- [mst10.in](mst10.in) ([output atteso](mst10-prim.out))
- [mst100.in](mst100.in) ([output atteso](mst100-prim.out))
- [mst1000.in](mst1000.in)
- [mst1500.in](mst1500.in)
- [mst2000.in](mst2000.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "minheap.h"
#include "graph.h"

/* Calcola il MST usando l'algoritmo di Prim.

   Parametri:

   - g: grafo di cui calcolare il MST

   - s: nodo sorgente (arbitrario; serve per l'algoritmo di Prim)

   - mst[v] è un puntatore all'arco in ingresso a v lungo il cammino
     dalla sorgente a v; si noti che il grafo è non orientato, quindi
     la "direzione" deriva solo dalla scelta del nodo sorgente. mst[]
     è un array di n puntatori ad arco che deve essere allocato dal
     chiamante

   Risultato:

   - peso complessivo dell'albero.

*/
double prim( const Graph *g, int s, const Edge **mst )
{
    /* [TODO] */
    return 0.0;
}

/* Stampa a video l'elenco degli archi del MST nello stesso formato
   usato per il grafo di input. */
void print_mst( const Graph *g, const Edge **mst )
{
    const int n = graph_n_nodes(g);
    int nmst = 0; /* numero di archi che fanno parte del MST */
    int v;

    assert(mst != NULL);

    /* Contiamo gli archi che fanno parte del MST */
    for (v=0; v<n; v++) {
        if (mst[v] != NULL) nmst++;
    }

    printf("%d %d 0\n", n, nmst);
    for (v=0; v<n; v++) {
        const Edge *e = mst[v];
        if (e != NULL) {
            printf("%d %d %f\n", e->src, e->dst, e->weight);
        }
    }
}

int main( int argc, char *argv[] )
{
    Graph G;
    const Edge **mst = NULL; /* mst[v] è il puntatore all'arco che collega v con il suo predecessore nel MST */
    double wtot = 0.0;       /* peso totale del MST */
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
    if (graph_type(&G) != GRAPH_UNDIRECTED) {
        fprintf(stderr, "Questo programma richiede grafi non orientati\n");
        return EXIT_FAILURE;
    }

    n = graph_n_nodes(&G);

    mst = (const Edge**)malloc(n * sizeof(*mst)); assert(mst != NULL);
    wtot = prim(&G, 0, mst);
    print_mst(&G, mst);
    printf("# MST weight = %f\n", wtot);
    graph_destroy(&G);
    free(mst);
    return EXIT_SUCCESS;
}
