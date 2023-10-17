/****************************************************************************
 *
 * list-main.c -- Demo lista
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

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Nota: si assume che ListInfo sia il tipo "int" */
int main( int argc, char *argv[] )
{
    char op;
    ListInfo k;
    List L;
    ListNode *n;
    FILE *filein = stdin;
    
    if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }
    
    list_init(&L);
    
    while (1 == fscanf(filein, " %c", &op)) {
        switch (op) {
        case '+': /* insert */
            fscanf(filein, "%d", &k);
            printf("INSERT %d\n", k);
            list_add_first(&L, k);
            break;
        case '-': /* delete */
            fscanf(filein, "%d", &k);
            printf("DELETE %d ", k);
            n = list_search(&L, k);
            if (n != list_end(&L)) {
                list_remove(&L, n);
                printf("OK\n");
            } else {
                printf("NOT FOUND\n");
            }
            break;
        case '?': /* search */
            fscanf(filein, "%d", &k);
            printf("SEARCH %d ", k);
            n = list_search(&L, k);
            if (n != list_end(&L)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
            break;
        case 'c': /* count */
            printf("LENGTH %d\n", list_length(&L));
            break;
        case 'p': /* print */
            list_print(&L);
            break;
        case 'd': /* empty */
            printf("REMOVE ALL\n");
            list_remove_all(&L);
            break;
        default:
            fprintf(stderr, "Unknown command %c\n", op);
        }            
    }

    list_destroy(&L);        

    return EXIT_SUCCESS;
}
