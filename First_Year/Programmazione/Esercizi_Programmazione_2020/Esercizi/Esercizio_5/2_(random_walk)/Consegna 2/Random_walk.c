/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/11/05

Scrivete un programma che generi una “passeggiata aleatoria” (random walk) in un array bidimensionale di dimensione 10×10.
L’array sarà riempito di caratteri (inizialmente da punti).
Il programma dovrà muoversi di elemento in elemento spostandosi ogni volta di un passo in direzione su, giù, destra o sinistra.
Gli elementi visitati andranno etichettati con le lettere dalla A alla Z, nell’ordine in cui vengono visitati.
E’ importante controllare ad ogni passo che la passeggiata non esca dall’array e che non ritorni su posizioni già visitate.
Quando si verifica una di queste condizioni, provate in altre direzioni.
Se tutte e quattro le direzioni sono bloccate, il programma deve uscire.

Ecco un esempio di funzionamento completo:

A . . . . . . . . . .

B C D . . . . . . .

. F E . . . . . . .

H G . . . . . . . .

I . . . . . . . . .

J . . . . . . . Z .

K . . R S T U V Y .

L M P Q . . . W X .

. N O . . . . . . .

. . . . . . . . . .
Ecco un esempio di uscita prematura dal programma:

A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .

Y è bloccata in tutte le direzioni quindi non c’è modo di inserire Z.

*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define aDim 10 //define the dimensions of the grid
#define DELAY_TIME 300000


//function to print the matrix
void printM(char matrix[aDim][aDim],int cursorX,int cursorY,char lettToPut)
{
 for (int y=0;y<aDim;y++)                                                   //cycle for row
        {
             printf("\n");                                                  //new line at the end of the row
            for (int x=0;x<aDim;x++)                                        //cycle for column
            {
                if(x==cursorX&&y==cursorY) matrix[x][y]=lettToPut;          //add the letter in cursor position
                if(x==cursorX&&y==cursorY) printf(">%c<\t",matrix[x][y]);   //print cursor position
                else printf("%c\t",matrix[x][y]);                           //print the rest
            }

        }
}

int main()
{
    srand(time(NULL));                  //initializing srand with time
    //initialize the matrix
    char matrix[aDim][aDim];
    //fill the matrix with '.'
    for (int x=0;x<aDim;x++)
    {
        for (int y=0;y<aDim;y++)
        {
            matrix[x][y]='.';
        }

    }


//initialize variables
    int cursorX=0;
    int cursorY=0;
    int lettToPut='A';
    char dir;

    printf("0) I want to drive the cursor\n1) I want a random sequence\n");             //ask if the user wants to drive the cursor or not
char ans;
while(1){
 ans=getch();
if (ans=='1'||ans=='0')break;                                                           //saves answer in "ans"
system("cls");
printf("0) I want to drive the cursor\n1) I want a random generating sequence\n");
printf("invalid input, try again!\n");
}



//enters a cycle to walk through the matrix
while(1)
{
    //prints matrix
    printM(matrix,cursorX,cursorY,lettToPut);
    //ask for directions
    if(ans=='0')printf("\nType a direction: up(\'w\'),down(\'s\'),left(\'a\') or right(\'d\')");

    while(1)  //cycle to check if answer is acceptable
    {
    if (ans=='0')scanf("%c",&dir);              //if ans ==0 ask for direction
    else if (ans=='1'){                         //else generates it "randomly"
        switch((rand()+time(NULL))%(3+1)){
    case 0:
        dir='a';
        break;
    case 1:
        dir='s';
        break;
     case 2:
        dir='d';
        break;
        case 3:
        dir='w';
        break;   }
    }
    system("cls");

    fflush(stdin);
         //prints matrix
    printM(matrix,cursorX,cursorY,lettToPut);
    //ask for directions
    if(ans=='0')printf("\nType a direction: up(\'w\'),down(\'s\'),left(\'a\') or right(\'d\')\n");
    if(ans=='1')printf("\nEnjoy the show!\n");
    //checks if the direction is possible, we preferred to make different if check in order to give a more precise error message

        if(dir=='a')                                                    //checks letter
            if(cursorX>0)                                               //checks if new position is inside the matrix
                if(matrix[cursorX-1][cursorY]=='.')break;               //checks if new position is already busy if all the above doesn't happen exits the cycle
                else {if(ans=='0')printf("Cell already busy, Try again!\n");      }   //else prints corresponding errors
            else {if(ans=='0')printf("Would be out of the matrix, Try again!\n");}

        else if(dir=='d')
            if(cursorX<aDim-1)
                if(matrix[cursorX+1][cursorY]=='.')break;
                else {if(ans=='0')printf("Cell already busy, Try again!\n");}
            else {if(ans=='0')printf("Would be out of the matrix, Try again!\n");}

        else if(dir=='w')
            if(cursorY>0)
                if(matrix[cursorX][cursorY-1]=='.')break;
                else {if(ans=='0')printf("Cell already busy, Try again!\n");}
            else {if(ans=='0')printf("Would be out of the matrix, Try again!\n");}

        else if(dir=='s')
            if(cursorY<aDim-1)
                if(matrix[cursorX][cursorY+1]=='.')break;
                else {if(ans=='0')printf("Cell already busy, Try again!\n");}
            else {if(ans=='0')printf("Would be out of the matrix, Try again!\n");}

        else printf("invalid input, Try again!\n");

    }

    //change cursor coordinates accordingly
    switch(dir)
    {
     case 'a': cursorX--;
     break;
     case 'd': cursorX++;
     break;
    case 'w': cursorY--;
     break;
    case 's': cursorY++;
     break;
    }

    //count the blocked sides on the new position
    int BlockedDir=0;
    if(cursorX==0||     matrix[cursorX-1][cursorY]!='.')BlockedDir++;   //checks both matrix dimension or if cell is busy
    if(cursorX==aDim-1||matrix[cursorX+1][cursorY]!='.')BlockedDir++;
    if(cursorY==0||     matrix[cursorX][cursorY-1]!='.')BlockedDir++;
    if(cursorY==aDim-1||matrix[cursorX][cursorY+1]!='.')BlockedDir++;




    if(ans=='1')usleep(DELAY_TIME); //allows the user to see whats happening
    lettToPut++;       //increase letter to put
    system("cls");     //clear console

    //if you finished letters walk ends
    if(lettToPut=='Z')
    {
        printM(matrix,cursorX,cursorY,lettToPut);
        printf("\nYou finished the alphabet! Press enter to exit\n");

        break;
    }

    //if you are blocked walk ends
    if(BlockedDir>3)
    {
        printM(matrix,cursorX,cursorY,lettToPut);
        printf("\nYou are stuck! Press enter to exit\n");
        break;
    }
}
    getchar();
    return 0;
}
