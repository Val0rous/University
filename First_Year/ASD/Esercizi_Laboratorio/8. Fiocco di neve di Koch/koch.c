/****************************************************************************
 *
 * koch.c -- Fiocco di neve di Koch
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
% LabASD - Fiocco di neve di Koch
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-11

(Esercizio della prof. [Violetta Lonati](http://lonati.di.unimi.it/), Università di Milano)

## Libreria `libpsgraph.c`

Questo esercizio fa uso della libreria `libpsgraph` che consente di
produrre dei semplici grafici in
[PostScript](https://en.wikipedia.org/wiki/PostScript). Per usare
questa libreria occorre procedere come segue:

* create una directory (si può usare la directory corrente);

* salvate in essa i file [libpsgraph.c](libpsgraph.c) e 
  [libpsgraph.h](libpsgraph.h);

* scrivete la vostra applicazione (che nel nostro caso 
  è il file [koch.c](koch.c)), che include all'inizio la direttiva

        #include "libpsgraph.h"

* compilate il programma con il comando

        gcc -std=c90 -Wall -Wpedantic libpsgraph.c koch.c -lm -o koch
  (attenzione alla necessità di linkare con la libreria matematica,
  da cui il flag `-lm`).

## Funzioni fornite dalla libreria

La libreria permette di disegnare usando le funzioni della ["turtle
graphics"](https://en.wikipedia.org/wiki/Turtle_graphics); il disegno
prodotto viene salvato in formato PostScript su un file, il cui nome
va specificato prima di iniziare a disegnare. Il file prodotto può
essere visualizzato con un apposito programma, ad
es. [ghostview](http://pages.cs.wisc.edu/~ghost/). Per Windows si può
scaricare la [versione a 32
bit](https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs9533/gs9533w32.exe)
oppure [quella a 64
bit](https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs9533/gs9533w64.exe).

La libreria va usata in questo modo:

* per prima cosa, si invoca la funzione `start(nomefile)` passando
  come parametro il nome del file in cui si vuole che il grafico venga
  salvato, ad esempio `start("prova.ps");`

* a questo punto è possibile disegnare usando le
  funzioni seguenti, che accettano un parametro di tipo `double`:

  * `draw(x)`: disegna un segmento lungo $x$ millimetri;

  * `move(x)`: si sposta (senza disegnare) di un segmento lungo $x$ millimetri;

  * `turn(x)`: ruota di $x$ gradi in senso orario;

* alla fine, occorre invocare la funzione `end()`.

All'inizio, la "tartaruga" è orientata verso destra in orizzontale;
quindi, se la prima istruzione è `draw(10)` ci si trova con un
segmento orizzontale di lunghezza 10 orientato da sinistra verso
destra.

Il programma seguente disegna un quadrato:

```C
#include "libpsgraph.h"

int main( void )
{
        start("square.ps");
        draw(100); turn(90);
        draw(100); turn(90);
        draw(100); turn(90);
        draw(100);
        end();
        return 0;
}

```

## Curva di Koch

Realizzare una funzione che, data una lunghezza in millimetri $x$ e un
intero $n \geq 0$ produce la curva di Koch di ordine $n$ e di
"lunghezza" $x$; per "lunghezza" qui si intende la lunghezza della sola
base. 

La curva di Koch è definita come segue:

* se $n = 0$, la curva è un segmento di lunghezza $x$;

* se $n > 0$, la curva è ottenuta concatenando quattro curve di Koch
  di ordine $n-1$ e di lunghezza $x/3$, come in figura 1.

![Figura 1: Curve di Koch dall'ordine $n=0$ (in basso) fino a $n=4$ (in alto)](koch-curve.png)

## Fiocco di neve di Koch

Realizzare ora una funzione che, data una lunghezza in millimetri $x$
e un intero $n \geq 0$, produce il fiocco di neve di Koch di ordine
$n$ e di lunghezza $x$: esso si ottiene come un triangolo equilatero
di lunghezza $x$ i cui lati siano stati sostituiti con curve di Koch
di ordine $n$ e lunghezza $x$ (vedi figura 2).

![Figura 2: Fiocco di neve di Koch di ordine $n=4$](koch-snowflake.png)

## Domande

- Sia $K(n)$ il numero di invocazioni della funzione ricorsiva che
  disegna la curva di Koch di ordine $n$. Si ha $K(0)=1$, dato che la
  funzione viene invocata una sola volta; $K(1)=5$ dato che la
  funzione viene invocata una volta con $n=1$ e quattro volte con
  $n=0$. Scrivere una espressione per $K(n)$, possibilmente in forma
  esplicita, cioè non ricorsiva.

- Dati $x$ e $n$, qual è la vera lunghezza della curva di Koch di
  ordine $n$ (cioè la somma delle lunghezze reali di tutti gli
  infiniti segmenti che la compongono)?

## File

- [koch.c](koch.c)
- [libpsgraph.c](libpsgraph.c)
- [libpsgraph.h](libpsgraph.h)

 ***/
#include <stdio.h>
#include <stdlib.h>
#include "libpsgraph.h"

/* Disegna la curva di Koch di ordine n e lunghezza x */
void koch(double x, int n)
{
  /* [TODO] */
}

int main( void )
{
    start("square.ps");
    draw(100); turn(90);
    draw(100); turn(90);
    draw(100); turn(90);
    draw(100);
    end();
    /* [TODO] */
    return EXIT_SUCCESS;
}
