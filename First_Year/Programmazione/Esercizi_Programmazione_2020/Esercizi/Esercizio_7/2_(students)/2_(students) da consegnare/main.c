/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/11/24
Si scriva un programma C, adeguatamente commentato, che gestisca un certo numero di studenti iscritti ad un corso di laurea.
Il programma utilizza un vettore di strutture, ognuna delle quali memorizza le informazioni di uno studente
(numero matricola, nome e cognome, anno di immatricolazione, piano di studi, �).
Il programma utilizza inoltre un vettore di strutture, ognuna delle quali memorizza le informazioni di un insegnamento
(codice, descrizione, anno di somministrazione, crediti, �).
Il programma deve fornire la possibilit� di:
aggiungere un nuovo studente, stampando un messaggio di errore se lo studente � gi� presente (individuato dalla matricola) o se il vettore � pieno;
la funzione deve inoltre assegnargli un piano di studi scegliendo fra gli insegnamenti disponibili.
dato il numero di matricola, stampare le informazioni dello studente oppure un messaggio di errore se la matricola non � presente nel vettore
dato un numero di matricola, modificare le informazioni del piano di studi aggiungendo un voto oppure stampando un messaggio di errore se la matricola non � presente nel vettore.
Calcolare la media dei voti di tutti gli studenti che hanno completato il piano di studi pesata sul numero di crediti di ogni insegnamento.
Il piano di studi all�interno della struttura studente � un vettore di NUM_ESAMI elementi ognuno di tipo struttura contenete il codice dell'insegnamento e il voto corrispondente (0 se non sostenuto).
Modificare poi il programma in modo che il vettore di studenti venga allocato dinamicamente usando la funzione malloc().
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

//grade values
#define MAX_MARK 30  //maximum mark
#define MIN_MARK 1   //minimum mark
#define SUFF_MARK 18 //sufficient mark (included)

//student values
#define MAX_STUD 100    //dimension of the array at least 3
#define N_SUB 5         //number of subjects
#define MAX_LEN_NAME 50 //maximum lenght of name and surname string

//clear screen instruction on different systems
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other system
#define CLEAR "clear"
#endif

//students struct
typedef struct stud_s
{
    char surname[50];
    char firstname[50];
    int regNum;
    int yearOfSubsc;
    int mark[N_SUB]; //list of student's marks on the different subjects
} stud_t;

//subjects struc
typedef struct subject_s
{
    int code;
    char descr[MAX_LEN_NAME];
    char prof[MAX_LEN_NAME];
    int year;
    int credits;
} subject_t;

