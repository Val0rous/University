/****************************************************************************
 *
 * queue.h -- Interfaccia coda
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

#ifndef QUEUE_H
#define QUEUE_H

/* Tipo degli elementi contenuti nella coda (default int) */
typedef int QueueInfo;

typedef struct {
    int capacity;
    int head, tail;
    QueueInfo *data;
} Queue;

/* Inizializza la coda */
void queue_init(Queue *q);

/* Dealloca la coda */
void queue_destroy(Queue *q);

/* Inserisci un elemento in fondo alla coda */
void queue_enqueue(Queue *q, QueueInfo val);

/* Rimuovi e ritorna l'elemento all'inizio della coda */
QueueInfo queue_dequeue(Queue *q);

/* Ritorna 1 se e solo se la coda e' vuota */
int queue_is_empty(const Queue *q);

/* Ritorna il numero di elementi nella coda */
int queue_size(const Queue *q);

/* Stampa il contenuto della coda */
void queue_print(const Queue *q);

#endif
