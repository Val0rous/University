/****************************************************************************
 *
 * bandiera.c -- Problema della bandiera nazionale
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
% LabASD - Problema della bandiera nazionale
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-18

Il _problema della bandiera nazionale olandese_ è stato proposto per
la prima volta da Edsger W. Dijkstra nel 1976 (E. W. Dijkstra, _A
discipline of programming_, Prentice-Hall, 1976). Lo riproponiamo qui
in chiave italiana.

![Edsger W. Dijkstra By Hamilton Richards - manuscripts of Edsger W. Dijkstra, University Texas at Austin, CC BY-SA 3.0, <https://commons.wikimedia.org/w/index.php?curid=4204157>](Dijkstra.jpg)

Sia `a[]` un array di lunghezza $n \geq 0$, i cui elementi possono
assumere solo uno di tre possibili valori: `VERDE`, `BIANCO`,
`ROSSO`. Non è detto che siano presenti elementi di ciascun
colore. Vogliamo ordinare l'array in modo che tutti gli elementi verdi
precedano quelli bianchi, e gli elementi bianchi precedano quelli
rossi. L'algoritmo deve soddisfare i seguenti requisiti:

- deve richiedere tempo $O(n)$ nel caso peggiore;

- deve usare spazio aggiuntivo $O(1)$ oltre a quello necessario per
  memorizzare l'array da ordinare;

- può solo scambiare tra di loro elementi di `a[]`.

L'algoritmo non può usare contatori per tenere traccia del numero di
elementi di un certo colore presenti (non si può usare l'algoritmo
_counting sort_).

## Suggerimento

Supponiamo che durante l'esecuzione dell'algoritmo l'array `a[]` venga
progressivamente ordinato. In particolare, durante la sua esecuzione,
l'algoritmo mantiene tre variabili `v`, `i`, `r` che soddisfano le
seguenti invarianti (ricordiamo che una invariante è una proprietà che
rimane vera durante l'intera esecuzione dell'algoritmo; si faccia
riferimento alla Figura 2):

![Figura 2: Invariante per l'algoritmo della bandiera](bandiera-invariante.png)

1. Gli elementi `a[0..v-1]` sono verdi (se `v==0`, non ci sono
   elementi verdi);

2. Gli elementi `a[v..i-1]` sono bianchi (se `i==v`, non ci
   sono elementi bianchi);
   
3. Gli elementi `a[r+1..n-1]` sono rossi (se `r==n-1`, non
   ci sono elementi rossi);

4. Gli elementi `a[i..r]` devono essere ancora esaminati, 
   e possono essere di qualsiasi colore.

Ad ogni iterazione, l'algoritmo esamina `a[i]`, effettuando opportuni
scambi per spostare l'elemento nella posizione corretta in base al
proprio colore.

- Quali valori occorre dare alle variabili `v`, `i`, `r` all'inizio 
  dell'algoritmo, quando l'intero array è inesplorato?

- Qual è la condizione che determina la terminazione dell'algoritmo?

Quella sopra non è l'unica invariante possibile per questo esercizio,
ma è quella che consente di ridurre il numero di scambi che occorre
fare per riordinare l'array. Nota: l'ordinamento non deve
necessariamente essere stabile, quindi è possibile cambiare l'ordine
relativo degli elementi dello stesso colore se necessario.

## File

- [bandiera.c](bandiera.c)

***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {VERDE, BIANCO, ROSSO} Colore;


/**
 * Stampa a video il contenuto dell'array a
 */
void stampa( const Colore *a, int n )
{
    int i;
    
    printf("[");
    for( i=0; i<n; i++ ) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

void bandiera( Colore *a, int n )
{
    /* [TODO] */
}

#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

int main( void )
{
    Colore p1[] = {BIANCO, VERDE, ROSSO, ROSSO, BIANCO, ROSSO, ROSSO, VERDE, VERDE, BIANCO, ROSSO, ROSSO, ROSSO, BIANCO};
    const int n1 = ARRAY_LEN(p1);
    Colore p2[] = {VERDE, VERDE, VERDE, VERDE};
    const int n2 = ARRAY_LEN(p2);
    Colore p3[] = {BIANCO, BIANCO, BIANCO, BIANCO};
    const int n3 = ARRAY_LEN(p3);
    Colore p4[] = {ROSSO};
    const int n4 = ARRAY_LEN(p4);
    Colore p5[] = {VERDE, ROSSO, BIANCO, ROSSO, BIANCO, BIANCO, BIANCO};
    const int n5 = ARRAY_LEN(p5);    
    Colore p6[] = {ROSSO, ROSSO, ROSSO, VERDE};
    const int n6 = ARRAY_LEN(p6);        

    bandiera(p1, n1);
    stampa(p1, n1);
    bandiera(p2, n2);
    stampa(p2, n2);
    bandiera(p3, n3);
    stampa(p3, n3);
    bandiera(p4, n4);
    stampa(p4, n4);
    bandiera(p5, n5);
    stampa(p5, n5);
    bandiera(p6, n6);
    stampa(p6, n6);
    return EXIT_SUCCESS;
}