int main()
{
    char ans;

    //version selector: w/dynamic memory allocation or w/out it
    while (1)
    {
        printf("Select the version\n1) Without Malloc\n2) With Malloc");

        ans = getch();
        fflush(stdin);
        if (ans == '1' || ans == '2')
            break;
        printf("\n\nInvalid input, Try again!\a\n\n");
    }

    //Without Malloc
    if (ans == '1')
    {

        //please insert in order of year and update definition N_SUB
        subject_t subject[N_SUB] = {{1, "History", "Rossi", 1, 6}, {2, "Math", "Monti", 1, 12}, {3, "English", "Smith", 2, 10}, {4, "Law", "Bianchi", 2, 8}, {5, "Physics", "Verdi", 3, 6}};
        stud_t stud[MAX_STUD];  //initializing students and subjects arrays
        int studIndex = -1;     //index to count students
        while (1)
        {
            fflush(stdin);
            system(CLEAR);
            char answer; //variable to store the intentions

            while (1) //print menu and get answer
            {
                printf("1)Add Student\n2)Search student\n3)Add mark to student\n4)General average\n0)Exit\n");
                answer = getch();
                fflush(stdin);
                if (answer == '1' || answer == '2' || answer == '3' || answer == '4' || answer == '0')
                    break;

                printf("Invalid input, Try again!\a\n");
            }

            //functions


            //add student
            if (answer == '1')
            {
                fflush(stdin);
                if (studIndex < MAX_STUD - 1) //check if the array is full
                {
                    studIndex++; //fill next student in the array

                    system(CLEAR);
                    //name
                    printf("Type the first name of the student:\n");
                    fgets(stud[studIndex].firstname, MAX_LEN_NAME, stdin);
                    fflush(stdin);
                    stud[studIndex].firstname[strlen(stud[studIndex].firstname) - 1] = '\0'; //removing the new line added by the fgets
                    //surname
                    printf("Type the surname of the student:\n");
                    fgets(stud[studIndex].surname, MAX_LEN_NAME, stdin);
                    fflush(stdin);
                    stud[studIndex].surname[strlen(stud[studIndex].surname) - 1] = '\0'; //removing the new line added by the fgets
                    //Registration Number
                    while (1)
                    {
                        fflush(stdin);
                        printf("Type the registration number of the student:\n(if also letters are typed only the previous number is taken)\n");
                        int good = 1;
                        if (scanf("%d", &stud[studIndex].regNum) == 1 && stud[studIndex].regNum < 2147483647 && stud[studIndex].regNum > 0)
                            //search if reg. num. already present
                            for (int i = 0; i < studIndex; i++)
                            {
                                if (stud[studIndex].regNum == stud[i].regNum)
                                {
                                    good = 0;
                                    break;
                                }
                            }
                        if (good == 1)
                        {
                            fflush(stdin);
                            break;
                        }
                        else
                            printf("Incorrect input or registration number already present, try again\a\n\n");
                    }
                    fflush(stdin);
                    //Year of subscription
                    while (1)
                    {
                        fflush(stdin);
                        printf("Type the year of the student subscription:\n(if letters are typed only the previous number is taken)\n");
                        if (scanf("%d", &stud[studIndex].yearOfSubsc) == 1 && stud[studIndex].yearOfSubsc < 2030 && stud[studIndex].yearOfSubsc > 1900)
                            break;
                        else
                            printf("Incorrect input, try again\a\n");
                    }
                    fflush(stdin);

                    //study plan
                    for (int i = 0; i < N_SUB; i++)
                    {
                        stud[studIndex].mark[i] = -1; //initializing all subject to -1 (not in study plan)
                    }
                    while (1)
                    {
                        system(CLEAR);
                        //print menu
                        printf("Type the number of the subject to add:\n");
                        printf("added:\tName:\t\tYear of study:\tCredits:\n");
                        //print subj
                        for (int i = 0; i < N_SUB; i++)
                        {
                            printf("%d)[%c]\t%s\t\t%d%s\t\t%d\n", i + 1, stud[studIndex].mark[i] == -1 ? 'x' : 'v', subject[i].descr, subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th", subject[i].credits); //works only if the maximum year of study is<10
                        }
                        printf("0)CONTINUE\n");
                        //change subj from -1 to 0 (and vice versa) to add
                        char answer = getch();
                        fflush(stdin);

                        if (answer <= N_SUB + '0' && answer >= '0')
                            if (answer == '0')
                                break;
                        {
                            if (stud[studIndex].mark[answer - ('0' + 1)] == -1)
                            {
                                stud[studIndex].mark[answer - ('0' + 1)] = 0;
                            }
                            else
                            {
                                stud[studIndex].mark[answer - ('0' + 1)] = -1;
                            }
                        }
                    }

                    //add mark
                    while (1)
                    {
                        system(CLEAR);

                        int activeSubj = 0; //count added subj

                        //print menu
                        printf("Type the number of the subject to add or modify a mark:\n");
                        printf("\tName:\t\tYear of study:\tPassed:\tMark:(out of %d)\n", MAX_MARK);
                        for (int i = 0; i < N_SUB; i++)
                        {
                            if (stud[studIndex].mark[i] != -1) //if subj added display it
                            {
                                char buffer[3]; //space for mark string (used in the itoa() below)

                                printf("%d)\t%s", activeSubj + 1, subject[i].descr);
                                printf("\t\t%d%s", subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th");
                                printf("\t\t[%c]", stud[studIndex].mark[i] == 0 ? ' ' : stud[studIndex].mark[i] < SUFF_MARK ? 'x' : 'v');
                                printf("\t%s\n", stud[studIndex].mark[i] == 0 ? "exam not taken yet" : itoa(stud[studIndex].mark[i], buffer, 10)); //works only if the maximum year of study is<10
                                activeSubj++;
                            }
                        }
                        printf("0)Back to Main Menu\n");

                        //get answer
                        char answer = getch();
                        fflush(stdin);

                        if (answer == '0')
                            break;
                        if (answer <= activeSubj + '0' && answer >= '0')
                        {
                            activeSubj = 0;
                            for (int i = 0; i < N_SUB; i++)//convert selection in subj identifier
                            {
                                if (stud[studIndex].mark[i] != -1) //if subj added increase counter
                                {
                                    activeSubj++;
                                }

                                if (activeSubj == answer - '0') //if matches selection

                                {
                                    //insert mark
                                    system(CLEAR);
                                    while (1)
                                    {
                                        fflush(stdin);

                                        printf("Type the mark of %s: (out of %d, at least %d to pass)\n", subject[i].descr, MAX_MARK, SUFF_MARK);
                                        if (scanf("%d", &stud[studIndex].mark[i]) == 1 && stud[studIndex].mark[i] < MAX_MARK + 1 && stud[studIndex].mark[i] > MIN_MARK)
                                            break;
                                        else
                                            printf("Incorrect input, try again\a\n");
                                    }
                                    break;
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
                else
                {
                    printf("There's no more space! press any key to continue\a\n");
                    getch();
                    fflush(stdin);
                }
            }

            //search student
            if (answer == '2')
            {
                //get selection
                system(CLEAR);

                int regToSearch;
                while (1)
                {
                    fflush(stdin);
                    printf("Type the registration number of the student to search\n");
                    printf("(if letters are typed only the previous number is taken)\n");
                    if (scanf("%d", &regToSearch) == 1 && regToSearch< 2147483647 && regToSearch > 0)
                        break;
                    else
                        printf("Incorrect input, try again\a\n");
                }
                fflush(stdin);


                fflush(stdin);
                system(CLEAR);
                int found = 0;
                for (int Istud = 0; Istud <= studIndex; Istud++)
                {
                    //search
                    if (regToSearch == stud[Istud].regNum)
                    {
                        //when found print info and initialize average variables
                        float averagePassedExam = 0;
                        int nPassedExam = 0;

                        float rawAverage = 0;
                        int nRawAverage = 0;

                        float WaveragePassedExam = 0;
                        int creditsPassedExam = 0;

                        float WrawAverage = 0;
                        int allCredit = 0;

                        printf("Name:\t\t%s\n", stud[Istud].firstname);
                        printf("Surname:\t%s\n", stud[Istud].surname);
                        printf("Reg number:\t%d\n", stud[Istud].regNum);
                        printf("Yr. of reg:\t%d\n", stud[Istud].yearOfSubsc);

                        int activeSubj = 0;

                        //print active subj
                        printf("Subjects in the study plan\n");
                        printf("\tName:\t\tYear of study:\tCredits:\tPassed:\tMark:(out of %d)\n", MAX_MARK);
                        for (int i = 0; i < N_SUB; i++)
                        {
                            if (stud[Istud].mark[i] != -1) //if subj added
                            {
                                char buffer[3]; //space for mark string (used in the itoa() below)

                                printf("%d)\t%s", activeSubj + 1, subject[i].descr);
                                printf("\t\t%d%s", subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th");
                                printf("\t\t%d", subject[i].credits);
                                printf("\t\t[%c]", stud[Istud].mark[i] == 0 ? ' ' : stud[Istud].mark[i] < SUFF_MARK ? 'x' : 'v');
                                printf("\t%s\n", stud[Istud].mark[i] == 0 ? "exam not taken yet" : itoa(stud[Istud].mark[i], buffer, 10)); //works only if the maximum year of study is<10

                                //calculating average
                                if (stud[Istud].mark[i] > 0)
                                {
                                    if (stud[Istud].mark[i] > SUFF_MARK - 1)
                                    {
                                        averagePassedExam += stud[Istud].mark[i];
                                        nPassedExam++;

                                        WaveragePassedExam += ((stud[Istud].mark[i]) * (subject[i].credits));
                                        creditsPassedExam += subject[i].credits;
                                    }
                                    rawAverage += stud[Istud].mark[i];
                                    nRawAverage++;

                                    WrawAverage += ((stud[Istud].mark[i]) * (subject[i].credits));
                                    allCredit += subject[i].credits;
                                }
                                activeSubj++;
                            }
                        }
                        if (averagePassedExam != 0)
                            averagePassedExam = (float)averagePassedExam / nPassedExam;

                        if (rawAverage != 0)
                            rawAverage = (float)rawAverage / nRawAverage;

                        if (WaveragePassedExam != 0)
                            WaveragePassedExam = (float)WaveragePassedExam / creditsPassedExam;

                        if (WrawAverage != 0)
                            WrawAverage = (float)WrawAverage / allCredit;
                        //print average
                        printf("\nAv. of passed exams:\t%f\n", averagePassedExam);
                        printf("Av. of all exams:\t%f\n", rawAverage);
                        printf("\nWeighted Av. of psd. exams:\t%f\n", WaveragePassedExam);
                        printf("Weighted Av. of all exams:\t%f\n\n", WrawAverage);

                        found++;
                        break;
                    }
                }
                if (found == 0)
                    printf("No matching student, ");
                printf("Press any key to continue...\n");
                getch();
                fflush(stdin);
            }

            //add a grade to a student
            if (answer == '3')
            {
                //get selection
                system(CLEAR);
                printf("Type the registration number of the student to search\n");
                int regToSearch;
                scanf("%d", &regToSearch);
                fflush(stdin);
                system(CLEAR);
                int found = 0;
                for (int Istud = 0; Istud <= studIndex; Istud++)
                {
                    //search student
                    if (regToSearch == stud[Istud].regNum)
                    {
                        //print info
                        found++;
                        printf("Name:\t\t%s\t", stud[Istud].firstname);
                        printf("Surname:\t%s\t", stud[Istud].surname);
                        printf("Reg number:\t%d\n", stud[Istud].regNum);
                        while (1)
                        {
                            //print subj menu
                            system(CLEAR);

                            printf("Study plan: Type the number of the subject to add or remove  (only if the exam is not taken yet): \n");
                            printf("added:\tName:\t\tYear of study:\tCredits:\tMark:\n");
                            for (int i = 0; i < N_SUB; i++)
                            {
                                char buffer[3]; //space for mark string (used in the itoa() below)
                                //magari la divido
                                printf("%d)[%c]\t%s\t\t%d%s\t\t%d\t\t%s\n", i + 1, stud[Istud].mark[i] == -1 ? 'x' : 'v', subject[i].descr, subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th", subject[i].credits, stud[Istud].mark[i] == -1 ? " " : stud[Istud].mark[i] == 0 ? "exam not taken yet" : itoa(stud[Istud].mark[i], buffer, 10)); //works only if the maximum year of study is<10
                            }
                            printf("0)CONTINUE\n");
                            //get answer and activate or deactivate it (if possible)
                            char answer = getch();
                            fflush(stdin);

                            if (answer <= N_SUB + '0' && answer >= '0')
                                if (answer == '0')
                                    break;
                            {
                                if (stud[Istud].mark[answer - ('0' + 1)] == -1)
                                {
                                    stud[Istud].mark[answer - ('0' + 1)] = 0;
                                }
                                else
                                {
                                    if (stud[Istud].mark[answer - ('0' + 1)] == 0)
                                        stud[Istud].mark[answer - ('0' + 1)] = -1;
                                    else
                                    {
                                        printf("Exam already taken, cannot delete! Press any key to continue...\a\n");
                                        getch();
                                        fflush(stdin);
                                    }
                                }
                            }
                        }

                        //add mark
                        while (1)
                        {
                            system(CLEAR);

                            int activeSubj = 0;

                            //print menu
                            printf("\tName:\t\tYear of study:\tPassed:\tMark:(out of %d)\n", MAX_MARK);
                            for (int i = 0; i < N_SUB; i++)
                            {
                                if (stud[Istud].mark[i] != -1) //if subj added
                                {
                                    char buffer[3]; //space for mark string (used in the itoa() below)

                                    printf("%d)\t%s", activeSubj + 1, subject[i].descr);
                                    printf("\t\t%d%s", subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th");
                                    printf("\t\t[%c]", stud[Istud].mark[i] == 0 ? ' ' : stud[Istud].mark[i] < SUFF_MARK ? 'x' : 'v');
                                    printf("\t%s\n", stud[Istud].mark[i] == 0 ? "exam not taken yet" : itoa(stud[Istud].mark[i], buffer, 10)); //works only if the maximum year of study is<10
                                    activeSubj++;
                                }
                            }
                            printf("0)Back to Main Menu\n");

                            //get answer
                            char answer = getch();
                            fflush(stdin);

                            if (answer == '0')
                                break;
                            if (answer <= activeSubj + '0' && answer >= '0')
                            {
                                activeSubj = 0;
                                for (int i = 0; i < N_SUB; i++)
                                {
                                    if (stud[Istud].mark[i] != -1) //if subj added increase counter to filter active subj
                                    {
                                        activeSubj++;
                                    }

                                    if (activeSubj == answer - '0') //if matches selection

                                    {
                                        //get mark
                                        system(CLEAR);
                                        while (1)
                                        {
                                            fflush(stdin);

                                            printf("Type the mark of %s: (out of %d, at least %d to pass)\n", subject[i].descr, MAX_MARK, SUFF_MARK);
                                            if (scanf("%d", &stud[Istud].mark[i]) == 1 && stud[Istud].mark[i] < MAX_MARK + 1 && stud[Istud].mark[i] > MIN_MARK)
                                                break;
                                            else
                                                printf("Incorrect input, try again\a\n");
                                        }
                                        break;
                                        fflush(stdin);
                                    }
                                }
                            }
                        }
                    }
                }
                if (found == 0)
                {
                    printf("No matching student, ");
                    printf("Press any key to continue...\n");
                    getch();
                    fflush(stdin);
                }
            }

            //average of all grades
            if (answer == '4')
            {
                system(CLEAR);
                float generalAv = 0;
                int generalCred = 0;

                for (int Istud = 0; Istud <= studIndex; Istud++) //for each student
                {

                    int completeStudyPlan = 1;
                    for (int i = 0; i < N_SUB; i++) //check if the study plan is complete with all passed exams
                    {
                        if ((stud[Istud].mark[i] < SUFF_MARK) && (stud[Istud].mark[i] != -1))
                        {
                            completeStudyPlan = 0;
                            break;
                        }
                    }

                    if (completeStudyPlan == 1) //if complete calculate average
                    {
                        float WaveragePassedExam = 0;
                        int creditsPassedExam = 0;

                        printf("Name:%s\t", stud[Istud].firstname);
                        printf("Surname:%s\t", stud[Istud].surname);
                        printf("Reg number:%d\t", stud[Istud].regNum);

                        for (int i = 0; i < N_SUB; i++)
                        {
                            if (stud[Istud].mark[i] != -1) //if subj added
                            {

                                //calculating average
                                if (stud[Istud].mark[i] > 0)
                                {
                                    if (stud[Istud].mark[i] > SUFF_MARK - 1)
                                    {
                                        WaveragePassedExam += ((stud[Istud].mark[i]) * (subject[i].credits));
                                        creditsPassedExam += subject[i].credits;

                                        generalAv += ((stud[Istud].mark[i]) * (subject[i].credits));
                                        generalCred += subject[i].credits;
                                    }
                                }
                            }
                        }
                        WaveragePassedExam = (float)WaveragePassedExam / creditsPassedExam;

                        printf("Weighted Av. of psd. exams:%f\n", WaveragePassedExam);
                    }
                }
                if (generalAv != 0)
                {
                    //calculate and print general average
                    generalAv = (float)generalAv / generalCred;
                    printf("\nGeneral weighted average of students with complete study plan:\t%f\n(all the exams in the study plan passed with a suff. mark)\n", generalAv);
                }
                else printf("None of the students has finished the study plan!\n");
                printf("Press any key to continue...\n");
                getch();
                fflush(stdin);
            }

            if (answer == '0')
                break;
        }

        return 0;
    }

    //With Malloc   ONLY DIFFERENCES ARE COMMENTED!
    if (ans == '2')
    {
        subject_t subject[N_SUB] = {{1, "History", "Rossi", 1, 6}, {2, "Math", "Monti", 1, 12}, {3, "English", "Smith", 2, 10}, {4, "Law", "Bianchi", 2, 8}, {5, "Phisics", "Verdi", 3, 6}};
        int reallocTimes=1; //in order to multiply the reallocated space multiple times
        stud_t *stud = malloc((MAX_STUD) * sizeof(stud));   //allocating space
        if(stud==NULL)return -1;
        int studIndex = 1;

        while (1)
        {
            fflush(stdin);
            system(CLEAR);
            char answer;

            while (1)
            {
                printf("1)Add Student\n2)Search student\n3)Add mark to student\n4)General avarage\n0)Exit\n");
                answer = getch();
                fflush(stdin);
                if (answer == '1' || answer == '2' || answer == '3' || answer == '4' || answer == '0')
                    break;

                printf("Invalid input, Try again!\a\n");
            }

            if (answer == '1')
            {
                fflush(stdin);
                if (studIndex < MAX_STUD*reallocTimes - 1)
                {
                    studIndex++;

                    system(CLEAR);
                    printf("Type the first name of the student:\n");
                    fgets(stud[studIndex].firstname, MAX_LEN_NAME, stdin);
                    fflush(stdin);
                    stud[studIndex].firstname[strlen(stud[studIndex].firstname) - 1] = '\0';

                    printf("Type the surname of the student:\n");
                    fgets(stud[studIndex].surname, MAX_LEN_NAME, stdin);
                    fflush(stdin);
                    stud[studIndex].surname[strlen(stud[studIndex].surname) - 1] = '\0';
                    while (1)
                    {
                        fflush(stdin);
                        printf("Type the registration number of the student:\n(if letters are typed only the previous number is taken)\n");
                        int good = 1;
                        if (scanf("%d", &stud[studIndex].regNum) == 1 && stud[studIndex].regNum < 2147483647 && stud[studIndex].regNum > 0)
                            for (int i = 1; i < studIndex; i++)
                            {
                                if (stud[studIndex].regNum == stud[i].regNum)
                                {
                                    good = 0;
                                    break;
                                }
                            }
                        if (good == 1)
                        {
                            fflush(stdin);
                            break;
                        }
                        else
                            printf("Incorrect input or registration number already present, try again\a\n\n");
                    }
                    fflush(stdin);

                    while (1)
                    {
                        fflush(stdin);
                        printf("Type the year of the student subscription:\n(if letters are typed only the previous number is taken)\n");
                        if (scanf("%d", &stud[studIndex].yearOfSubsc) == 1 && stud[studIndex].yearOfSubsc < 2030 && stud[studIndex].yearOfSubsc > 1900)
                            break;
                        else
                            printf("Incorrect input, try again\a\n");
                    }
                    fflush(stdin);


                    for (int i = 0; i < N_SUB; i++)
                    {
                        stud[studIndex].mark[i] = -1;
                    }
                    while (1)
                    {
                        system(CLEAR);

                        printf("Type the number of the subject to add:\n");
                        printf("added:\tName:\t\tYear of study:\tCredits:\n");
                        for (int i = 0; i < N_SUB; i++)
                        {
                            printf("%d)[%c]\t%s\t\t%d%s\t\t%d\n", i + 1, stud[studIndex].mark[i] == -1 ? 'x' : 'v', subject[i].descr, subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th", subject[i].credits);
                        }
                        printf("0)CONTINUE\n");

                        char answer = getch();
                        fflush(stdin);

                        if (answer <= N_SUB + '0' && answer >= '0')
                            if (answer == '0')
                                break;
                        {
                            if (stud[studIndex].mark[answer - ('0' + 1)] == -1)
                            {
                                stud[studIndex].mark[answer - ('0' + 1)] = 0;
                            }
                            else
                            {
                                stud[studIndex].mark[answer - ('0' + 1)] = -1;
                            }
                        }
                    }

                    while (1)
                    {
                        system(CLEAR);

                        int activeSubj = 0;


                        printf("Type the number of the subject to add or modify a mark:\n");
                        printf("\tName:\t\tYear of study:\tPassed:\tMark:(out of %d)\n", MAX_MARK);
                        for (int i = 0; i < N_SUB; i++)
                        {
                            if (stud[studIndex].mark[i] != -1)
                            {
                                char buffer[3];

                                printf("%d)\t%s", activeSubj + 1, subject[i].descr);
                                printf("\t\t%d%s", subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th");
                                printf("\t\t[%c]", stud[studIndex].mark[i] == 0 ? ' ' : stud[studIndex].mark[i] < SUFF_MARK ? 'x' : 'v');
                                printf("\t%s\n", stud[studIndex].mark[i] == 0 ? "exam not taken yet" : itoa(stud[studIndex].mark[i], buffer, 10)); //works only if the maximum year of study is<10
                                activeSubj++;
                            }
                        }
                        printf("0)Back to Main Menu\n");


                        char answer = getch();
                        fflush(stdin);

                        if (answer == '0')
                            break;
                        if (answer <= activeSubj + '0' && answer >= '0')
                        {
                            activeSubj = 0;
                            for (int i = 0; i < N_SUB; i++)
                            {
                                if (stud[studIndex].mark[i] != -1)
                                {
                                    activeSubj++;
                                }

                                if (activeSubj == answer - '0')

                                {

                                    system(CLEAR);
                                    while (1)
                                    {
                                        fflush(stdin);

                                        printf("Type the mark of %s: (out of %d, at least %d to pass)\n", subject[i].descr, MAX_MARK, SUFF_MARK);
                                        if (scanf("%d", &stud[studIndex].mark[i]) == 1 && stud[studIndex].mark[i] < MAX_MARK + 1 && stud[studIndex].mark[i] > MIN_MARK)
                                            break;
                                        else
                                            printf("Incorrect input, try again\a\n");
                                    }
                                    break;
                                    fflush(stdin);
                                }
                            }
                        }
                    }
                }
                else
                {
                    //if the array is full
                    stud = realloc(stud,(MAX_STUD*(++reallocTimes)) * sizeof(stud));//realloc with n times the initial dimension
                    if(stud==NULL)return -1;                                        //check
                    printf("There was no more space! Array expanded, try again, press any key to continue\a\n");//print message
                    getch();
                    fflush(stdin);
                }
            }

            if (answer == '2')
            {
                system(CLEAR);
                int regToSearch;
                while (1)
                {
                    fflush(stdin);
                    printf("Type the registration number of the student to search\n");
                    printf("(if letters are typed only the previous number is taken)\n");
                    if (scanf("%d", &regToSearch) == 1 && regToSearch< 2147483647 && regToSearch > 0)
                        break;
                    else
                        printf("Incorrect input, try again\a\n");
                }
                fflush(stdin);
                fflush(stdin);
                system(CLEAR);
                int found = 0;
                for (int Istud = 2; Istud <= studIndex; Istud++)
                {
                    if (regToSearch == stud[Istud].regNum)
                    {
                        float averagePassedExam = 0;
                        int nPassedExam = 0;

                        float rawAverage = 0;
                        int nRawAverage = 0;

                        float WaveragePassedExam = 0;
                        int creditsPassedExam = 0;

                        float WrawAverage = 0;
                        int allCredit = 0;

                        printf("Name:\t\t%s\n", stud[Istud].firstname);
                        printf("Surname:\t%s\n", stud[Istud].surname);
                        printf("Reg number:\t%d\n", stud[Istud].regNum);
                        printf("Yr. of reg:\t%d\n", stud[Istud].yearOfSubsc);

                        int activeSubj = 0;


                        printf("Subjects in the study plan\n");
                        printf("\tName:\t\tYear of study:\tCredits:\tPassed:\tMark:(out of %d)\n", MAX_MARK);
                        for (int i = 0; i < N_SUB; i++)
                        {
                            if (stud[Istud].mark[i] != -1)
                            {
                                char buffer[3];

                                printf("%d)\t%s", activeSubj + 1, subject[i].descr);
                                printf("\t\t%d%s", subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th");
                                printf("\t\t%d", subject[i].credits);
                                printf("\t\t[%c]", stud[Istud].mark[i] == 0 ? ' ' : stud[Istud].mark[i] < SUFF_MARK ? 'x' : 'v');
                                printf("\t%s\n", stud[Istud].mark[i] == 0 ? "exam not taken yet" : itoa(stud[Istud].mark[i], buffer, 10));

                                if (stud[Istud].mark[i] > 0)
                                {
                                    if (stud[Istud].mark[i] > SUFF_MARK - 1)
                                    {
                                        averagePassedExam += stud[Istud].mark[i];
                                        nPassedExam++;

                                        WaveragePassedExam += ((stud[Istud].mark[i]) * (subject[i].credits));
                                        creditsPassedExam += subject[i].credits;
                                    }
                                    rawAverage += stud[Istud].mark[i];
                                    nRawAverage++;

                                    WrawAverage += ((stud[Istud].mark[i]) * (subject[i].credits));
                                    allCredit += subject[i].credits;
                                }
                                activeSubj++;
                            }
                        }
                        if (averagePassedExam != 0)
                            averagePassedExam = (float)averagePassedExam / nPassedExam;

                        if (rawAverage != 0)
                            rawAverage = (float)rawAverage / nRawAverage;

                        if (WaveragePassedExam != 0)
                            WaveragePassedExam = (float)WaveragePassedExam / creditsPassedExam;

                        if (WrawAverage != 0)
                            WrawAverage = (float)WrawAverage / allCredit;

                        printf("\nAv. of passed exams:\t%f\n", averagePassedExam);
                        printf("Av. of all exams:\t%f\n", rawAverage);
                        printf("\nWeighted Av. of psd. exams:\t%f\n", WaveragePassedExam);
                        printf("Weighted Av. of all exams:\t%f\n\n", WrawAverage);

                        found++;
                        break;
                    }
                }
                if (found == 0)
                    printf("No matching student, ");
                printf("Press any key to continue...\n");
                getch();
                fflush(stdin);
            }
            if (answer == '3')
            {
                system(CLEAR);
                printf("Type the registration number of the student to search\n");
                int regToSearch;
                scanf("%d", &regToSearch);
                fflush(stdin);
                system(CLEAR);
                int found = 0;
                for (int Istud = 2; Istud <= studIndex; Istud++)
                {
                    if (regToSearch == stud[Istud].regNum)
                    {
                        found++;
                        printf("Name:\t\t%s\t", stud[Istud].firstname);
                        printf("Surname:\t%s\t", stud[Istud].surname);
                        printf("Reg number:\t%d\n", stud[Istud].regNum);
                        while (1)
                        {
                            system(CLEAR);

                            printf("Study plan: Type the number of the subject to add or remove  (only if the exam is not taken yet): \n");
                            printf("added:\tName:\t\tYear of study:\tCredits:\tMark:\n");
                            for (int i = 0; i < N_SUB; i++)
                            {
                                char buffer[3];
                                printf("%d)[%c]\t%s\t\t%d%s\t\t%d\t\t%s\n", i + 1, stud[Istud].mark[i] == -1 ? 'x' : 'v', subject[i].descr, subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th", subject[i].credits, stud[Istud].mark[i] == -1 ? " " : stud[Istud].mark[i] == 0 ? "exam not taken yet" : itoa(stud[Istud].mark[i], buffer, 10)); //works only if the maximum year of study is<10
                            }
                            printf("0)CONTINUE\n");

                            char answer = getch();
                            fflush(stdin);

                            if (answer <= N_SUB + '0' && answer >= '0')
                                if (answer == '0')
                                    break;
                            {
                                if (stud[Istud].mark[answer - ('0' + 1)] == -1)
                                {
                                    stud[Istud].mark[answer - ('0' + 1)] = 0;
                                }
                                else
                                {
                                    if (stud[Istud].mark[answer - ('0' + 1)] == 0)
                                        stud[Istud].mark[answer - ('0' + 1)] = -1;
                                    else
                                    {
                                        printf("Exam already taken, cannot delete! Press any key to continue...\a\n");
                                        getch();
                                        fflush(stdin);
                                    }
                                }
                            }
                        }

                        //add mark
                        while (1)
                        {
                            system(CLEAR);

                            int activeSubj = 0;

                            //print menu
                            printf("\tName:\t\tYear of study:\tPassed:\tMark:(out of %d)\n", MAX_MARK);
                            for (int i = 0; i < N_SUB; i++)
                            {
                                if (stud[Istud].mark[i] != -1)
                                {
                                    char buffer[3];

                                    printf("%d)\t%s", activeSubj + 1, subject[i].descr);
                                    printf("\t\t%d%s", subject[i].year, subject[i].year == 1 ? "st" : subject[i].year == 2 ? "nd" : subject[i].year == 3 ? "rd" : "th");
                                    printf("\t\t[%c]", stud[Istud].mark[i] == 0 ? ' ' : stud[Istud].mark[i] < SUFF_MARK ? 'x' : 'v');
                                    printf("\t%s\n", stud[Istud].mark[i] == 0 ? "exam not taken yet" : itoa(stud[Istud].mark[i], buffer, 10));
                                    activeSubj++;
                                }
                            }
                            printf("0)Back to Main Menu\n");


                            char answer = getch();
                            fflush(stdin);

                            if (answer == '0')
                                break;
                            if (answer <= activeSubj + '0' && answer >= '0')
                            {
                                activeSubj = 0;
                                for (int i = 0; i < N_SUB; i++)
                                {
                                    if (stud[Istud].mark[i] != -1)
                                    {
                                        activeSubj++;
                                    }

                                    if (activeSubj == answer - '0')

                                    {

                                        system(CLEAR);
                                        while (1)
                                        {
                                            fflush(stdin);

                                            printf("Type the mark of %s: (out of %d, at least %d to pass)\n", subject[i].descr, MAX_MARK, SUFF_MARK);
                                            if (scanf("%d", &stud[Istud].mark[i]) == 1 && stud[Istud].mark[i] < MAX_MARK + 1 && stud[Istud].mark[i] > MIN_MARK)
                                                break;
                                            else
                                                printf("Incorrect input, try again\a\n");
                                        }
                                        break;
                                        fflush(stdin);
                                    }
                                }
                            }
                        }
                    }
                }
                if (found == 0)
                {
                    printf("No matching student, ");
                    printf("Press any key to continue...\n");
                    getch();
                    fflush(stdin);
                }
            }
            if (answer == '4')
            {
                system(CLEAR);
                float generalAv = 0;
                int generalCred = 0;

                for (int Istud = 2; Istud <= studIndex; Istud++)
                {

                    int completeStudyPlan = 1;
                    for (int i = 0; i < N_SUB; i++)
                    {
                        if ((stud[Istud].mark[i] < SUFF_MARK) && (stud[Istud].mark[i] != -1))
                        {
                            completeStudyPlan = 0;
                            break;
                        }
                    }

                    if (completeStudyPlan == 1)
                    {
                        float WaveragePassedExam = 0;
                        int creditsPassedExam = 0;

                        printf("Name:%s\t", stud[Istud].firstname);
                        printf("Surname:%s\t", stud[Istud].surname);
                        printf("Reg number:%d\t", stud[Istud].regNum);

                        for (int i = 0; i < N_SUB; i++)
                        {
                            if (stud[Istud].mark[i] != -1)
                            {

                                if (stud[Istud].mark[i] > 0)
                                {
                                    if (stud[Istud].mark[i] > SUFF_MARK - 1)
                                    {
                                        WaveragePassedExam += ((stud[Istud].mark[i]) * (subject[i].credits));
                                        creditsPassedExam += subject[i].credits;

                                        generalAv += ((stud[Istud].mark[i]) * (subject[i].credits));
                                        generalCred += subject[i].credits;
                                    }
                                }
                            }
                        }
                        WaveragePassedExam = (float)WaveragePassedExam / creditsPassedExam;

                        printf("Weighted Av. of psd. exams:%f\n", WaveragePassedExam);
                    }
                }
                if (generalAv != 0)
                {
                    generalAv = (float)generalAv / generalCred;

                    printf("\nGeneral weighted average of students with complete study plan:\t%f\n(all the exams in the study plan passed with a suff. mark)\n", generalAv);
                }
                else printf("None of the students has finished the study plan!\n");
                printf("Press any key to continue...\n");
                getch();
                fflush(stdin);
            }

            if (answer == '0')
            {
                break;
                free(stud);//freeing the malloc
            }
        }

        return 0;
    }
}
