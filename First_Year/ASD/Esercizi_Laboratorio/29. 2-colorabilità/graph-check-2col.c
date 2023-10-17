/****************************************************************************
 *
 * graph-check-2col.c -- Controlla se un grafo è 2-colorabile
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
% LabASD - Controlla se un grafo è 2-colorabile
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-30

Un grafo non orientato $G = (V, E)$ è 2-colorabile se è possibile
assegnare a ciascun nodo un colore scelto tra due alternative, in modo
che nodi adiacenti abbiano colori diversi. Formalmente, un grafo è
2-colorabile se esiste una funzione $c: V \rightarrow \{1, 2\}$ che
assegna a ogni nodo $v \in V$ un colore scelto tra $\{1, 2\}$ tale
che:

$$
c(u) \neq c(v)\ \mbox{per ogni arco}\ \{u,v\} \in E
$$

Ad esempio, il grafo (a) in Figura 1 è 2-colorabile, mentre il grafo
(b) non lo è.

![Figura 1: Esempio di grafo 2-colorabile e non 2-colorabile](graph-check-2col.png)

Scrivere un programma che, dato un grafo non orientato, determina se è
2-colorabile oppure no. **Attenzione:** il grafo potrebbe essere _non_
connesso.

## Suggerimento

È possibile risolvere questo problema applicando un algoritmo di
visita (BFS oppure DFS) al grafo $G$. La visita inizia assegnando un
colore arbitrario ad un nodo qualunque; successivamente, i nodi
adiacenti ricevono il colore opposto a quello appena usato. Se si
tenta di applicare un colore diverso ad un nodo già colorato, allora
il grafo non è 2-colorabile. Si presti attenzione al fatto che il
grafo $G$ non è necessariamente connesso, quindi occorre ripetere il
procedimento per ogni componente connessa.

## File

- [graph-check-2col.c](graph-check-2col.c)
- [graph.c](../solutions/graph.c)
- [graph.h](../solutions/graph.h)
- [Esempio di grafo 2-colorabile](graph-2col-yes.in) (è il grafo in Figura 1(a))
- [Esempio di grafo NON 2-colorabile](graph-2col-no.in) (è il grafo in Figura 1(b))
- [graph-2col-1.in](graph-2col-1.in)
- [graph-2col-2.in](graph-2col-2.in)
- [graph-2col-3.in](graph-2col-3.in)
- [graph-2col-4.in](graph-2col-4.in)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"


/* Ritorna 1 se e solo se g è 2-colorabile, 0 altrimenti */
int graph_2col(const Graph* g)
{
    /* TODO */
    return -1;
}

int main( int argc, char *argv[] )
{
    Graph G;
    FILE *filein = stdin;

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
    if (graph_2col(&G)) {
        printf("Il grafo e' 2-colorabile\n");
    } else {
        printf("Il grafo NON E' 2-colorabile\n");
    }
    graph_destroy(&G);

    return EXIT_SUCCESS;
}
