/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 3
 Descrizione:	Comprimere in run-length una sequenza di byte. Il risultato deve
				essere inserito in un vettore con il seguente formato:
				byte 0: <numero di occorrenze del byte seguente>, 
				byte 1: <valore del byte>
				byte 2: <numero di occorrenza del byte seguente>
				byte 3: <valore del byte>
				...
				byte N-2: <numero di occorrenza del byte seguente>
				byte N-1: <valore del byte>
				byte N: 0 (il byte 0: indica la fine dei dati compressi)

 ********************************************************************************/
#include <stdio.h>


void main()
{
// Variabili
#define MaxLen 1024
int Len = 30;							// Lunghezza della sequenza da comprimere
unsigned char Buffer[MaxLen] = {1,2,3,3,3,3,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,	// I dati da
								4,5,99,99,99,255,255,255,255};				// comprimere
#define MaxLenComp (MaxLen*2+1)
unsigned char BufComp[MaxLenComp];		// Vettore in cui mettere i dati compressi

// Blocco assembler
	__asm
	{
   	}

// Stampa su video
	{
		int i;				
		for (i=0;i<Len;i++)
		{
			printf("%02X ",Buffer[i]);
		}
		printf("\n");
		for (i=0;BufComp[i];)
		{
			printf("%3d ",BufComp[i++]);
			printf("%02X ",BufComp[i++]);
		}
		printf("\n");
	}
}


