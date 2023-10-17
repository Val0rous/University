/* Find the first flight from a list of available */

#include <stdlib.h>
#include <stdio.h>

#define NUMFLIGHTS 10

int main()
{
    /* List of available flights */
    int list[2][NUMFLIGHTS];
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
    list[0][0]=8;  list[1][0]=15;
    list[0][1]=9;  list[1][1]=30;
    list[0][2]=10; list[1][2]=45;
    list[0][3]=12; list[1][3]=0;
    list[0][4]=13; list[1][4]=15;
    list[0][5]=14; list[1][5]=30;
    list[0][6]=15; list[1][6]=45;
    list[0][7]=17; list[1][7]=0;
    list[0][8]=18; list[1][8]=15;
    list[0][9]=19; list[1][9]=30;

    /* Print the list of available fights */
    printf("List of available flights:\n");
    for (i=0; i<NUMFLIGHTS; i++)
    {
        printf("\tFlight %2d: %02d.%02d\n", i+1, list[0][i], list[1][i]);
    }

    /* Ask the time to the user */
    printf("\nInsert the time of the arrival at the airport in the format hh.mm (24-hours):\n");
    scanf("%2d%c%2d", &hh, &point, &mm);
    fflush(stdin);

    /* Find the first flight available */
    index = 0;
    hhfirst = list[0][0];
    mmfirst = list[1][0];
    for (i=0; i<NUMFLIGHTS; i++)
    {
        if (hh<=list[0][i])
        {
            if (mm<list[1][i])
            {
                hhfirst = list[0][i];
                mmfirst = list[1][i];
                break;
            }
            else
            {
                if (i<NUMFLIGHTS-1)
                {
                    hhfirst = list[0][i+1];
                    mmfirst = list[1][i+1];
                    break;
                }
            }
        }
    }

    printf("\nThe first flight available leaves at: %02d.%02d\n", hhfirst, mmfirst);

    return 1;
}
