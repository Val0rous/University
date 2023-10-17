/****************************************************************************
 *
 * bellman-ford.c -- Algoritmo di Bellman-Ford
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
% LabASD - Algoritmo di Bellman-Ford
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-05-03

Implementare l'algoritmo di Bellman-Ford per il calcolo del cammini
minimi da singola sorgente in un grafo orientato pesato senza pesi
negativi. L'algoritmo richiede un nodo di partenza $s$, e opera
eseguendo dei _passi di rilassamento_. Dato un arco orientato $(u, v)$
di peso $w$, e un array `d[]` contenente le stime delle distanze di
ciascun nodo dalla sorgente, un passo di rilassamento consiste
nell'operazione seguente:

```C
if (d[u] + w < d[v]) {
    d[v] = d[u] + v;
    p[v] = u;
}
```

dove `p[x]` indica il predecessore del nodo $x$ lungo il cammino
minimo dalla sorgente a $x$.

L'operazione di rilassamento consente di ridurre la stima $d[v]$ della
distanza del nodo $v$ dalla sorgente nel caso in cui si scopra che
attraversando l'arco $(u, v)$ si raggiunge $v$ con una distanza
inferiore.

Le distanze sono inizialmente stimate tutte $+\infty$, ad esclusione
della distanza $d[s]$ della sorgente da se stessa che vale zero. Per
rappresentare il valore $+\infty$ si può usare il simbolo `HUGE_VAL`
di tipo `float` o `double` definito in `<math.h>`.  Questo simbolo è
parte dello standard C90, per cui dovrebbe essere presente in tutti i
compilatori compatibili (in C99 è definito un più comprensibile
simbolo `INFINITY`). `HUGE_VAL` si comporta a tutti gli effetti come
"infinito": è infatti strettamente maggiore di ogni valore
rappresentabile dal tipo `float` o `double`, e non cambia se viene
sommato ad una quantità finita.

Questo programma memorizza l'albero dei cammini minimi in due modi:
come array di predecessori `p[v]`, e in un array `sp[]` di lunghezza
$n$. Specificamente, `sp[v]` è un puntatore all'arco entrante nel nodo
$v$ lungo il cammino minimo dalla sorgente a $v$; se $v$ non è
raggiungibile dalla sorgente, oppure se $v$ coincide con la sorgente,
si pone `sp[v] = NULL`.

Il programma legge il grafo da un file il cui nome è indicato sulla
riga di comando, e stampa l'elenco degli archi che fanno parte
dell'albero dei cammini minimi da una sorgente, oppure da una sorgente
a una destinazione specificati (in questo secondo caso vengono
comunque calcolati tutti i cammini minimi). Il formato dell'input è
quello supportato dal tipo [grafo](../solutions/graph.html).

Per compilare:

        gcc -std=c90 -Wall -Wpedantic graph.c bellman-ford.c -o bellman-ford

Per stampare le distanze e i cammini minimi dal nodo 0:

        ./bellman-ford graph10.in 0

Per stampare la distanza e il cammino minimo dal nodo 3 al nodo 4:

        ./bellman-ford graph10.in 3 4

## Suggerimento

Nella versione base, l'algoritmo di Bellman-Ford effettua $n-1$
fasi di rilassamento, in cui in ogni fase si esaminano tutti
gli archi del grafo. Il costo è pertanto $\Theta(nm)$.

In certi casi, si può ridurre il tempo di esecuzione con la seguente
ottimizzazione: se al termine di una fase di rilassamento le distanze
dei nodi non cambiano, allora l'algoritmo può terminare
immediatamente. Infatti, questo significa che le distanze sono già
quelle minime e risulterebbe inutile effettuare altre fasi. Questo
comportamento si può realizzare con una semplice modifica alla
versione base dell'algoritmo.

Con questa ottimizzazione è possibile gestire grafi più grandi, come
quelli nella tabella seguente che rappresentano porzioni della rete
stradale di alcuni stati americani e della città di Roma:

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

## File

- [bellman-ford.c](bellman-ford.c)
- [graph.c](../solutions/graph.c)
- [graph.h](../solutions/graph.h)
- [graph-negative-cycle.in](graph-negative-cycle.in) (questo grafo ha cicli negativi, che devono essere segnalati da questo programma).
- [graph10.in](graph10.in) ([risultato atteso usando 0 come sorgente](graph10-bf.out))
- [graph100.in](graph100.in)
- [graph1000.in](graph1000.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "graph.h"


/* Calcola l'albero dei cammini minimi dalla sorgente s usando
   l'algoritmo di Bellman-Ford. Restituisce 1 se e solo se ci sono
   cicli negativi.

   Parametri:

   - g: grafo con n nodi

   - s: nodo sorgente (0 <= s < n)

   - d[v]: distanza di v dalla sorgente; d[] è un array di n elementi
     allocato dal chiamante e viene riempito da questa funzione

   - p[v]: predecessore di v lungo il cammino minimo dalla sorgente a
     v; p[] è un array di n elementi allocato dal chiamante e
     viene riempito da questa funzione

   - sp[v] punta all'arco in ingresso a v lungo il cammino dalla
     sorgente a v; sp[] è un array di n puntatori allocato dal
     chiamante e viene riempito da questa funzione

   Risultato:

   - 1 se ci sono cicli negativi, 0 altrimenti.
*/
int bellman_ford( const Graph *g, int s, double *d, int *p, const Edge **sp )
{
    /* [TODO] */
    return 0;
}


/* Stampa l'elenco degli archi dell'albero dei cammini minimi nello
   stesso formato usato per il grafo di input. Questa funzione non
   viene usata in questo programma. */
void print_sp( const Graph *g, const Edge **sp )
{
    const int n = graph_n_nodes(g);
    int v;
    int nsp = 0; /* numero di archi che fanno parte dell'albero dei cammini minimi */

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
    const Edge **sp; /* sp[v] è il puntatore all'arco nel grafo che
                        collega v con il suo predecessore nell'albero
                        dei cammini minimi */
    double *d;       /* d[v] è la distanza del nodo v dalla
                        sorgente */
    int *p;          /* p[v] è il predecessore di v lungo il cammino
                        minimo dalla sorgente a v */
    FILE *filein = stdin;
    int n, neg, src = 0, dst = -1;

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

    /* Assumiamo 0 come nodo sorgente */
    neg = bellman_ford(&G, src, d, p, sp);
    if (neg) {
        printf("Ci sono cicli negativi\n");
    } else {
        /* print_sp(&G, sp); */
        print_dist(&G, src, dst, p, d);
    }
    graph_destroy(&G);

    free(d);
    free(p);
    free(sp);
    return EXIT_SUCCESS;
}
