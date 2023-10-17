/****************************************************************************
 *
 * vecsum.c -- Sottovettore di somma massima
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
% LabASD - Sottovettore di somma massima
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-05

Realizzare un programma per risolvere il seguente problema: è dato un
array di interi `v[]` di lunghezza $n \geq 1$. L'array può contenere
anche valori negativi o nulli. Tra tutti i sottovettori `v[i..j]` con
$0 \leq i \leq j < n$ vogliamo determinare quello la cui somma dei
valori sia massima possibile. Con la notazione `v[i..j]` indichiamo la
porzione di `v` compresa tra gli indici $i$ e $j$, estremi inclusi.

Esistono diverse soluzioni per questo problema. In questo esercizio è
richiesto di realizzare la soluzione più semplice, che consiste nel
considerare sistematicamente tutte le combinazioni valide di $i,j$ e
per ciascuna calcolare il valore della somma del sottovettore
`v[i..j]`. Si ottiene in questo modo un algoritmo di costo asintotico
$O(n^3)$.

Il `main()` legge la lunghezza $n$ come parametro sulla riga di
comando, inizializza un array di lunghezza $n$, ne calcola il
sottovettore di somma massima e riporta il tempo di esecuzione in
secondi.

Si lanci il programma con vari valori di $n$ (es., da $n=1000$ e
$n=5000$ con passi di $500$, oppure altri valori che non richiedano
troppo tempo sulla propria macchina) segnando i tempi di esecuzione,
Si compili una tabella come quella che segue (i tempi sono puramente
indicativi, e sono relativi alla mia macchina):

: Tabella 1: Tempi di esecuzione in secondi

$n$      Tempo
-------  ---------
1000     0.37
1500     1.26
2000     2.98
2500     5.77
3000     10.04
...      ...
-------  ---------

Per risultati più precisi è necessario ripetere ciascuna misura più
volte (es., 5 volte) e calcolare la media dei tempi. Rappresentare
graficamente i tempi di esecuzione in funzione di $n$ per verificare
che il tempo di esecuzione cresca come $n^3$. Per realizzare i grafici
si può usare un foglio di calcolo (Excel, Libreoffice Calc o
equivalenti).

## Suggerimenti

Assicurarsi che il programma funzioni correttamente anche nel caso in
cui tutti i valori di `v[]` siano negativi.

## Per approfondire

L'algoritmo $O(n^3)$ è estremamente inefficiente. Si può ridurre il
tempo a $O(n^2)$ ristrutturando leggermente il programma (vedremo più
avanti nel corso che esiste anche una soluzione $O(n)$). Misurare
sperimentalmente le prestazioni del nuovo algoritmo scegliendo alcuni
valori di $n$ che consentano di osservare tempi di esecuzione non
troppo elevati.

Usando i dati misurati, estrapolare i valori necessari a completare la
tabella seguente:

: Tabella 2: Tempo di esecuzione in funzione della dimensione

+-----------------------+--------------------+--------------------+
| Tempo necessario per  |                    |                    |
| risolvere un problema | Algoritmo $O(n^3)$ | Algoritmo $O(n^2)$ |
| di dimensione         |                    |                    |
+=======================+====================+====================+
| $n=1000$              |                    |                    |
+-----------------------+--------------------+--------------------+
| $n=10000$             |                    |                    |
+-----------------------+--------------------+--------------------+
| $n=100000$            |                    |                    |
+-----------------------+--------------------+--------------------+

Non è richiesto di eseguire sperimentalmente tutte le misure (con
$n=100000$ l'algoritmo $O(n^3)$ richiederebbe comunque troppo
tempo). Si possono invece estrapolare i risultati ragionando come
segue. Sia $T(n)$ il tempo misurato (in secondi) richiesto dal
programma $O(n^3)$ per risolvere un problema di dimensione
$n$. Sappiamo che $T(n) = O(n^3)$, per cui scrivere (in maniera un po'
impropria):

$$
T(n) \approx \alpha n^3
$$

dove $\alpha$ è una costante moltiplicativa. Misuriamo il tempo per un
certo valore "piccolo" di $n$, ad esempio $n=5000$. Possiamo quindi
stimare $\alpha$ come

$$
\alpha \approx \frac{T(5000)}{5000^3}
$$

(La misura dovrebbe essere ripetuta un certo numero di volte per
ottenere una stima accurata).  Una volta stimato $\alpha$ siamo in
grado di stimare $T(n)$ per ogni $n$ come:

$$
T(n) \approx T(5000) \times \left(\frac{n}{5000}\right)^3
$$

Supponiamo ora di avere un certo tempo a disposizione, e chiediamoci
quale è la dimensione massima del problema risolvibile da ciascun
algoritmo nel tempo assegnato.

: Tabella 3: Dimensione del problema in funzione del tempo a disposizione

+-----------------------+--------------------+--------------------+
| Dimensione problema   |                    |                    |
| risolvibile in tempo  | Algoritmo $O(n^3)$ | Algoritmo $O(n^2)$ |
|                       |                    |                    |
+=======================+====================+====================+
| 1 secondo             | $n=\ldots$         | $n=\ldots$         |
+-----------------------+--------------------+--------------------+
| 1 ora                 | $n=\ldots$         | $n=\ldots$         |
+-----------------------+--------------------+--------------------+
| 1 giorno              | $n=\ldots$         | $n=\ldots$         |
+-----------------------+--------------------+--------------------+

Anche qui, possiamo usare la formula empirica appena derivata.
Supponiamo di aver calcolato $T(5000)$, cioè il tempo necessario
all'algoritmo $O(n^3)$ per risolvere un problema di dimensione
$n=5000$. Detto $T(n)$ il tempo che abbiamo a disposizione, possiamo
derivare $n$ come:

$$
n \approx 5000 \times \left( \frac{T(n)}{T(5000)} \right)^{1/3}
$$

Nel caso dell'algoritmo $O(n^2)$ si può ragionare in modo analogo,
modificando però le formule in modo opportuno.

## File

- [vecsum.c](vecsum.c)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/* Risolve il problema del sottovettore di somma massima. Restituisce
   il massimo valore della somma */
int sottovet_somma_max(const int v[], int n)
{
    printf("Algoritmo O(n^3)\n");
    return -1;
}


/* Riempie l'array deterministicamente */
void fill(int v[], int n)
{
    int i, xi = -100;
    for (i=0; i<n; i++) {
        v[i] = xi;
        xi += 17;
        if (xi > 100) xi -= 200;
    }
}

int main( int argc, char *argv[] )
{
    int n, result;
    clock_t tstart, tend;
    int *v;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s n\n", argv[0]);
        return EXIT_FAILURE;
    }
    n = atoi(argv[1]);
    assert( n>=1 );
    v = (int*)malloc(n * sizeof(v[0]));
    assert(v != NULL);
    fill(v, n);
    tstart = clock();
    result = sottovet_somma_max(v, n);
    tend = clock();
    printf("result=%d\nElapsed time %f\n", result, ((double)(tend - tstart))/CLOCKS_PER_SEC);
    free(v);
    return EXIT_SUCCESS;
}
