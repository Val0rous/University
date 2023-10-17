#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
////#include <errno.h>
#define ARRAY_SIZE 1000

//TODO:
//data gathering
//command line arguments (main)
//structure
//volume calc
//quicksort by volume
//fix sorting problems (biggest box I guess)
//create tempcheck variable to keep fscanf return value and simplify code
//* size comparison
//* printing formatted output
//* creating output file (to do only when everything else is complete)

struct BoxData
{
    //sizes of box sides
    float width;
    float height;
    float depth;

    float volume;
    ////float min_cube; //cube of the shortest side of the box
    ////float base_area;     //base area = width * depth

    ////float stack_index;    //cube coefficient = 0*shortest side + volume * minimum cube

    int number; //original box number, before sorting
};

//* QUICKSORT ALGORITHM --- START

//useful function to swap two elements of struct BoxData type (just for volume sorting)
void swap(struct BoxData *a, struct BoxData *b)
{
    struct BoxData temp = *a;
    *a = *b;
    *b = temp;
}

//partition function
int partition(struct BoxData arr[], int low, int high)
{
    //always select pivot as rightmost element
    struct BoxData pivot = arr[high];

    //index for highest element (before the pivot)
    int i = low - 1;

    //run through each array element
    for (int j = low; j <= high - 1; j++)
    {
        //compare element with pivot
        if (arr[j].volume >= pivot.volume)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    //return partitioning index
    return (i + 1);
}

//sorting function
void quicksort(struct BoxData arr[], int low, int high)
{
    //"domain" check
    if (low < high)
    {
        //pi = Partitioning Index
        int pi = partition(arr, low, high);
        //recursive call on left
        quicksort(arr, low, pi - 1);
        //recursive call on right
        quicksort(arr, pi + 1, high);
    }
}

//* QUICKSORT ALGORITHM --- END

/*
float minimum(float a, float b, float c)
{
    if (a < b && a < c)
    {
        return a;
    }

    else if (b < a && b < c)
    {
        return b;
    }

    else
    {
        return c;
    }
}
*/

//// bug with pointers in argv
//// DEBUG IN VISUAL STUDIO
int main(int argc, char *argv[])    //* passing arguments from command line is working properly
{
    //opening file from command line
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    //fptr = fopen("C:\\Users\\fv260\\Desktop\\Informatica\\1 - II\\ASD - Algoritmi e Strutture Dati\\Elaborato\\1.in", "r");
    assert(fptr);
    printf("\nThe file %s has opened successfully\n\n", argv[1]);   //* now file opening is working properly
    //printf("The file C:\\Users\\fv260\\Desktop\\Informatica\\1 – II\\ASD - Algoritmi e Strutture Dati\\Elaborato\\1.in has opened successfully\n\n");

    int total;  //total number of boxes

    //gets first number of text input (total number of boxes)
    int temp_check;
    temp_check = fscanf(fptr, "%d", &total);     //* this is working properly

    //error check
    if (temp_check != 1)     
    {
        fprintf(stderr, "\n\nError in scanning first number of input file\n\n");
        exit(1);
    }
    ////printf("\nTotal number of boxes is: %d\n\n", total);
    
    //* initializing array of boxes is working properly
    struct BoxData BoxList[ARRAY_SIZE];
    for (int counter = 0; counter < total; counter++)
    {
        temp_check = fscanf(fptr, "%f %f %f", &BoxList[counter].width, &BoxList[counter].height, &BoxList[counter].depth);

        //error check
        if (temp_check != 3)
        {
            fprintf(stderr, "Error in scanning line %d of input file", (counter + 1));
            exit(1);
        }
        //fscanf(fptr, "%f", &BoxList[counter].height);
        //fscanf(fptr, "%f", &BoxList[counter].depth);

        BoxList[counter].number = counter;

        //calculating volume
        BoxList[counter].volume = ((BoxList[counter].width) * (BoxList[counter].height) * (BoxList[counter].depth));

        ////calculating minimum cube
        ////BoxList[counter].min_cube = powf(minimum(BoxList[counter].width, BoxList[counter].height, BoxList[counter].depth), 3);

        ////calculating base area
        ////BoxList[counter].base_area = BoxList[counter].width * BoxList[counter].depth;

        //////calculating cube coefficient
        ////BoxList[counter].stack_index = BoxList[counter].volume * BoxList[counter].min_cube + 0*minimum(BoxList[counter].width, BoxList[counter].height, BoxList[counter].depth);
    }

    //sorting boxes by descending volume
    quicksort(BoxList, 0, total - 1);   //* quicksort working properly

    //? DEBUG PURPOSES ONLY: prints the list it has just scanned from file input
    //? DEBUG PURPOSES (NOT) ONLY: prints newly sorted list
    //* data structure working properly
    for (int i = 0; i < total; i++)
    {
        printf("No %3d    W % 5.1f   H %5.1f   D %5.1f    V %8.1f\n", BoxList[i].number, BoxList[i].width, BoxList[i].height, BoxList[i].depth, BoxList[i].volume);
    }
    // SUM and V/SUM didn't work (SUM = width + height + depth)
    // MINCB is the cube created with the shortest side of the box:
    // it's a measurement of how squared (shall I say cubed?) the box is: the bigger it is, the more regular the box

    //create another array which's gonna hold all the boxes (elements) which are gonna
    //be the max number of "Chinese boxes"

    //? this array holds the index (in BoxList) of each selected box
    int selected_boxes[ARRAY_SIZE];
    int current_box_selection[ARRAY_SIZE];  //holds currently selected boxes: if optimum solution, that's gonna be copied into selected_boxes[]

    //then compare the elements and fill that array
    int i = 0;
    int j = 0;                 //loop counter (always starts from biggest box, which is gonna be always included in box list)
    int counter;               //counter to place elements in array
    int best_solution_num;     //number of selected boxes in current solution: used to find optimum solution
    ////int last_added_box = BoxList[0].number;     //added box counter (always starts from biggest box)
    ////printf("%d\n", BoxList[0].number);

    #define LAST_ADDED_BOX current_box_selection[counter]  //let's simplify code!

    //// FIX THIS, FUTURE ME... GOOD LUCK! I'M GOING TO SLEEP RN :)
    // FIND A BETTER COEFFICIENT TO FIX TEST CASE #3

    //biggest box (aka the starting box) runs through all elements: tries with all elements
    j = 7;  //! DEBUG
    while (j < total - 1)
    {
        i = j + 1; //i (element runner) is set equal to j (loop runner) at every cycle

        counter = 0;                        //array place counter (first place: biggest selected box)
        current_box_selection[counter] = j; //first element of said array is the index of current starting box

        //loops for every element in BoxList (sorted array), starting from second element
        while (i < total)
        {
            //if current box parameters are all smaller than last added box parameters
            if (BoxList[i].width < BoxList[LAST_ADDED_BOX].width &&
                BoxList[i].height < BoxList[LAST_ADDED_BOX].height &&
                BoxList[i].depth < BoxList[LAST_ADDED_BOX].depth)
            {
                //update last added box
                counter++;
                current_box_selection[counter] = i;
                ////last_added_box = BoxList[i].number;
            }

            i++;
        }

        counter++;

        if (j == 0) //on first iteration always copies current selection into selected_boxes
        {
            best_solution_num = counter;
            ////best_solution_num = 21;
            memcpy(selected_boxes, current_box_selection, ARRAY_SIZE * sizeof(int));
            /*
            for (int k = 0; k < total; k++)
            {
                selected_boxes[k] = current_box_selection[k];
            }
            */
        }

        //! DEBUG PURPOSES
        best_solution_num = counter;
        memcpy(selected_boxes, current_box_selection, ARRAY_SIZE * sizeof(int));
        break;

        //checks if current solution is optimal
        if (j != 0)     //can't check this on first iteration
        {
            if (counter > best_solution_num)   //current solution is better than former best solution
            {
                //updates best solution number
                best_solution_num = counter;

                
                //copies elements into new array
                /*
                for (int k = 0; k < total; k++)
                {
                    selected_boxes[k] = current_box_selection[k];
                }
                */
                memcpy(selected_boxes, current_box_selection, ARRAY_SIZE * sizeof(int));
            }
        }

        if (best_solution_num == total)
        {
            //in this case, it's already the best solution: we can end the loop right now
            break;
        }

        j++;
    }
    
    //! DA' 20 SCATOLE INVECE DI 21 - FIX THIS IF YOU CAN !

    //? DEBUG: prints selected_boxes array
    for (int i = 0; i < best_solution_num; i++)
    {
        printf("\nBOX No %3d - index %d", BoxList[selected_boxes[i]].number, selected_boxes[i]);
    }
    
/*
    //? DEBUG
    printf("\nTOTAL NUMBER OF BOXES: %d\n", best_solution_num);
    for (int s = 0; s < 1000; s++)
    {
        printf("original: %d\tcopied: %d\n", current_box_selection[s], selected_boxes[s]);
    }
    */

    //and display the final output in a format akin to the one in 1.out
    //? print first line of output (total boxes)
    printf("\n\n%d scatole\n", best_solution_num);
    ////printf("scatola in posizione 0: N %d W %f H %f D %f", BoxList[0].number, BoxList[0].width, BoxList[0].height, BoxList[0].depth);
    /*
    if(counter=0)
    {
        printf("\n\nERROR: no boxes selected");
        exit(1);
    }
    */


   //? print all chosen boxes, ordered by size and, hence, volume
    for (int i = 0; i < best_solution_num; i++)
    {
        printf("scatola %d: %.6f %.6f %.6f\n", BoxList[selected_boxes[i]].number, BoxList[selected_boxes[i]].width, BoxList[selected_boxes[i]].height, BoxList[selected_boxes[i]].depth);
    }


    system("pause");

    fclose(fptr);

    ////printf("Program name: %s\nFirst argument: %s\nSecond argument: %s", argv[0], argv[1], argv[2]);
    return 0;
}

/*
LET'S REASON A LITTLE BIT

Boxes need to be as big and close to a cube as possible, in order to maximize number of stacked boxes
So we need to come up with a proper compare coefficient


*/