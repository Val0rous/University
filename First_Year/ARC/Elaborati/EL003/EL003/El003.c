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
	/*
int Len = 30;							// Lunghezza della sequenza da comprimere
unsigned char Buffer[MaxLen] = {1,2,3,3,3,3,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,	// I dati da
								4,5,99,99,99,255,255,255,255};				// comprimere
*/
	int Len = 258;
	unsigned char Buffer[MaxLen] = { 97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,255 };
#define MaxLenComp (MaxLen*2+1)
unsigned char BufComp[MaxLenComp];		// Vettore in cui mettere i dati compressi

// Blocco assembler
	__asm
	{
		//azzero tutti i registri
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EDI, EDI
		XOR ESI, ESI

		//ESI = carattere iniziale
		//EDI = caratteri seguenti

		//megaciclo per spostare ESI
		megaciclo:	MOV BL, Buffer[ESI]
					INC EDI
					//ciclo per spostare EDI
					ciclo:	MOV BH, Buffer[EDI]
							CMP BH, BL
							JNE aggiorna

							INC EDI
							//necessario per evitare che venga conteggiata una sfilza di zeri automaticamente generati alla fine
							CMP EDI, Len
							JA eccezionezeri

							CMP EDI, 255
							JE aggiorna

							JMP ciclo

					//aggiorna vettore BufComp[] <=> trova un elemento diverso
					aggiorna:	//contatore
								MOV EAX, EDI
								SUB EAX, ESI
								MOV BufComp[ECX], AL
								INC ECX
								XOR EAX,EAX

								//valore
								MOV BufComp[ECX], BL
								INC ECX
								MOV ESI, EDI
								
					CMP EDI, Len
					JB megaciclo

		//l'ultimo elemento, dopo le coppie (contatore, valore), deve essere 0 per definizione
		eccezionezeri:	MOV BufComp[ECX], 0x00

			

   	}

// Stampa su video
	{
		int i;				
		for (i=0;i<Len;i++)
		{
			printf("%02X ",Buffer[i]);	//array items
		}
		printf("\n");
		for (i=0;BufComp[i];)
		{
			printf("%3d ",BufComp[i++]);	//decimal
			printf("%02X ",BufComp[i++]);	//hex
		}
		printf("\n");
	}
}


