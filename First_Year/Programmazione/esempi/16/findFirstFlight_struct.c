/* Find the first flight from a list of available */

#include <stdlib.h>
#include <stdio.h>

#define NUMFLIGHTS 10

struct tempo{
	int ora;
	int minuto;
};

struct tempo voli[NUMFLIGHTS] = {{8,15},{9,30},{10,45},{12,0},{13,15},{14,30},{15,45},{17,00},{18,15},{19,30}};

int main()
{
    int i, j, index, hh, mm, hhfirst, mmfirst;
    char point;

    /* times of available flights:
    hh.mm
    08:15
    09:30
    10:45
    12:00
    13:15
    14:30
    15:45
    17:00
    18:15
    19:30
    */

    /* Print the list of available fights */
    printf("List of available flights:\n");
    for (i=0; i<NUMFLIGHTS; i++)
    {
        printf("\tFlight %2d: %02d.%02d\n", i+1, voli[i].ora, voli[i].minuto);
    }

    /* Ask the time to the user */
    printf("\nInsert the time of the arrival at the airport in the format hh.mm (24-hours):\n");
    scanf("%2d%c%2d", &hh, &point, &mm);
    fflush(stdin);

    /* Find the first flight available */
    hhfirst = voli[0].ora;
    mmfirst = voli[0].minuto;
    for (i=0; i<NUMFLIGHTS; i++)
    {
        if (hh<=voli[i].ora)
        {
            if (mm<voli[i].minuto || hh<voli[i].ora)
            {
                hhfirst = voli[i].ora;
                mmfirst = voli[i].minuto;
                break;
            }
        }
    }

    printf("\nThe first flight available leaves at: %02d.%02d\n", hhfirst, mmfirst);

    return 1;
}
