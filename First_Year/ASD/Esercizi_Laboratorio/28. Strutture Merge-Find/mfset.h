/****************************************************************************
 *
 * mfset.h -- Interfaccia Merge-Find
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

#ifndef MERGE_FIND_H
#define MERGE_FIND_H

typedef struct {
    int n;  /* Numero di elementi   */
    int *p; /* Array di padri       */
    int *h; /* Altezze degli alberi */
} MFSet;

/* Inizializza una struttura merge-find composta da n elementi disgiungi */
void mfset_init(MFSet *s, int n);

/* Distruggi la struttura merge-find */
void mfset_destroy(MFSet *s);

/* Fonde gli insiemi contenenti x e y; se x e y già appartengono allo
   stesso insieme, non fa nulla. */
void mfset_merge(MFSet *s, int x, int y);

/* Restituisce l'id del rappresentante dell'insieme contenente x */
int mfset_find(MFSet *s, int x);

#endif
