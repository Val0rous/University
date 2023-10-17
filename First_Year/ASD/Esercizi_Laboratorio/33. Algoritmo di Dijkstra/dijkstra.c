/****************************************************************************
 *
 * dijkstra.c -- Algoritmo di Dijkstra
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
% LabASD - Algoritmo di Dijkstra
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-05-06

Implementare l'algoritmo di Dijkstra per il calcolo del cammini minimi
da singola sorgente in un grafo orientato pesato con pesi non
negativi. L'algoritmo di Dijkstra richiede un nodo di partenza $s$, e
opera sfruttando una coda di priorità (già implementato nei programmi
[minheap.c](../solutions/minheap.c) e
[minheap.h](../solutions/minheap.h)).

![Edsger W. Dijkstra By Hamilton Richards - manuscripts of Edsger W. Dijkstra, University Texas at Austin, CC BY-SA 3.0, <https://commons.wikimedia.org/w/index.php?curid=4204157>](Dijkstra.jpg "Edsger W. Dijkstra")

Per inizializzare le distanze a $+\infty$ si può usare il valore
`HUGE_VAL` definito in `<math.h>` che rappresenta l'infinito positivo.
Questo simbolo è definito nello standard C90, per cui _dovrebbe_
essere presente in tutti i compilatori compatibili.

Il programma legge il grafo di input da standard input, e stampa
l'elenco degli archi che fanno parte dell'albero dei cammini minimi su
standard output. Il formato dell'input è quello utilizzato
dall'interfaccia [grafo](graph.html).

Per sperimentare la propria implementazione con grafi più grandi, si
possono usare i file di input seguenti che rappresentano porzioni
della rete stradale di alcuni stati americani e della città di Roma:

Dataset                   Nodi ($n$)   Archi ($m$)
------------------------- ------------ ------------
[Nevada](graph-NV.in)     261155       618175
[Maine](graph-ME.in)      194505       425708
[Vermont](graph-VT.in)    97975        212979
[Delaware](graph-DE.in)   49109        119744
[Roma](graph-rome.in)     3353         8859
------------------------- ------------ ------------

I file sono stati ottenuti dai dati forniti nel [9th DIMACS
implementation challenge--Shortest
Paths](http://users.diag.uniroma1.it/challenge9/download.shtml).
Curiosamente, i grafi non sono sempre (fortemente) connessi, quindi
non tutti i nodi sono raggiungibili dagli altri nodi (!!).

Per compilare:

        gcc -std=c90 -Wall -Wpedantic minheap.c graph.c dijkstra.c -o dijkstra

Per stampare le distanze e i cammini minimi dal nodo 0:

        ./dijkstra graph10.in 0

Per stampare la distanza e il cammino minimo dal nodo 3 al nodo 4:

        ./dijkstra graph10.in 3 4

dove al posto di 0 si può indicare l'indice di qualunque altro nodo da
usare come sorgente.

## File

- [dijkstra.c](dijkstra.c)
- [minheap.c](../solutions/minheap.c)
- [minheap.h](../solutions/minheap.h)
- [graph.c](../solutions/graph.c)
- [graph.h](../solutions/graph.h)
- [graph10.in](graph10.in) ([risultato atteso usando 0 come sorgente](graph10-dijkstra.out))
- [graph100.in](graph100.in)
- [graph1000.in](graph1000.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "minheap.h"
#include "graph.h"

/* Calcola l'albero dei cammini minimi dalla sorgente s usando
   l'algoritmo di Dijkstra.

   Parametri:

   - g: grafo di input con n nodi

   - s: nodo sorgente (0 <= s < n)

   - d[v]: distanza di v dalla sorgente; d[] è un array di n elementi
     allocato dal chiamante e viene riempito da questa funzione

   - p[v]: predecessore di v lungo il cammino dalla sorgente a v; p[]
     è un array di n elementi allocato dal chiamante e viene riempito
     da questa funzione

   - sp[v]: puntatore all'arco in ingresso a v lungo il cammino dalla
     sorgente a v; sp[] è un array di n puntatori ad arco allocato dal
     chiamante e viene riempito da questa funzione
*/
void dijkstra( const Graph *g, int s, double *d, int *p, const Edge **sp )
{
    /* [TODO] */
}

