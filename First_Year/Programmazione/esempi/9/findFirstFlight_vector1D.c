/* Find the first flight from a list of available */

#include <stdlib.h>
#include <stdio.h>

#define NUMFLIGHTS 10

int main()
{
    /* List of available flights */
    int list[NUMFLIGHTS];
    int i, j, index, hh, mm, timeInput, timeFirst, hhfirst, mmfirst;
    char point;

    /* times of available flights:
    hh.mm
    08:15 ->
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
    list[0]=(8*60)+15;
    list[1]=(9*60)+30;
    list[2]=(10*60)+45;
    list[3]=(12*60)+0;
    list[4]=(13*60)+15;
    list[5]=(14*60)+30;
    list[6]=(15*60)+45;
    list[7]=(17*60)+0;
    list[8]=(18*60)+15;
    list[9]=(19*60)+30;

    /* Print the list of available fights */
    printf("List of available flights:\n");
    for (i=0; i<NUMFLIGHTS; i++)
    {
        hhfirst = list[i]/60;
        mmfirst = list[i]%60;
        printf("\tFlight %2d: %02d.%02d\n", i+1, hhfirst, mmfirst);
    }

    /* Ask the time to the user */
    printf("\nInsert the time of the arrival at the airport in the format hh.mm (24-hours):\n");
    scanf("%2d%c%2d", &hh, &point, &mm);
    timeInput = (hh*60)+mm;

    /* Find the first flight available */
    index = 0;
    timeFirst = list[0];
    for (i=0; i<NUMFLIGHTS; i++)
    {
        if (timeInput < list[i])
        {
            index = i;
            timeFirst = list[i];
            break;
        }
    }
    hhfirst = list[i]/60;
    mmfirst = list[i]%60;

    printf("\nThe first flight available leaves at: %02d.%02d\n", hhfirst, mmfirst);
    printf("\nThe following flights available leave at:\n");
    for (i=index+1; i<NUMFLIGHTS; i++)
    {
        hhfirst = list[i]/60;
        mmfirst = list[i]%60;
        printf("\t%02d.%02d\n", hhfirst, mmfirst);
    }

	printf("\n\n");
    system("PAUSE");
    return 0;
}
