//DEPRECATED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_RUBRICA 100
#define MAX_VOCE 50

int main()
{
    //dichiarazione variabili
    char rubrica[MAX_RUBRICA][MAX_VOCE + 1] = {0}, temp[MAX_RUBRICA];
    char numTel[11], voce[MAX_VOCE + 1];
    int scelta, ch, i, j, dummy = 0;
    double numero;
    char nomeCercato[MAX_VOCE], nome[MAX_RUBRICA][MAX_VOCE];
    char spazio[MAX_VOCE] = " | ";
    char nomeApprossimativo[MAX_VOCE];
    bool success;

    while (1)
    {
        system("cls");
        printf("\n\n*****RUBRICA MENU*****\n\n");
        printf("1)NUOVA VOCE\n");
        printf("2)RICERCA ESATTA\n");
        printf("3)RICERCA APPROSSIMATIVA\n");
        printf("4)STAMPA LA RUBRICA\n");
        printf("0)ESCI");
        printf("\n\n**********************\n\n");

        printf("\n\n>");
        scanf("%d", &scelta);

        //aggiungi nuova voce
        if (scelta == 1)
        {
            success = true;
            system("cls");
            if (dummy == MAX_RUBRICA)
                printf("\n\n*****RUBRICA PIENA*****\n\n");
            else
            {
                printf("\tNUMERO : ");
                //scanf("%10lf",&numero);
                //sprintf(numTel,"%10lf",numero);
                scanf("%10s", numTel);
                fflush(stdin);
                printf("\tNOME : ");
                i = 0;
                while ((ch = getchar()) != '\n')
                {
                    if (i < MAX_VOCE)
                    {
                        voce[i++] = ch;
                    }
                }

                voce[i] = '\0';
                for (j = 0; j <= strlen(voce); j++)
                {
                    voce[j] = toupper(voce[j]);
                }
                strcpy(nome[dummy], voce);
                for (i = 0; i <= dummy; i++)
                {
                    for (j = i + 1; j <= dummy; j++)
                    {
                        if (strcmp(nome[i], nome[j]) == 0)
                        {
                            success = false;
                        }
                    }
                }
                strcpy(rubrica[dummy], voce);
                strcat(rubrica[dummy], spazio);
                strcat(rubrica[dummy], numTel);

                for (i = 0; i <= dummy; i++)
                {
                    for (j = i + 1; j <= dummy; j++)
                    {
                        if (strcmp(rubrica[i], rubrica[j]) > 0)
                        {
                            strcpy(temp, rubrica[i]);
                            strcpy(rubrica[i], rubrica[j]);
                            strcpy(rubrica[j], temp);

                            strcpy(temp, nome[i]);
                            strcpy(nome[i], nome[j]);
                            strcpy(nome[j], temp);
                        }
                    }
                }
                dummy++;
                system("cls");
                if (success)
                    printf("\n\n**************CONTATTO AGGIUNTO*************\n\n");
                else
                {
                    printf("\n\n*****ESISTE GIA' QUESTA VOCE*****\n\n");
                    dummy--;
                }
            }
            printf("\n\n*****PREMI UN TASTO PER TORNARE AL MENU*****\n\n");
            fflush(stdin);
            getchar();
        }
        //ricerca esatta
        if (scelta == 2)
        {
            system("cls");
            fflush(stdin);
            printf("NOME>");
            //scanf("%s",nomeCercato);
            memset(nomeCercato, 0, sizeof(nomeCercato));
            i = 0;
            while ((ch = getchar()) != '\n')
            {
                if (i < MAX_VOCE)
                {
                    nomeCercato[i++] = ch;
                }
            }
            nomeCercato[i] = '\0';
            for (j = 0; j <= strlen(nomeCercato); j++)
            {
                nomeCercato[j] = toupper(nomeCercato[j]);
            }
            system("cls");
            for (i = 0; i < dummy; i++)
            {
                if (strcmp(nomeCercato, nome[i]) == 0)
                {
                    success = true;
                    break;
                }
                else
                    success = false;
            }
            if (success)
                printf("\n\n*****VOCE CORRISPONDENTE*****\n\t%s\n", rubrica[i]);
            else
                printf("\n\n*****NESSUNA VOCE CORRISPONDENTE*****\n\n");
            printf("\n\n*****PREMI UN TASTO PER TORNARE AL MENU*****\n\n");
            fflush(stdin);
            getchar();
        }
        //ricerca approssimativa
        if (scelta == 3)
        {
            fflush(stdin);
            system("cls");
            memset(nomeApprossimativo, 0, sizeof(nomeApprossimativo));
            printf("CERCA>");
            i = 0;
            while ((ch = getchar()) != '\n')
            {
                if (i < MAX_VOCE)
                {
                    nomeApprossimativo[i++] = ch;
                }
            }
            nomeApprossimativo[i] = '\0';
            for (j = 0; j <= strlen(nomeApprossimativo); j++)
            {
                nomeApprossimativo[j] = toupper(nomeApprossimativo[j]);
            }
            system("cls");
            printf("\n\n*****VOCI DOVE COMPAIONO I CARATTERI INSERITI (SE CI SONO)*****\n\n");
            for (i = 0; i <= dummy; i++)
            {
                if (strstr(rubrica[i], nomeApprossimativo) != NULL)
                {
                    printf("\t%s\n", rubrica[i]);
                }
            }
            printf("\n\n*****PREMI UN TASTO PER TORNARE AL MENU*****\n\n");
            fflush(stdin);
            getchar();
        }
        //stampa rubrica
        if (scelta == 4)
        {
            system("cls");
            printf("\n\n\tRUBRICA\n\n");
            for (int i = 0; i <= dummy; i++)
            {
                printf("\t%s\n", rubrica[i]);
            }
            fflush(stdin);
            printf("\n\n*****PREMI UN TASTO PER TORNARE AL MENU*****\n\n");
            getchar();
        }
        //esci
        if (scelta == 0)
        {
            system("cls");
            break;
        }
    }
    printf("\n\n*****RUBRICA CHIUSA*****\n\n");
    system("pause");
    return (0);
}
