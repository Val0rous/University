/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/10/30
Scrivere un programma C che riceva in ingresso due parole inserite da tastiera. Si consideri che ciascuna parola pu� contenere al massimo 30 caratteri.
Il programma deve essere case sensitive, cio� deve distinguere lettere minuscole da lettere maiuscole e deve essere in grado anche di analizzare numeri, simboli e segni di punteggiatura.
Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola con il carattere �*�. Ad esempio, inserite le parole

abchdfffchdchdtlchd

e

chd

il programma deve visualizzare la parola

ab*fff**tl*

Scrivere due versioni: la prima deve ignorare la presenza della libreria string.h e quindi dovete lavorare esplicitamente su ogni singolo carattere delle stringhe.
La seconda deve usare le funzioni della libreria string.h per determinare la lunghezza e per ricercare sotto-stringhe all'interno di una stringa
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[31];
    char str2[31];
    int lung1 = 0, lung2 = 0, i = 0;
    int ris = 0, verifica;


    printf("Inserisci la prima stringa : ");
    scanf("%s", &str1);
    fflush(stdin);

    printf("Inserisci la seconda stringa : ");
    scanf("%s", &str2);
    fflush(stdin);

    printf("\nShall i use the library?\nNo String.h (0) \nString.h (1)\n");
    scanf("%d", &ris);
    fflush(stdin);

    if(ris==0) {


        while(str1[lung1] != NULL) {
            lung1++;
        }


        while(str2[lung2] != NULL) {
            lung2++;
        }


        for(i = 0; i + (lung2 - 1) < lung1; i++) {  //scorre la prima stringa

            verifica = 1 ; //le sottostringhe sono uguali

            for(int k = 0; k < lung2 && verifica == 1; k++){ //scorre la seconda stringa
                if (str1[i+k] != str2[k])
                    verifica = 0; // se le sottostringhe non sono uguali la verifica = 0
            }

            if(verifica == 1) {
            for(int k=0; k < lung2; k++){
                str1[i + k] = '*';
            }

            i = i + lung2 - 1; //vado alla posizione successiva agli asterischi nella prima stringa
            }
        }

        printf("Risultato : %s", str1) ;

        return 0;

    }
    else {

        lung1=strlen(str1);
        //printf("\n%d", lung1);

        lung2=strlen(str2);
        //printf("\n%d", lung2);






        }
}