/* Stampa l'elenco degli archi dell'albero dei cammini minimi nello
   stesso formato usato per il grafo di input. Questa funzione non
   viene usata in questo programma. */
void print_sp( const Graph *g, const Edge **sp )
{
    const int n = graph_n_nodes(g);
    int v;
    int nsp = 0;

    assert(sp != NULL);

    /* Contiamo gli archi che fanno parte dell'albero dei cammini minimi */
    for (v=0; v<n; v++) {
        if (sp[v] != NULL) nsp++;
    }

    printf("%d %d 1\n", n, nsp);
    for (v=0; v<n; v++) {
        const Edge *e = sp[v];
        if (e != NULL) {
            printf("%d %d %f\n", e->src, e->dst, e->weight);
        }
    }
}

/* Questa funzione deve stampare la sequenza di nodi del cammino
   minimo da src a dst, se esiste, oppure "Non raggiungibile" se la
   destinazione non è raggiungibile.  Il formato deve essere:

   src->v0->v1->...->dst

   dove src, vi, dst sono interi che rappresentano i nodi del
   cammino minimo. Non bisogna andare a capo alla fine della
   stampa.

   L'array p[] è l'array dei predecessori, calcolato dall'algoritmo
   di Dijkstra.

   Suggerimento: suggerisco una implementazione ricorsiva, che è molto
   semplice. */
void print_path(const int *p, int src, int dst)
{
    /* [TODO] */
}

/* Stampa la distanza e il cammino minimo da src a dst; se dst < 0,
   stampa le distanze e i cammini minimi da src a tutti i nodi del
   grafo. */
void print_dist( const Graph *g, int src, int dst, const int *p, const double *d )
{
    const int n = graph_n_nodes(g);
    int v, from_idx = 0, to_idx = n-1;

    assert(p != NULL);
    assert(d != NULL);

    if (dst >= 0) {
        from_idx = to_idx = dst;
    }

    printf("   s    d         dist path\n");
    printf("---- ---- ------------ -------------------------\n");
    for (v=from_idx; v<=to_idx; v++) {
        printf("%4d %4d %12.4f ", src, v, d[v]);
        print_path(p, src, v);
        printf("\n");
    }
}

int main( int argc, char *argv[] )
{
    Graph G;
    const Edge **sp; /* sp[v] è il puntatore all'arco che collega v
                        con il suo predecessore nell'albero dei
                        cammini minimi */
    double *d;       /* d[v] è la distanza minima dalla sorgente al
                        nodo v */
    int *p;          /* p[v] è il predecessore di v lungo il cammino
                        minimo dalla sorgente a v */
    FILE *filein = stdin;
    int n, src = 0, dst = -1;

        if (argc > 4) {
        fprintf(stderr, "Usage: %s [filein [src [dst]]]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc > 1 && 0 != strcmp(argv[1], "-")) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    if (argc > 2)
        src = atoi(argv[2]);

    if (argc > 3)
        dst = atoi(argv[3]);

    graph_read_from_file(filein, &G);

    n = graph_n_nodes(&G);
    assert(src >= 0 && src < n);
    assert(dst<0 || (dst >=0 && dst < n));

    d = (double*)malloc(n * sizeof(*d)); assert(d != NULL);
    p = (int*)malloc(n * sizeof(*p)); assert(p != NULL);
    sp = (const Edge**)malloc(n * sizeof(*sp)); assert(sp != NULL);

    dijkstra(&G, src, d, p, sp);
    /* print_sp(&G, sp); */
    print_dist(&G, src, dst, p, d);
    graph_destroy(&G);

    free(d);
    free(p);
    free(sp);
    return EXIT_SUCCESS;
}
