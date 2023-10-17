/****************************************************************************
 *
 * quicksort.c -- Quicksort
 *
 * Copyright (C) 2021 Nicolas Farabegoli, Moreno Marzolla
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
% LabASD - Quicksort
% Nicolas Farabegoli <nicolas.farabegoli2@unibo.it>
  Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-11

Implementare l'algoritmo _Quicksort_. Quicksort è un algoritmo di
ordinamento ricorsivo di tipo _divide et impera_ inventato da Charles
Antony Richard Hoare nel 1959 e pubblicato nel 1961.

![Figura 1: C. A. R. Hoare By Photograph by Rama, Wikimedia Commons, Cc-by-sa-2.0-fr, CC BY-SA 2.0 fr, <https://commons.wikimedia.org/w/index.php?curid=15568323>](Hoare.jpg)

L'array da ordinare viene partizionato in modo diverso rispetto a
[Merge Sort](merge-sort.html). In particolare, Quicksort fa uso di una
funzione `partition(v, start, end)` che, data una porzione di array
`v[start..end]`, seleziona uno dei valori detto _pivot_ (chiamiamolo
$p$). Successivamente, il contenuto della porzione di array viene
permutato in modo che gli elementi minori o uguali a $p$ si trovino a
sinistra rispetto al pivot, e gli elementi maggiori a $p$ si trovino a
destra. La funzione `partition()` deve restituire la posizione
(indice) del pivot. Si faccia riferimento alla Figura 2.

![Figura 2: Risultato della funzione `partition(v, start, end)`](partition.png)

Di conseguenza, il pivot si trova nella posizione corretta rispetto
all'array ordinato. Per completare l'ordinamento, Quicksort viene
invocato ricorsivamente sul sottovettore che precede e segue la
posizione del pivot.

La parte più complessa di QuickSort è la funzione `partition()`. Esistono
diverse strategie per realizzarla; quella descritta nal libro si basa
sul mantenimento delle invarianti seguenti (vedi Figura 3):

- `v[k] <= p` per ogni $\textit{start} \leq k \leq i$

- `v[k] > p` per ogni $i+1 \leq k < j$

![Figura 3: Invariante della funzione `partition(v, start, end)`](partition-invariant.png)

In rete si trovano molte [animazioni di
Quicksort](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif).

Le prestazioni di Quicksort dipendono dalla bontà del partizionamento.
Nel caso ideale in cui il pivot si trovi quasi al centro del
sottovettore, il costo asintotico $T(n)$ soddisfa l'equazione di
ricorrenza:

$$
T(n) = \begin{cases}
c_1 & \mbox{se } n \leq 1 \\
2T(n/2) + c_2 n & \mbox{altrimenti}
\end{cases}
$$

che è la stessa di [Merge sort](merge-sort.html) e ha soluzione $T(n)
= \Theta(n \log n)$.

Se invece il partizionamento è totalmente sbilanciato (il pivot si
trova all'inizio o alla fine di ciascun sottovettore), l'equazione
di ricorrenza diventa

$$
T(n) = \begin{cases}
c_1 & \mbox{se } n \leq 1 \\
T(n-1) + c_2 n & \mbox{altrimenti}
\end{cases}
$$

che ha soluzione $T(n) = \Theta(n^2)$. È possibile evitare in modo
deterministico il caso pessimo con una strategia di partizionamento
sofisticata ("mediana di mediane"). 

In questa esercitazione suggerisco di scegliere il pivot in modo
deterministico oppure in modo randomizzato (il pivot è scelto a caso
tra gli elementi del sottovettore).

Il programma fornito contiene alcuni test per verificare la parziale
correttezza della funzione `quicksort()`. Nei test si confronta il
risultato con quello prodotto dalla funzione `qsort()` della libreria
standard C. La segnatura di `qsort()` è:

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

Per compilare il programma da riga di comando:

        gcc -std=c90 -Wall -Wpedantic quicksort.c -o quicksort

(il flag `-std=c90` indica di trattare il sorgente in modo conforme
allo standard ANSI/ISO C90; è equivalente al flag `-ansi`).

## Per approfondire

Questo programma misura in modo grossolano il tempo necessario per ordinare
l'array. Considerando array di dimensioni sufficientemente grandi (es., 
100000 elementi o più), come varia il tempo di esecuzione nei seguenti casi?

- array di input già ordinato;

- array di input "quasi" ordinato (esempio, un array ordinato in cui
  si scambiano due elementi casuali `v[i]` e `v[j]`);

- array di input ordinato in senso decrescente;

- array di input casuale;

- array di input composto da tutti valori uguali

Per eseguire le prove occorre modificare opportunamente la funzione
`main()` per generare degli array di input opportuni. Nel caso possano
risultare utili, vengono fornite due funzioni `randab()` e
`random_shuffle()`, la cui specifica è indicata nei commenti al
codice.

## File

- [quicksort.c](quicksort.c)

 ***/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//Swaps two elements: useful for comparisons and first/last step of QuickSort
