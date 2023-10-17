/****************************************************************************
 *
 * shooting-stars.c - Shooting Stars
 *
 * Copyright (C) 2018, 2019, 2021 Moreno Marzolla
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
% LabASD - Shooting Stars
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: LASTUPDATED

"Shooting stars" è un gioco di strategia descritto a p. 42 della
rivista [BYTE Magazine n. 9, maggio
1976](https://archive.org/details/byte-magazine-1976-05/page/n43/mode/1up).

![](shooting-stars.jpg)

Il gioco si svolge su una griglia $3 \times 3$ le cui celle sono
numerate da 0 a 8 come segue:

```
012
345
678
```

Ogni cella può contenere una stella (`*`) oppure un buco nero
(`.`). La configurazione iniziale contiene una singola stella nella
cella 4:

```
...
.*.
...
```

Ad ogni turno il giocatore può far "esplodere" una stella digitando il
numero della cella corrispondente. Una stella esplosa si trasforma in
un buco nero; inoltre, i frammenti della stella vanno a finire in
alcune delle celle adiacenti, trasformando i buchi neri in stelle, e
le stelle in buchi neri. Il vicinato è definito in modo differente per
ogni cella, ed è rappresentato con un `#` dalle figure seguenti:

```
0#.  #1#  .#2 
##.  ...  .##
...  ...  ...

#..  .#.  ..# 
3..  #4#  ..5
#..  .#.  ..#

...  ...  ... 
##.  ...  .##
6#.  #7#  .#8
```

quindi il vicinato della cella 0 è costituita da (0, 1, 3, 4); il
vicinato della cella 1 è costituito da (0, 1, 2); il vicinato della
cella 2 è costituito da (1, 2, 4, 5), e così via. In pratica, fare
esplodere la stella in posizione $k$ significa trasformare stelle in
buchi neri (e viceversa) nella cella $k$ e in quelle "vicine" secondo
le figure sopra.

Ad esempio, supponiamo che la configurazione corrente sia la seguente
(per facilitare la lettura, le celle contenenti una stella sono indicate
con il rispettivo numero):

```
.1.
.45
6..
```

Il giocatore può scegliere di fare esplodere una tra le stelle 1, 4,
5, 6. Se decide di fare esplodere la stella 1, la nuova configurazione
sarà

```
0.2
.45
6..
```

Se ora decide di fare esplodere la stella 4, la nuova configurazione
sarà

```
012
3..
67.
```

e così via.

Per vincere a questo gioco occorre ottenere la configurazione

```
012
3.5
678
```

mentre si perde se si ottiene la configurazione contenente solo buchi neri

```
...
...
...
```

(infatti, per le regole del gioco a questo punto non è possibile far
esplodere alcuna stella).

Compilare il programma con 

        gcc -std=c90 -Wall -Wpedantic shooting-stars.c -o shooting-stars

Eseguire con

        ./shooting-stars

## Per approfondire

Alla fine del corso sarete in grado di scrivere un programma
efficiente in grado di rispondere a queste domande:

- Qual è il numero minimo di mosse necessarie a vincere?

- Qual è la sequenza di mosse che porta alla vittoria nel minor numero di passi?

- Qual è il numero minimo di mosse necessarie a perdere (cioè
  a raggiungere la configurazione vuota)?

- Esiste una configurazione di stelle/buchi neri che non può essere
  generata dallo stato iniziale effettuando solo mosse valide?

Per il momento è sufficiente completare il programma in modo da
consentire all'utente di giocare una partita.

## File

- [shooting-stars.c](shooting-stars.c)

***/
#include <stdio.h>
#include <stdlib.h>


int main( void )
{
    return EXIT_SUCCESS;
}
