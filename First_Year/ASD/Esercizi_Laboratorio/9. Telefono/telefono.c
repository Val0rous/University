/****************************************************************************
 *
 * telefono.c -- Trova il minimo numero di telefono duplicato
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
% LabASD - Trova il minimo numero di telefono duplicato
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-12

Siete stati assunti come consulenti dalla IATM S.p.A. (Importante
Azienda di Telefonia Mobile) che è alle prese con il problema
seguente. L'azienda ha un file contenente $n$ numeri di telefono, $n >
200000$. Tutti i numeri hanno sei cifre, la prima delle quali può
essere `3` oppure `5`; i numeri di telefono non sono ordinati e sono
presenti duplicati. Infatti, ci sono esattamente 200000 numeri di
telefono fatti in questo modo, e l'input ne ha più di 200000, per cui
è sicuramente presente almeno un numero di telefono che compare più di
una volta. Il vostro compito è di implementare un algoritmo efficiente
che calcoli il minimo numero di telefono che compare almeno due volte
nel file di input.

Il file di input ha la struttura seguente:

```
n
tel_0
tel_1
...
tel_n-1
```

dove `n` è il numero di valori dell'array, e `tel_0`, ... `tel_n-1`
sono i numeri di telefono.

## Per approfondire

Forse la parte più complicata di questo esercizio è la generazione dei
file di input. Dato un intero $n$ e un numero di telefono $t$, come
fareste per generare un input in cui il minimo numero di telefono
ripetuto almeno due volte sia esattamente $t$?

## File

- [telefono.c](telefono.c)
- [telefono1.in](telefono1.in)
- [telefono2.in](telefono2.in)
- [telefono3.in](telefono3.in)

***/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
    return EXIT_SUCCESS;
}
