/****************************************************************************
 *
 * hashtable.h -- Interfaccia hash table
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
#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **items;
    int size;
    int values_count;
} HashTable;

/* Questa funzione mappa un intero k arbitrario in una posizione
   dell'array *items[] dell'hash table */
unsigned long hash_function(const HashTable *table, unsigned long k);

/* Trasforma una sequenza di caratteri in un intero senza segno;
   l'implementazione proposta in hashtable.c non e' robusto contro le
   collisioni, per cui non va usato in applicazioni reali. */
unsigned long encode(const char *key);

/* Inizializza la hash table `size` slot */
void ht_init(HashTable *table, int size);

/* Libera tutta la memoria occupata dall'hash table */
void ht_destroy(HashTable *table);

/* Inserisci la coppia (key, value) nella hash table. Se la chiave e'
   già presente, aggiorna il valore associato al vecchio nodo gia'
   presente. Se viene creato un nuovo nodo nella hash table, questa
   funzione deve copiare il contenuto della chiave nel nodo.
   Restituisce 1 se viene creato un nuovo nodo, 0 se viene aggiornato
   un nodo esistente. */
int ht_insert(HashTable *table, const char *key, int value);

/* Ritorna il nodo contenente le informazioni associate alla chiave
   `key`; se la chiave non è presente, ritorna NULL */
HashNode *ht_search(HashTable *table, const char *key);

/* Rimuove la chiave `key` dalla hash table; se la chiave non è
   presente, non fa nulla. Ritorna 1 se la chiave era presente ed è
   stata cancellata, 0 altrimenti (chiave non presente, quindi non
   cancellata). */
int ht_delete(HashTable *table, const char *key);

/* Ritorna il numero di coppie (chiave, valore) presente nella hash
   table */
int ht_count(const HashTable *table);

#endif
