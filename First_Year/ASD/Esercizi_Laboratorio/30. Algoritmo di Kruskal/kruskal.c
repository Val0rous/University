/****************************************************************************
 *
 * kruskal.c -- Algoritmo di Kruskal per MST
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
% LabASD - Algoritmo di Kruskal
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-29

In questo esercizio si chiede di implementare l'algoritmo di Kruskal
per il calcolo di un _Minimum Spanning Tree_ (MST) di un grafo non
orientato pesato $G=(V, E, w)$. L'algoritmo opera secondo i passi
seguenti:

- Ordina gli archi per peso crescente;

- Sia $T$ la foresta di alberi costituita da $n$ nodi isolati
  (un nodo per ogni nodo del grafo).

- Per ogni arco $\{u, v\} \in E$, in ordine crescente di peso:

    * Se $u$ e $v$ appartengono ad alberi diversi della foresta, $T_u$
      e $T_v$, aggiungi l'arco $\{u, v\}$ al MST e fondi i due alberi
      $T_u$ e $T_v$.

    * Altrimenti, salta l'arco e passa al successivo.

Per implementare efficientemente l'algoritmo di Kruskal serve un modo
rapido per verificare se due nodi appartengono o no allo stesso albero
della foresta. A tale scopo possiamo usare una struttura _merge-find_
oggetto di [un'altra esercitazione](mfset.html).

Per ordinare gli archi si può implementare un algoritmo di
ordinamento, oppure usare la funzione `qsort()` dichiarata nell'header
file `<stdlib.h>`. L'interfaccia della funzione è la seguente:

```C
#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size,
           int (*compare)(const void *, const void *));
```

dove:

- `base` è un puntatore all'inizio dell'array da ordinare;

- `nmemb` è il numero di elementi dell'array da ordinare (attenzione, **non** il numero di byte!)

- `size` è la dimensione in byte di ciascuno degli elementi dell'array

- `compare` è un puntatore ad una funzione che accetta due parametri
  di tipo `const void *` e restituisce un `int`. Il risultato deve
  essere negativo se il primo parametro è minore del secondo, positivo
  se il primo parametro è maggiore del secondo, e zero se i parametri
  hanno lo stesso valore.

Il programma deve leggere il grafo da standard input, e deve stampare
l'elenco degli archi che fanno parte del MST su standard output.  Il
formato dell'input è [quello della struttura Graph](graph.html).

Il programma stampa l'elenco degli archi che fanno parte del MST,
nello stesso formato dell'input. Sarebbe quindi possibile usare
l'output di una esecuzione di questo programma come input al programma
stesso.

Come si vede, questo programma non fa uso della struttura dati _Graph_
che abbiamo visto in un [precedente laboratorio](graph.html). Infatti,
per come funziona l'algoritmo di Kruskal, è sufficiente che il grafo
sia rappresentato mediante un elenco di archi. Nel nostro caso usiamo
un array `E[]` di strutture di tipo `Edge` per semplificarne
l'ordinamento. Il MST viene memorizzato in un array di puntatori
`mst[]` (Figura 1), che deve essere inizializzato ad una lunghezza
opportuna; si suggerisce di usare come lunghezza di default il massimo
numero di archi che possano far parte di un MST (si vedano le
domande). La variabile globale `nmst` indica il numero effettivo di
archi che fanno parte del MST.

![Figura 1: Grafo orientato e rappresentazione di un suo MST](kruskal.png)

Per compilare da riga di comando:

        gcc -std=c90 -Wall -Wpedantic kruskal.c mfset.c -o kruskal

Per eseguire:

        ./kruskal < graph10.in

oppure

        ./kruskal graph10.in

## Domande

- Dato un grafo non orientato connesso con $n$ nodi, quanti sono gli
  archi che fanno parte di un MST?

- Cosa succede applicando l'algoritmo di Kruskal ad un grafo non
  connesso?

- Che risultato ci aspettiamo se usiamo l'output di una esecuzione di
  questo programma come input per una successiva esecuzione?  In altre
  parole, cosa ci aspettiamo che succeda se calcoliamo il MST di un
  MST?

## File

- [kruskal.c](kruskal.c)
- [mst10.in](mst10.in) ([output atteso](mst10-kruskal.out))
- [mst100.in](mst100.in) ([output atteso](mst100-kruskal.out))
- [mst1000.in](mst1000.in)
- [mst1500.in](mst1500.in)
- [mst2000.in](mst2000.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mfset.h"

/* Rappresentiamo il grafo come array di archi. Per questo programma
   non usiamo la struttura Grafo che abbiamo definito in una lezione
   precedente. */
typedef struct {
    int src, dst;
    double weight;
} Edge;

/* Anche se non è una buona pratica di programmazione, utilizziamo
   variabili globali per memorizzare l'input del programma e il
   risultato calcolato. Questo semplifica un po' la stesura del
   codice, e puo' essere considerato accettabile vista la dimensione
   ridotta di questo programma. */

int n = 0;        /* numero di nodi             */
int m = 0;        /* numero di archi            */
Edge *E = NULL;   /* Array di archi del grafo   */
int nmst = 0;     /* numero archi del MST       */
const Edge **mst = NULL; /* Array contenente puntatori agli archi che fanno parte del MST; questo array deve essere allocato nella funzioen Kruskal(). I primi `nmst` elementi di questo array contengono puntatori agli archi del MST. */
FILE *filein;     /* file di input              */


/* Leggi li grafo di input e alloca l'array E di archi. Il formato
   dell'input è quello usato dalla struttura dati Graph; per i grafi
   non orientati, gli archi sono salvati su file una sola volta (anche
   se in fase di lettura la struttura Graph li memorizza _due_ volte
   nelle liste di adiacenza). Siccome qui non usiamo liste di
   adiacenza, possiamo leggere gli archi e salvarli direttamente
   nell'array E[]. */
void readGraph( void )
{
    int i, t;

    fscanf(filein, "%d %d %d", &n, &m, &t);
    if (t != 0) {
        fprintf(stderr, "ERRORE: questo programma richiede grafi non orientati\n");
        exit(EXIT_FAILURE);
    }
    E = (Edge*)malloc(m * sizeof(*E)); assert(E != NULL);
    for (i=0; i<m; i++) {
        fscanf(filein, "%d %d %lf", &(E[i].src), &(E[i].dst), &(E[i].weight));
    }
}

/* Calcola il MST usando l'algoritmo di Kruskal e ritorna il peso
   totale dell'albero; alloca l'array `mst[]` e ne definisce
   opportunamente i valori (l'array `mst[]` contiene puntatori ad
   archi). Al termine, la variabile globale `nmst` deve contenere il
   numero di archi che fanno parte del MST. */
double Kruskal( void )
{
    /* [TODO] */
    return 0.0;
}

/* Stampa a video l'elenco degli archi del MST nello stesso formato
   usato per il grafo di input. */
void print_mst( void )
{
    int i;

    printf("%d %d 0\n", n, nmst);
    for (i=0; i<nmst; i++) {
        printf("%d %d %f\n", mst[i]->src, mst[i]->dst, mst[i]->weight);
    }
}

int main( int argc, char *argv[] )
{
    double wtot; /* peso totale del MST */
    filein = stdin;

    if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    readGraph();
    wtot = Kruskal();
    print_mst();
    printf("# MST weight = %f\n", wtot);
    free(E);
    free(mst);
    return EXIT_SUCCESS;
}
