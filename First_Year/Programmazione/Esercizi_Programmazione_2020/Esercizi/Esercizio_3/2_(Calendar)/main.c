/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

            Let us know if it's over or under commented, thanks for understendig!

DATE: 2020/10/16

Scrivere un programma C che stampi il calendario di un anno,
chiedendo all'utente di specificare l'anno in oggetto
e il numero che identifica il primo giorno dell'anno
(1=lunedì, 7=domenica).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int year, startDay;     //Initializing variables
    do
    {                                                                                        //Using a do-while loop 'cause we want the code
    printf("Type a year and the starting day, I will print the calendar!\n");                //to be executed at least once, repeating if the input
    printf("Do you prefer to give me the first day of the week of the 1st of January?\n");   //if it is not acceptable
    printf("Otherwise I can calculate it automatically! Type 1(Mon),2(Tue)etc. or \'0\' for auto\n");
    printf("Format: YYYY d\n");
    scanf("%d %d", &year, &startDay);
    fflush(stdin);
    if(year<1583||year>3000||startDay<0||startDay>7) //Skipping the 10 days that never existed in 1582 (transitioning from Julian to Gregorian Calendar)
    {
        printf("\nPlease type in a correct value for year and starting day\n\n");
    }
    else {
            break;}                              //If input is acceptable, get out of the loop
    }                                            //As 1 is TRUE, the loop's gonna iterate forever, unless the else condition is met and the code can get out of the loop
    while(1);

    if(startDay==0){                             //auto function: there is surely a better method (we are almost complete beginners) on the net but we preferred to come up with our own one, where would be the fun otherwise?
        int diffYears=year-2018;                 //starting from 2018 (where we know the starting day is Mon we calculate the difference
        int diffDays;
        if(diffYears>=0){
            for(int i=0;i<diffYears;i++){        //if the difference is positive count the difference of day summing each year in between (distinguishing if it's leap)
                if((2018+i)%400==0 || ((2018+i)%100!=0 && (2018+i)%4==0))
                   {
                   diffDays+=366;
                   }
                else diffDays+=365;
            }
        startDay=diffDays%7+1;                  //update the new start day using the module of 7, +1 since it starts from Monday (1)
        }
        else{                                   //if the difference is negative
            diffYears=-diffYears;               //converting it into positive
            for(int i=1;i<diffYears;i++){       //the starting condition now is 1 because we don't have to subtract 2018
            if((2017-i)%400==0 || ((2017-i)%100!=0 && (2017-i)%4==0)) //as before counting the difference of days from the 1st of January 2018
                   {
                   diffDays+=366;
                   }
                else diffDays+=365;
            }
        startDay=7-(diffDays%7);                //since now we are going backwards we have to subtract the previous formula to 7
        }

    }

    //CALENDAR PRINTING

    for (int month=1; month<=12; month++){
        int daysInMonth;
        switch (month){                                         //Defining name and number of days for each month
            case 1:
            printf("\nJANUARY\n");
            daysInMonth=31;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 2:
            printf("FEBRUARY\n");                               //distinguishes the leap years
            if(year%400==0 || (year%100!=0 && year%4==0))
            {
            daysInMonth=29;
            }
            else daysInMonth=28;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 3:
            printf("MARCH\n");
            daysInMonth=31;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 4:
            printf("APRIL\n");
            daysInMonth=30;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 5:
            printf("MAY\n");
            daysInMonth=31;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 6:
            printf("JUNE\n");
            daysInMonth=30;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 7:
            printf("JULY\n");
            daysInMonth=31;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 8:
            printf("AUGUST\n");
            daysInMonth=31;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 9:
            printf("SEPTEMBER\n");
            daysInMonth=30;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 10:
            printf("OCTOBER\n");
            daysInMonth=31;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 11:
            printf("NOVEMBER\n");
            daysInMonth=30;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;

            case 12:
            printf("DECEMBER\n");
            daysInMonth=31;
            printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");      //Prints header row with day names
            break;
        }

        for (int space=1; space<startDay; space++)              //Spaces before first day
        {
            printf("\t");
        }
        for(int days=1; days<=daysInMonth; days++)              //Printing the days on 5 rows (or 4 Es. Feb 2021)
        {
            printf("%2d\t", days);          //Printing all days with two digits and tabulating
            if((startDay+days-1)%7==0)      //If it's the end of the week, print a new line
            {
                printf("\n");
            }
            if(days==daysInMonth)           //If all days have been printed, go to a new line leaving a blank line
            {

                printf("\n\n");
            }
        }


        startDay=((startDay+daysInMonth-1)%7)+1;                //Makes the next month start from the correct day,
                                                                //rather than having 12 months all starting with the same day
    }




    getchar();      //Pauses the program
    return 0;
}
