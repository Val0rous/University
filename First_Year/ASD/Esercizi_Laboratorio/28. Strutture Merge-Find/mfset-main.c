/****************************************************************************
 *
 * mfset-main.c -- Programma demo per strutture Merge-Find
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
#include "mfset.h"

int main( int argc, char *argv[] )
{
    char op;
    int x, y, n;
    MFSet s;
    FILE *filein = stdin;

    if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    if (1 != fscanf(filein, "%d", &n)) {
        fprintf(stderr, "Missing size\n");
        return EXIT_FAILURE;
    }
    printf("CREATE %d\n", n);
    mfset_init(&s, n);

    while (1 == fscanf(filein, " %c", &op)) {
        switch (op) {
        case 'm': /* merge */
            fscanf(filein, "%d %d", &x, &y);
            printf("UNION %d %d\n", x, y);
            mfset_merge(&s, x, y);
            break;
        case 'q': /* query */
            fscanf(filein, "%d %d", &x, &y);
            printf("QUERY %d %d = %d\n", x, y,
                   mfset_find(&s, x) == mfset_find(&s, y));
            break;
        default:
            printf("Unknown command %c\n", op);
        }
    }

    mfset_destroy(&s);

    return EXIT_SUCCESS;
}
