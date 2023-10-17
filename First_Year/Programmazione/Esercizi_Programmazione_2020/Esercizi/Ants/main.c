//LEONARDO TASSINARI ANTS 26/11/2020
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d",&num);   //define number of inputs

    int array[num];
    int indice=0;   //create array and a used maximum index

    for(int i=0; i<num; i++)    //get input
    {
        int Anum;
        scanf("%d",&Anum);
        if(Anum>0)              //add if >0
        {
            array[indice]=Anum;
            indice++;           //increase counter in the array
        }
    }


    for(int esame=1; esame<=indice; esame++)    //for each number form 1 to the maximum index of the array
    {
        int good=0;     //flag variable
        for (int i=0; i<indice; i++)            //check if the number is in the array
        {
            if(array[i]==esame)                 //if yes break
            {
                good=1;
                break;
            }
        }
        if (good==0)return esame;               //if not return answer

    }
}
