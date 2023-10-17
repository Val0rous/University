/****************************************************************************
 *
 * bst-main.c -- Demo alberi binari di ricerca
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
#include "bst.h"

/* Nota: il main assume che BSTKey sia il tipo "int" */
int main( int argc, char *argv[] )
{
    char op;
    BSTKey k;
    BST T;
    BSTNode *n;
    FILE *filein = stdin;

    if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    bst_init(&T);

    while (1 == fscanf(filein, " %c", &op)) {
        switch (op) {
        case '+': /* insert */
            fscanf(filein, "%d", &k);
            printf("INSERT %d\n", k);
            bst_insert(&T, k);
            break;
        case '-': /* delete */
            fscanf(filein, "%d", &k);
            printf("DELETE %d\n", k);
            n = bst_search(&T, k);
            if (n) {
                bst_delete(&T, n);
            } else {
                printf("NOT FOUND\n");
            }
            break;
        case '?': /* search */
            fscanf(filein, "%d", &k);
            printf("SEARCH %d = ", k);
            n = bst_search(&T, k);
            if (n) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
            break;
        case 's': /* size */
            printf("SIZE = %d\n", bst_size(&T));
            break;
        case 'h': /* height */
            printf("HEIGHT = %d\n", bst_height(&T));
            break;
        case 'p': /* print */
            bst_print(&T);
            break;
        default:
            printf("Unknown command %c\n", op);
            exit(EXIT_FAILURE);
        }
    }

    bst_destroy(&T);

    return EXIT_SUCCESS;
}
