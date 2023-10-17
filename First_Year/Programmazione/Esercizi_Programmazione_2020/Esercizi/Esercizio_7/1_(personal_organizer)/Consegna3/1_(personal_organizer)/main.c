/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/12/09
Scrivere un programma C che simuli la gestione di un�agenda annuale e dei relativi appuntamenti.

Ogni appuntamento deve essere rappresentato da una struttura contenente giorno, mese, ora inizio, ora fine e descrizione.

Scrivere le funzioni: inserisci_appuntamento (verificare che nello stesso giorno e alla stessa ora non ci sia gi� un altro appuntamento), elimina_appuntamento, stampa_appuntamenti_del_mese
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h> //defining boolean variables in a hidden #define

#define MAX_DESCRIPTION_CHARACTERS 40  //Max number of characters for event description
#define clear() printf("\e[1;1H\e[2J") //alternatively

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other system
#define CLEAR "clear"
#endif

//define structure
typedef struct time_s
    {
        int day;
        int month;
        int starthour;
        int startminute;
        int endhour;
        int endminute;
    } time_tp;

    //struct for the appointments
    typedef struct appointment_s
    {
        struct appointment_s *previous;
        time_tp time;
        int order;
        char description[MAX_DESCRIPTION_CHARACTERS + 1];
        struct appointment_s *next;

    } appointment_t;





void newItem(appointment_t **first,appointment_t **last,appointment_t *cursor)
{

    system(CLEAR);
    //Insert description
    printf("Which is the description? (Warning! use univocal descriptions for specific delete! and maximum 7 characters)\n");
    char tempDescription[MAX_DESCRIPTION_CHARACTERS + 1];

    fgets(tempDescription, MAX_DESCRIPTION_CHARACTERS + 1, stdin);
    tempDescription[strlen(tempDescription) - 1] = '\0';
    //insert date
    int tempday;
    int tempmonth;

    while (1)
    {
        printf("Which day is the appointment? (dd/mm)\n");
        int good = scanf("%d/%d", &tempday, &tempmonth);
        fflush(stdin);
        int maxday = 0;

        switch (tempmonth)
        {
        //Ah February, the shortest month
        case 2:
            maxday = 29;
            break;
        //30 day months
        case 4:
        case 6:
        case 9:
        case 11:
            maxday = 31;
            break;
        //31 day months, the longest folks
        default:
            maxday = 32;
        }

        if ((good == 2) && (tempday < maxday) && (tempmonth < 13) && (tempday > 0) && (tempmonth > 0))
            break;

        printf("Invalid input, try again!\a\n");
    }
    //insert start times
    int tempStHour;
    int tempStMinute;

    while (1)
    {
        printf("At which time starts the appointment? (hh:mm) 24h format\n");
        int good = scanf("%02d:%02d", &tempStHour, &tempStMinute);
        fflush(stdin);

        if (good == 2 && tempStHour < 24 && tempStMinute < 60 && tempStHour >= 0 && tempStMinute >= 0)
            break;

        printf("Invalid input, try again!\a\n");
    }

    //insert ending times
    int tempEnHour;
    int tempEnMinute;
    while (1)
    {
        while (1)
        {
            printf("At which time ends the appointment? (hh:mm) 24h format\n");
            int good = scanf("%02d:%02d", &tempEnHour, &tempEnMinute);
            fflush(stdin);

            if (good == 2 && tempEnHour < 24 && tempEnMinute < 60 && tempEnHour >= 0 && tempEnMinute >= 0)
                break;

            printf("Invalid input, try again!\a\n");
        }
        //check if end time is possible
        if (tempStHour < tempEnHour)
            break;

        else if (tempStHour == tempEnHour && tempStMinute < tempEnMinute)
            break;

        printf("Ding dong, your time is wrong!(start after finish)\a\n");
    }
    //check if times already busy
    bool good = true;
    cursor = *first;

    while (cursor != NULL) //checks each element
    {
        if (tempday == cursor->time.day && tempmonth == cursor->time.month) //if the day is the same
        {
            //convert times in hhmm format, easier to manipulate
            int timestart = cursor->time.starthour * 100 + cursor->time.startminute;
            int timeend = cursor->time.endhour * 100 + cursor->time.endminute;
            int timeendTemp = tempEnHour * 100 + tempEnMinute;
            int timestartTemp = tempStHour * 100 + tempStMinute;

            //checks if times overlap
            if (timestart < timestartTemp && timestartTemp < timeend) //new start time betwen existing schedule
            {
                good = false;
                break;
            }

            if (timestart < timeendTemp && timeendTemp < timeend) //new end time betwen existing schedule
            {
                good = false;
                break;
            }

            if (timestartTemp < timestart && timestart < timeendTemp) //existing start time between new schedule
            {
                good = false;
                break;
            }

            if (timestartTemp < timeend && timeend < timeendTemp) //existing end time between new schedule
            {
                good = false;
                break;
            }
        }

        cursor = cursor->next; //check next item
    }

    if (good)
    {
        //creating appointment
        appointment_t *pos = (appointment_t *)malloc(sizeof(appointment_t)); //creating space
        if (pos == NULL)                                                     //crash the program otherwise
            exit(1);

        if (*first == NULL) //if the list is empty
        {
            *first = pos;
            *last = pos;
            pos->previous = NULL;
            pos->next = NULL;
        }

        else //otherwise add the item at the end, updating all the addresses
        {
            (*last)->next = pos;
            pos->previous = *last;
            pos->next = NULL;
            *(last) = pos;
        }

        //copying temp values
        strcpy(pos->description, tempDescription);
        pos->time.day = tempday;
        pos->time.month = tempmonth;
        pos->time.starthour = tempStHour;
        pos->time.startminute = tempStMinute;
        pos->time.endhour = tempEnHour;
        pos->time.endminute = tempEnMinute;
        printf("Item added succesfully, press a key to continue...\n");
    }
    else
        printf("schedule already busy in those times!(appointments overlap), press a key to continue...\a\n"); //print an error message if times overlap

    getch();
    fflush(stdin);
}


