/****************************************************************************
 *
 * bfs.c -- Visita in ampiezza di grafi orientati
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
% LabASD - Visita in ampiezza (BFS)
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-13

Realizziamo l'algoritmo di visita in ampiezza (_Breadth-First Search_,
BFS) di un grafo orientato $G=(V,E)$ con $n$ nodi e $m$ archi.  La
visita in ampiezza inizia da un nodo sorgente $s$ e procede "per
livelli": prima si visitano tutti i nodi adiacenti a $s$, poi tutti i
nodi adiacenti a quelli adiacenti, e così via.

In [questa pagina](https://bl.ocks.org/mbostock/11337835) è presente
una interessante visualizzazione dell'algoritmo BFS mentre esplora un
labirinto (che può essere descritto tramite un grafo).

Al termine della visita, l'algoritmo riempie due array `p[]` e `d[]`,
entrambi di $n$ elementi, con le seguenti informazioni:

- `p[v]` è il predecessore del nodo $v$ durante la visita (il predecessore
   del nodo sorgente viene indicato con $-1$);

- `d[v]` è la distanza del nodo $v$ dalla sorgente, dove per distanza
  intendiamo il numero di archi attraversati. Per ogni nodo
  raggiungibile dalla sorgente, l'algoritmo BFS determina il minimo
  numero di archi che è necessario attraversare per raggiungerlo. Se
  un nodo $v$ non è raggiungibile dalla sorgente poniamo `d[v] = -1`

L'algoritmo BFS richiede l'uso di una coda FIFO in cui inserire i nodi
da visitare. In una coda FIFO il primo elemento inseriro è anche il
primo ad essere estratto. Viene fornita una implementazione nei file
[queue.h](queue.h) e [queue.c](../solutions/queue.c); è anche
possibile utilizzare la struttura `List` già vista in una [precedente
esercitazione](list.html).

La struttura `Queue` è basata su un array circolare che viene
automaticamente espanso e contratto in base al numero di elementi
effettivamente presenti. Tale struttura supporta l'inserimento e la
rimozione dalle estremità in tempo $O(1)$ _ammortizzato_; la struttura
`List` fa uso di puntatori, e supporta l'inserimento e la rimozione
dalle estremità in tempo $O(1)$ nel caso pessimo.

Se si vuole usare la struttura `Queue`, le funzioni utili per questo
esercizio sono:

`queue_init(Queue *q)`

: Inizializza la coda

`queue_destroy(Queue *q)`

: Libera tutta la memoria occupata dalla coda

`queue_enqueue(Queue *q, int val)`

: Inserisce `val` in fondo alla coda

`int queue_dequeue(Queue *q)`

: Rimuove e restituisce l'elemento in testa alla coda.

`int queue_is_empty(const Queue *q)`

: Restituisce 1 se la coda è vuota

Questo programma deve accettare uno o due parametri sulla riga di
comando. Il primo parametro (obbligatorio) indica il nodo sorgente da
cui far partire la visita. Il secondo parametro (facoltativo) indica
il nome del file contenente il grafo da visitare; se manca, il grafo
viene letto da standard input.

Per compilare:

        gcc -std=c90 -Wall -Wpedantic queue.c graph.c bfs.c -o bfs

Per eseguire:

        ./bfs 0 graph100.in

oppure

        ./bfs 0 < graph100.in

## Curiosità

La visita in ampiezza può essere applicata all'analisi del grafo delle
mosse di un gioco da tavolo, per determinare il numero minimo di mosse
necessarie a vincere, o se esiste una strategia vincente.  Un
risultato interessante è stato ottenuto nel 2007 quando un gruppo di
ricercatori ha [completato l'analisi del gioco della
dama](https://www.researchgate.net/publication/231216842_Checkers_Is_Solved),
che ha circa $5 \times 10^{20}$ configurazioni valide (che
corrispondono a nodi del grafo). È stato così dimostrato che, se
entrambi i giocatori giocano in modo "perfetto", il risultato è un
pareggio.  _"The Atlantic"_ ha un [articolo non
tecnico](https://www.theatlantic.com/technology/archive/2017/07/marion-tinsley-checkers/534111/)
che discute questo risultato.

Usando la visita in ampiezza dell'albero delle mosse valide, è
possibile rispondere alle questioni rimaste in sospeso sul gioco
[shooting stars](shooting-stars.html): qual è il minimo numero di
mosse necessarie per vincere? esistono configurazioni della griglia di
gioco che non possono essere ottenute da quella iniziale?

## File

- [bfs.c](bfs.c)
- [graph.c](graph.c)
- [graph.h](graph.h)
- [queue.c](../solutions/queue.c)
- [queue.h](../solutions/queue.h)
- [graph10.in](graph10.in) (risultato della visita in ampiezza usando [il nodo 0 come sorgente](graph10-bfs-0.out) oppure [il nodo 5 come sorgente](graph10-bfs-5.out))
- [graph100.in](graph100.in)
- [graph1000.in](graph1000.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "graph.h"
#include "queue.h"

typedef enum { WHITE, GREY, BLACK } Color; /* colori dei nodi */

/* Visita il grafo g usando l'algoritmo di visita in ampiezza (BFS)
   partendo dal nodo sorgente s. Restituisce il numero di nodi
   visitati (incluso s). */
int bfs( const Graph *g,
         int s,  /* Nodo sorgente */
         int *d, /* d[i] e' la distanza del nodo i dalla sorgente,
                    intesa come minimo numero di archi che collegano
                    la sorgente al nodo i. Questo array deve essere
                    preallocato dal chiamante e contenere n elementi
                    (uno per ogni nodo del grafo) */
         int *p  /* array di padri; anche questo array deve essere
                    preallocato dal chiamante e avere lunghezza n */
         )
{
    /* [TODO] */
    return 0;
}

/* Stampa i predecessori e le distanze (numero di archi) di ciascun
   nodo dalla sorgente */
void print_bfs( const Graph *g, const int *d, const int *p )
{
    const int n = graph_n_nodes(g);
    int v;

    assert(p != NULL);
    assert(d != NULL);

    printf("    v  p[v]  d[v]\n");
    printf("----- ----- -----\n");
    for (v=0; v<n; v++) {
        printf("%5d %5d %5d\n", v, p[v], d[v]);
    }
}

int main( int argc, char *argv[] )
{
    Graph G;
    int nvisited; /* n. di nodi raggiungibili dalla sorgente */
    int *p, *d;
    FILE *filein = stdin;
    int s, n;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s n [grafo]\n", argv[0]);
        return EXIT_FAILURE;
    }

    s = atoi(argv[1]);

    if (argc > 2) {
        filein = fopen(argv[2], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[2]);
            return EXIT_FAILURE;
        }
    }

    graph_read_from_file(filein, &G);
    n = graph_n_nodes(&G);
    assert(s >= 0 && s < n);
    p = (int*)malloc( n * sizeof(*p) ); assert(p != NULL);
    d = (int*)malloc( n * sizeof(*p) ); assert(d != NULL);
    nvisited = bfs(&G, s, d, p);
    print_bfs(&G, d, p);
    printf("# %d nodi su %d raggiungibili dalla sorgente %d\n", nvisited, n, s);
    graph_destroy(&G);
    free(p);
    free(d);
    return EXIT_SUCCESS;
}