void swap(int *v, int i, int j)
{
    const int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* Applica la procedura "partition" al sottovettore v[start..end]
   (estremi inclusi). Ritorna la posizione all'interno di questo array
   in cui si trova il pivot. */
int partition(int *v, int start, int end)
{
    /* [TODO] */
    int x = v[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++)
    {
        if(v[j]<=x)
        {
            i++;
            swap(v, v[i], v[j]);
        }
    }
    swap(v, v[i + 1], v[end]);

    return i + 1;
}

/* Ordina il sottovettore array[start..end] (estremi inclusi) */
void quicksort_rec(int *array, int start, int end)
{
    /* [TODO] */
}

/* ordina il vattore v di lunghezza n usando l'algoritmo
   Quicksort. Questa funzione fa partire la ricorsione chiamando
   quicksort_rec() con i parametri appropriati. */
void quicksort(int *v, int n)
{
    quicksort_rec(v, 0, n - 1);
}

void print_array(const int *v, int n)
{
    int i;

    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]");
}

/* Restituisce un valore casuale compreso tra a e b (estremi inclusi) */
int randab(int a, int b)
{
    return a + rand() % (b - a + 1);
}

/* Permuta il contenuto dell'array v in modo casuale. Questa operazione
   viene eseguita in modo iterativo come segue:

   - al primo passo si scambia v[0] con uno elemento casuale scelto 
     in v[1..n-1];

   - al secondo passo si scambia v[1] con un elemento casuale scelto
     in v[2..n-1];

   - all'i-esimo passo si scambia v[i-1] con un elemento casuale scelto
     in v[i-1..n-1]

   È possibile dimostrare che questo procedimento, applicato fino alla fine,
   produce un "rimescolamento casuale" (random shuffle) di v[].
*/
void random_shuffle(int *v, int n)
{
    int i;

    for (i = 0; i < n - 1; i++)
    {
        const int j = randab(i, n - 1);
        const int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
}

/* Restituisce -1 se *p1 (interpretato come intero) è minore di *p2
   (sempre interpretato come inter), 0 se sono uguali, 1 se il primo è
   maggiore del secondo. */
int compare(const void *p1, const void *p2)
{
    int v1 = *(int *)p1;
    int v2 = *(int *)p2;
    return (v1 - v2);
}

/* Ordina l'array v[] di lunghezza n. Confrontiamo il risultato
   dell'ordinamento con quello prodotto dalla funzione qsort() della
   libreria standard C. Restituisce 1 se il test ha successo, 0
   altrimenti. */
int test(int *v, int n)
{
    int result;
    int *tmp = (int *)malloc(n * sizeof(*tmp));
    clock_t tstart, elapsed;

    assert(tmp); /* questo serve per evitare un warning con VS */
    memcpy(tmp, v, n * sizeof(*v));
    qsort(tmp, n, sizeof(*tmp), compare);
    tstart = clock();
    quicksort(v, n);
    elapsed = clock() - tstart;
    if (0 == memcmp(v, tmp, n * sizeof(*v)))
    {
        printf("Test OK (%f seconds)\n", elapsed / (double)CLOCKS_PER_SEC);
        result = 1;
    }
    else
    {
        printf("Test FALLITO: risultato atteso=");
        print_array(tmp, n);
        printf(", risultato ottenuto=");
        print_array(v, n);
        printf("\n");
        result = 0;
    }
    free(tmp);
    return result;
}

#define ARRAY_LEN(v) (sizeof(v) / sizeof(v[0]))

int main(void)
{
    int v1[] = {0, 8, 1, 7, 2, 6, 3, 5, 4};
    int v2[] = {0, 1, 0, 6, 10, 10, 0, 0, 1, 2, 5, 10, 9, 6, 2, 3, 3, 1, 7};
    int v3[] = {-1, -3, -2};
    int v4[] = {2, 2, 2};

    test(v1, ARRAY_LEN(v1));
    test(v2, ARRAY_LEN(v2));
    test(v3, ARRAY_LEN(v3));
    test(v4, ARRAY_LEN(v4));

    return EXIT_SUCCESS;
}
