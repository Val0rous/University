/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ****************************************************************************
 Elaborato 1
 Descrizione: Data una stringa contenente una frase, contare le occorrenze di
     ogni lettera dell'alfabeto (senza distinzione tra lettere
     maiuscole e minuscole).
     N.B.: le lettere accentate non sono da considerare.
 ********************************************************************************/

#include <stdio.h>

void main()
{
    // Input: frase da valutare
    char frase[] = "Questa e' UNA FrASe di PROVA per l'elABOrato 1";

    // Output
    unsigned short occorrenze[26]; //Occorrenze delle 26 lettere dell'alfabeto

    __asm
    {
            XOR ECX, ECX
            XOR EAX, EAX
            XOR EBX, EBX
            //inizializzazione vettore occorrenze
            MOV ECX, 26
        
        inizializzazione:   //sets entire array to 0
            MOV occorrenze[ECX * 2 - 2], 0
            LOOP inizializzazione

        ripeti:
            MOV BL, frase[EAX] //di volta in volta salvo in BL il carattere da controllare
            //controllo terminatore per vedere se si � giunti a fine frase
            CMP BL, 0
            JE fine
            //se il carattere preso in considerazione � speciale, si passa al successivo con "avanti", altrimenti lo si controlla normalmente con "inizio"
            CMP BL, 1
            JGE caratteriSpeciali1
            CMP BL, 91
            JGE caratteriSpeciali2
            CMP BL, 123
            JGE avanti
            JMP inizio
        caratteriSpeciali1 :
            CMP BL, 64
            JLE avanti
            JMP inizio
        caratteriSpeciali2 :
            CMP BL, 96
            JLE avanti
            JMP inizio
            //faccio uso della corrispondenza char-int con la tabella ASCII
        inizio :
            CMP BL, 97 //inizio caratteri minuscoli
            JGE controllo2
            CMP BL, 65 //inizio caratteri maiuscoli
            JGE controllo1
        controllo1 :
            CMP BL, 90 //fine caratteri maiuscoli
            JLE trasformaMaiuscolo
        controllo2 :
            CMP BL, 122 //fine caratteri minuscoli
            JLE trasformaMinuscolo
        trasformaMinuscolo: //porto gli int che mi indicano un carattere minuscolo nel range 0-25
            SUB BL, 97
            JMP continua
        trasformaMaiuscolo: //porto gli int che mi indicano un carattere maiuscolo nel range 0-25
            SUB BL, 65
        continua:
            INC occorrenze[EBX * 2]  //l'indice viene salvato su BL, incremento nella giusta posizione per ogni occorrenza trovata
        avanti:
            INC EAX //incremento EAX per andare a controllare il carattere successivo
            JMP ripeti
        fine:
    }

    // Stampa su video
    {
        int i;
        for (i = 0; i < 26; i++)
        {
            printf("%c: %d\n", 97 + i, occorrenze[i]);
        }
    }
}