/****************************************************************************
 *
 * insertion-sort.c -- Implementazione di insertion sort.
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
% LabASD - Insertion Sort
% Nicolas Farabegoli <nicolas.farabegoli2@unibo.it>
  Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-11

Implementare l'algoritmo _Insertion sort_ in modo tale che i test
forniti vengano superati. L'algoritmo deve ordinare l'array di input
in senso crescente.

Insertion sort opera iterativamente: ad ogni passo l'array `v[0..n-1]`
è composto da una parte iniziale ordinata `v[0..i-1]`, e dal resto
non ordinato. Durante la sua esecuzione, l'algoritmo mantiene la
seguente invariante:

> `v[0..i-1]` è ordinato

Per espandere di un elemento la parte ordinata, cioè per rendere
ordinato `v[0..i]`, occorre inserire `v[i]` nella posizione corretta
di `v[0..i-1]` mediante scambi "a ritroso". Si faccia riferimento alla
Figura 1 per un esempio.

![Figura 1: Esempio Insertion Sort](insertion-sort.png)

Il programma fornito contiene alcuni test per verificare la parziale
correttezza della funzione `insertion_sort()`. Nei test si confronta
il risultato con quello prodotto dalla funzione `qsort()` della
libreria standard C. La segnatura di `qsort()` è:

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

## Per approfondire

Questo programma misura in modo grossolano il tempo necessario a ordinare
l'array. Considerando array di dimensioni sufficientemente grandi (es.,
100000 elementi o più), come varia il tempo di esecuzione nei seguenti casi?

- array di input già ordinato;

- array di input "quasi" ordinato (esempio, array ottenuto da un array
  ordinato in cui si scambiano tra loro due elementi in posizioni $i$,
  $j$);

- array di input ordinato in senso decrescente;

- array di input casuale;

- array di input composto da tutti valori uguali

Per farsi un'idea, si può procedere come segue:

- Si fissa una dimensione di $n$ abbastanza grande per ottenere tempi
  significativi (esempio, $n=100000$, ma si possono scegliere valori
  minori o maggiori in base alle prestazioni della propria macchina);

- Si genera un array di dimensione $n$ del tipo desiderato (es., un
  array ordinato in senso decrescente).

- Si misura il tempo $T_1$ richiesto dalla funzione `insertion_sort()`
  per ordinare l'input di dimensione $n$.

- Si genera un _nuovo_ array di dimensione doppia ($2n$) e si misura
  il tempo $T_2$ richiesto per ordinare questo nuovo input.

- Si calcola il rapporto $T_2 / T_1$. Cosa possiamo dedurre da questo
  rapporto?

Per eseguire le prove occorre modificare la funzione `main()` per
generare input opportuni. Nel caso possano risultare utili, vengono
fornite due funzioni `randab()` e `random_shuffle()`, la cui specifica
è indicata nei commenti al codice.

## File

- [insertion-sort.c](insertion-sort.c)

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void insertion_sort(int *v, int n)
{
    /* [TODO] */
}

void print_array(const int *v, int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]");
}

/* Restituisce un valore casuale compreso tra a e b (estremi inclusi) */
int randab(int a, int b)
{
    return a + rand() % (b-a+1);
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
    for (i=0; i<n-1; i++) {
        const int j = randab(i, n-1);
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
    int v1 = *(int*)p1;
    int v2 = *(int*)p2;
    return (v1 - v2);
}

/* Ordina l'array v[] di lunghezza n. Confrontiamo il risultato
   dell'ordinamento con quello prodotto dalla funzione qsort() della
   libreria standard C. Restituisce 1 se il test ha successo, 0
   altrimenti. */
int test(int *v, int n)
{
    int result;
    int *tmp = (int*)malloc(n * sizeof(*tmp));
    clock_t tstart, elapsed;

    assert(tmp != NULL); /* questo serve per evitare un warning con VS */
    memcpy(tmp, v, n*sizeof(*v));
    qsort(tmp, n, sizeof(*tmp), compare);
    tstart = clock();
    insertion_sort(v, n);
    elapsed = clock() - tstart;
    if (0 == memcmp(v, tmp, n*sizeof(*v))) {
        printf("Test OK (%f seconds)\n", ((double)elapsed) / CLOCKS_PER_SEC);
        result = 1;
    } else {
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

#define ARRAY_LEN(v) (sizeof(v)/sizeof(v[0]))

int main( int argc, char *argv[] )
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