void del(appointment_t **first,appointment_t **last,appointment_t *cursor)
{
     //get the desription to delete
            system(CLEAR);
            printf("Type the exact description of the appointment to delete\n(in case of multiple appointments with the same name all the occurrences will be deleted)\n");
            char tempDescription[MAX_DESCRIPTION_CHARACTERS + 1];
            fgets(tempDescription, MAX_DESCRIPTION_CHARACTERS + 1, stdin);
            tempDescription[strlen(tempDescription) - 1] = '\0';

            cursor = *first;
            int deleted = 0;    //check each item
            while (cursor != NULL)
            {
                if (strcmp(cursor->description, tempDescription) == 0)  //if matches the search
                {
                    //correcting previous item
                    if (cursor->previous != NULL)
                        cursor->previous->next = cursor->next;

                    else    //the item was the first of the list
                        *first = cursor->next;
                    //correcting next item
                    if (cursor->next != NULL)
                        cursor->next->previous = cursor->previous;

                    else    //the item was the last of the list
                        *last = cursor->previous;

                    free(cursor);
                    deleted++;
                }
                cursor = cursor->next;  //go to the next
            }
            //print actions
            printf("%d item%c %s deleted\n", deleted, deleted > 1 ? 's' : '\0', deleted > 1 ? "were" : "Was");
            printf("Press any key to continue...\n");
            getch();
            fflush(stdin);
}

void printApp(appointment_t **first,appointment_t *cursor)
{
    int monthToprint = 0;
            int results = 0;

            while (1)   //ask which month to print
            {
                printf("Which month do you want to print?\n");
                int good = scanf("%02d", &monthToprint);

                if (monthToprint > 0 && monthToprint < 13 && good == 1)
                    break;

                printf("Invalid input, try again!\a\n");
            }
            printf("Description:\tdate:\tstart:\tend:\n");  //print title





            cursor=*first;
            int count=0;
            while (cursor != NULL)
            {
                cursor->order=0;                                   //initialize indexes
                if (cursor->time.month == monthToprint) count++;    //counts items to display
                cursor = cursor->next;
            }





    for(int i=1; i<=count; i++)                         //for each number assign the order
    {
        cursor = *first;         //check each item
        appointment_t * smallest =NULL;
        while (cursor != NULL)      //cycle each number to get smallest free
        {

            if (cursor->time.month == monthToprint) //if month matches
            {
                if(cursor->order==0)//and if it's free
                {
                    if(smallest==NULL||cursor->time.day*10000+cursor->time.starthour*100+cursor->time.startminute< smallest->time.day*10000+smallest->time.starthour*100+smallest->time.startminute)
                    {//if it's smaller than the record overwrites
                        smallest=cursor;

                    }
                }
            }
            cursor = cursor->next;
        }
        smallest->order=i;//assign order
    }

    for(int i=1; i<=count; i++)  //for each number print corresponding appointment
    {
        cursor=*first;
         while (cursor != NULL)
        {
            if(cursor->order==i){
                    printf("%s\t\t%02d/%02d\t%02d:%02d\t%02d:%02d\n", cursor->description, cursor->time.day, cursor->time.month, cursor->time.starthour, cursor->time.startminute, cursor->time.endhour, cursor->time.endminute);
                    results++;
            }
            cursor = cursor->next;
        }
    }


            //Printing results
            //if results are more than zero print results
            if (results > 0)
                printf(" %d result%c \npress any key to continue (Except the power button)\n", results, results > 1 ? 's' : '\0');

            else
                printf("no results found: press any key to continue (Except the power button)\n");

            getch();
            fflush(stdin);
}

//this is not a leap year (2021 agenda, we wanna forget about 2020, it's such an unlucky year, we hate leapers)

int main()
{
    //creating a struct for time management

    appointment_t *first = NULL; //to orient ourself in the list
    appointment_t *last = NULL;
    appointment_t *cursor = NULL;

    while (1) //MAIN CYCLE
    {
        system(CLEAR);
        char answer; //variable to store the intencions

        while (1) //print menu and get answer
        {
            printf("1)New Appointment\n2)Delete appointment\n3)Print appointment of a month\n0)exit\n");
            answer = getch();

            if (answer == '1' || answer == '2' || answer == '3' || answer == '0')
                break;

            printf("Invalid input, Try again!\a\n");
        }

        //new item
        if (answer == '1')
        {
           newItem(&first,&last,cursor);
        }
        //delete section
        if (answer == '2')
        {
            del(&first,&last,cursor);

        }

        if (answer == '3')
        {
            printApp(&first,cursor);
        }

        if (answer == '0')
            break;
    }

    //free malloc for each item
    cursor = first;

    while (cursor != NULL)
    {
        appointment_t *cursorNext = cursor->next;
        free(cursor);
        cursor = cursorNext;
    }

    return 0;
}
