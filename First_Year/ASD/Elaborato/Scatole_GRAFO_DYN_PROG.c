#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
////#include <math.h>
#include <string.h>
#include <stdbool.h>
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
// size comparison
// printing formatted output

// GRAPH CREATION:
// liste di adiacenza con puntatore alla testa contenuto dentro alla struttura
// poi DFS, almeno credo (con contatore TIME (forse inutile) e un altro contatore per memorizzare il numero di nodi finora visitati)
// in seguito, controlla il nodo col contatore (quell'altro) più alto e ricostruisci il percorso fatto dal nodo parent

//* creating output file (to do only when everything else is complete)



struct BoxData
{
    //sizes of box sides
    float width;
    float height;
    float depth;

    float volume;

    ////int fitting_following_boxes;    //holds the value of how many of the following boxes we can fit in the current one
    ////float max_cube;
    ////float cube_index;
    ////float min_cube; //cube of the shortest side of the box
    ////float base_area;     //base area = width * depth

    ////float stack_index;    //cube coefficient = 0*shortest side + volume * minimum cube

    int number; //original box number, before sorting
    int box_pos;    //position in array after first sorting

    //for DFS purposes
    struct BoxData *parent; //pointer to parent node
    int start_time;
    int end_time;
    int connected_nodes; //counts the number of nodes connected to each other until visit of current node
    enum dfs_color_states
    {
        WHITE,
        GRAY,
        BLACK
    } color;

    struct AdjacencyList *head_adjacency_list;  //pointer to adjacency list
};



struct AdjacencyList
{
    int box_pos;                 //box position in array
    int number;                  //box number
    struct AdjacencyList *next;  //pointer to next element
};

struct BoxSelect
{
    int box_pos;   //box position in array
    int number;    //box number
};

struct LongestLink
{
    int box_pos;
    int number;
    int numberofnext;     //number of box to which it points
    struct LongestLink *next;
    int longest_link;
};

//! make this a local variable
struct AdjacencyList adjacency_list[ARRAY_SIZE];    //array of head pointers to the related adjacency list

void initList (struct AdjacencyList **lis)
{
    //initializes list to empty list
    *lis = NULL;
}

int testEmptyList(struct AdjacencyList *lis)
{
    return (lis == NULL);
}

//insert element to tail of linked list
void insertTailList (struct AdjacencyList **lis, int elem, int num)
{
    struct AdjacencyList *last;     //element to add
    struct AdjacencyList *paux;

    paux = malloc(sizeof(struct AdjacencyList));
    assert(paux);

    paux->box_pos = elem;
    paux->number = num;
    paux->next = NULL;

    //empty list
    if(*lis == NULL)
        *lis = paux;

    //non-empty list
    else
    {
        last = *lis;
        //run through list
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = paux;
    }
}

/*
//inverts list
void invertList(struct AdjacencyList **lis)
{
    struct AdjacencyList *prec = NULL;  //points to element preceding current element
    struct AdjacencyList *suc;          //points to current element to edit the next one

    while (*lis != NULL)
    {
        suc = *lis;
        *lis = (*lis)->next;
        suc->next = prec;
        prec = suc;
    }

    *lis = prec;
}
*/

/*
//deletes element from list (not sure if this is useful)
void deleteElemList(struct AdjacencyList **lis, int val)
{
    struct AdjacencyList *del;
    struct AdjacencyList *temp;

    temp = *lis;
    while (temp->next && temp->next->box_pos != val)
        temp = temp->next;

    if (temp->next->box_pos ==val)
    {
        del = temp->next;
        temp->next = del->next;
        free(del);
    }
}
*/

//deletes entire list
void deleteList(struct AdjacencyList **lis)
{
    struct AdjacencyList *paux;

    if (*lis != NULL)
    {
        paux = (*lis)->next;
        free(*lis);
        deleteList(&paux);
        *lis = NULL;
    }
}

//* QUICKSORT ALGORITHM --- START

//useful function to swap two elements of struct BoxData type (just for volume sorting)
void swap(struct BoxData *a, struct BoxData *b)
{
    struct BoxData temp = *a;
    *a = *b;
    *b = temp;
}


//TODO: write quicksort function sorting by descending finishing visit times (can be done with qsort() to simplify code)

//* QUICKSORT ALGORITHM --- END

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
        if (arr[j].end_time >= pivot.end_time)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    //return partitioning index
    return (i + 1);
}

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

/*
//returns the maximum of its arguments
float maximum(float a, float b, float c)
{
    if (a > b && a > c)
    {
        return a;
    }

    else if (b > a && b > c)
    {
        return b;
    }

    else
    {
        return c;
    }
}
*/

//*DFS ALGORITHM --- START

void DFS_Visit(struct BoxData graph[], int vertex, int *time)
{
    (*time)++;
    graph[vertex].start_time = *time;
    graph[vertex].color = GRAY;

    /*
    //counts number of currently connected nodes
    graph[vertex].connected_nodes = counter;

    //updates selected_boxes[]
    if (counter > (*max_connected_nodes))
    {
        *max_connected_nodes = counter;
        
        //runs through current link (backwards) and adds elements to selected_boxes[]
        struct BoxData *aux = &graph[vertex];
        int position = 0;

        while (aux != NULL)
        {
            //this array stores the position of the box in box_data[], not the actual box number label
            selected_boxes[position] = (aux-graph);
            position++;
            aux = aux->parent;
        }
    }

    // test to check whether DFS path is correct
    // selected_boxes[*index] = vertex;
    // (*index)++;
    */

    //for each adjacent vertex
    struct AdjacencyList *temp = graph[vertex].head_adjacency_list;
    while (temp != NULL)
    {
        if (graph[temp->box_pos].color == WHITE)
        {
            //setting parent node (pointer)
            graph[temp->box_pos].parent = &graph[vertex];
            //visit the node
            DFS_Visit(graph, temp->box_pos, time);
        }
        //move on to next element in adjacency list
        temp = temp->next;
    }
//// ISSUE WITH TIME COUNTER

    graph[vertex].color = BLACK;
    (*time)++;
    graph[vertex].end_time = *time;
}

void DFS(struct BoxData graph[], int num_vertices)
{
    for (int i = 0; i < num_vertices; i++)
    {
        graph[i].color = WHITE;
        graph[i].parent = NULL;
    }
    int time = 0; //time variable initialized here
    //---END OF INIT---

    for (int i = 0; i < num_vertices; i++)
    {
        ////counter is reset at every major iteration
        ////int counter = 0;
        
        if (graph[i].color == WHITE)
        {
            DFS_Visit(graph, i, &time);
        }
    }
}

//* DFS ALGORITHM --- END

//edit to add the counter part

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
    struct BoxData box_data[ARRAY_SIZE];
    for (int counter = 0; counter < total; counter++)
    {
        temp_check = fscanf(fptr, "%f %f %f", &box_data[counter].width, &box_data[counter].height, &box_data[counter].depth);

        //error check
        if (temp_check != 3)
        {
            fprintf(stderr, "Error in scanning line %d of input file", (counter + 1));
            exit(1);
        }
        //fscanf(fptr, "%f", &box_data[counter].height);
        //fscanf(fptr, "%f", &box_data[counter].depth);

        box_data[counter].number = counter;

        //calculating volume
        box_data[counter].volume = ((box_data[counter].width) * (box_data[counter].height) * (box_data[counter].depth));

        //initializing parent pointer to NULL
        box_data[counter].parent = NULL;

        //current box index is being saved
        box_data[counter].box_pos = counter;

        ////calculating minimum cube
        ////box_data[counter].min_cube = powf(minimum(box_data[counter].width, box_data[counter].height, box_data[counter].depth), 3);

        ////calculating base area
        ////box_data[counter].base_area = box_data[counter].width * box_data[counter].depth;

        //////calculating cube coefficient
        ////box_data[counter].stack_index = box_data[counter].volume * box_data[counter].min_cube + 0*minimum(box_data[counter].width, box_data[counter].height, box_data[counter].depth);
    }

    ////sorting boxes by descending volume
    ////quicksort(box_data, 0, total - 1);   //* quicksort working properly

    //? DEBUG PURPOSES ONLY: prints the list it has just scanned from file input
    //? DEBUG PURPOSES (NOT) ONLY: prints newly sorted list
    //* data structure working properly
    for (int i = 0; i < total; i++)
    {
        printf("No %3d    W % 5.1f   H %5.1f   D %5.1f    V %8.1f\n", box_data[i].number, box_data[i].width, box_data[i].height, box_data[i].depth, box_data[i].volume);
    }
    // SUM and V/SUM didn't work (SUM = width + height + depth)
    // MINCB is the cube created with the shortest side of the box:
    // it's a measurement of how squared (shall I say cubed?) the box is: the bigger it is, the more regular the box

    //create another array which's gonna hold all the boxes (elements) which are gonna
    //be the max number of "Chinese boxes"


    //creating adjacence list -- THIS SHOULD BE FINE
    for (int i = 0; i < total; i++)
    {
        //initializing list and head pointer
        initList(&box_data[i].head_adjacency_list);
        ////box_data[i].head_adjacency_list = &adjacency_list[i];

        //adding current box to list (in tail) -- DO NOT DO THIS
        ////insertTailList(&box_data[i].head_adjacency_list, i);

        ////int counter = 0; //counts the number of following boxes we can fit in current one
        //links all following acceptable elements
        for (int j = 0; j < total; j++)
        {
            //if current box parameters are all smaller than reference box parameters
            if (box_data[j].width < box_data[i].width &&
                box_data[j].height < box_data[i].height &&
                box_data[j].depth < box_data[i].depth)
            {
                //increment counter and add current box to list
                ////counter++;
                insertTailList(&box_data[i].head_adjacency_list, j, box_data[j].number);
                ////last_added_box = box_data[i].number;
            }
        }

        ////storing counter value in struct variable
        ////box_data[i].fitting_following_boxes = counter;
    }

/*
    //print adjacence lists
    for (int i = 0; i < total; i++)
    {
        printf("\nAL #%d: ", i);
        struct AdjacencyList *temp = box_data[i].head_adjacency_list;
        while (temp != NULL)
        {
            printf("%3d (%d)\t", temp->box_pos, temp->number);
            temp = temp->next;
        }
    }
    printf("\n");
*/

    struct BoxSelect selected_boxes[ARRAY_SIZE];     //end selection of boxes
    int index = 0;                      //index counter
    struct BoxSelect current_selection[ARRAY_SIZE];  //current selection of boxes
    ////int max_connected_nodes = 0;
    struct LongestLink max_connected_nodes;
    max_connected_nodes.longest_link = 0;

    //this is gonna hold all selected boxes
    //int selected_boxes[ARRAY_SIZE];
    //int k = 0;
    //calling DFS
    //* DFS is working properly
    DFS(box_data, total);

    //making a copy of the array so we're not gonna lose adjacence list references
    struct BoxData box_data_top_sort[ARRAY_SIZE];
    memcpy(&box_data_top_sort, &box_data, sizeof(box_data));

    //TOPOLOGICAL SORT (on newer array)
    quicksort(box_data_top_sort, 0, total - 1);

/*
    //? DEBUG: prints this newly sorted array
    for (int i = 0; i < total; i++)
    {
        printf("\nNo %3d    W % 5.1f   H %5.1f   D %5.1f    V %8.1f    EndTime %d\n", box_data_top_sort[i].number, box_data_top_sort[i].width, box_data_top_sort[i].height, box_data_top_sort[i].depth, box_data_top_sort[i].volume, box_data_top_sort[i].end_time);
    }
*/

    //keeps longest links of boxes using dynamic programming
    struct LongestLink box_selection[ARRAY_SIZE];
    //elements in box_selection will be sorted by box number rather than box position in box_data_top_sort
    
    #define BOX_NUM box_data_top_sort[i].number   //items in box_selection are sorted by number, so the index is box number

    //getting longest list of stacked boxes
    for (int i = total - 1; i >= 0; i--)
    {
        //for all elements adjacent to current one
        //temporary pointer to head of adjacency list
        struct AdjacencyList *temp = box_data_top_sort[i].head_adjacency_list;
        
        //*guess it's working fine
        //no elements in adjacency list
        if (temp == NULL)
        {
            box_selection[BOX_NUM].longest_link = 1;
            box_selection[BOX_NUM].number = BOX_NUM;
            box_selection[BOX_NUM].numberofnext = -1;     //NEXT ELEM DOESN'T EXIST!!
            box_selection[BOX_NUM].next = NULL;
            box_selection[BOX_NUM].box_pos = box_data_top_sort[i].box_pos;
            continue;   //analyze next element
        }

        //selected elements are being placed like this: box_selection[box-number] = box-number

        //now, items must have at least one element in adjacency list
        //run through all elements of adjacency list
        int max = 0;
        do
        {
            //updating longest link for each box (keeps only largest value, as smaller ones would still be ignored later on)
            //current 
            if (box_selection[temp->number].longest_link > max)
            {
                box_selection[BOX_NUM].longest_link = box_selection[temp->number].longest_link + 1;
                box_selection[BOX_NUM].number = BOX_NUM;
                box_selection[BOX_NUM].numberofnext = temp->number;
                box_selection[BOX_NUM].next = &box_selection[temp->number];
                box_selection[BOX_NUM].box_pos = box_data_top_sort[i].box_pos;
                //updates max to make it work
                max = box_selection[BOX_NUM].longest_link - 1;
            }

            //keeping track of record-holder node (the one with the largest link chain)
            if (max + 1 > max_connected_nodes.longest_link)
            {
                max_connected_nodes.longest_link = max + 1;
                max_connected_nodes.number = BOX_NUM;
                max_connected_nodes.numberofnext = BOX_NUM;
                max_connected_nodes.next = &box_selection[BOX_NUM];
                ////max_connected_nodes.box_pos = box_selection[box_data_top_sort[i].number].box_pos;
            }

            //next element
            temp = temp->next;
        } while (temp != NULL);

        
    }

/*
    //* should be working fine
    //? DEBUG - printing box_selection array
    for (int i = 0; i < total; i++)
    {
        printf("\nNo: %d\tLongest Link: %d\tNext: %d", i, box_selection[i].longest_link, box_selection[i].numberofnext);
    }
    printf("\n\nStart Box: %d", max_connected_nodes.numberofnext);
*/

    //putting boxes in selected_boxes
    struct LongestLink *temp = max_connected_nodes.next;   //points to first chosen node
    index = 0;
    assert(temp);   //check (temp != NULL)

    while (temp != NULL)
    {
        selected_boxes[index].number = temp->number;
        selected_boxes[index].box_pos = temp->box_pos;
        index++;
        temp = temp->next;
    }

/*
    //? DEBUG: prints selected_boxes array
    for (int i = 0; i < max_connected_nodes.longest_link; i++)
    {
        printf("\nBOX No %d", selected_boxes[i].number);
    }

    ////printf("\n\nMAX BOX: %d\n\n", max_connected_nodes.number);
*/

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
    printf("\n\n%d scatole\n", max_connected_nodes.longest_link);
    ////printf("scatola in posizione 0: N %d W %f H %f D %f", box_data[0].number, box_data[0].width, box_data[0].height, box_data[0].depth);
    /*
    if(counter=0)
    {
        printf("\n\nERROR: no boxes selected");
        exit(1);
    }
    */


   //? print all chosen boxes, ordered by size and, hence, volume
    for (int i = 0; i < max_connected_nodes.longest_link; i++)
    {
        printf("scatola %d: %.6f %.6f %.6f\n", selected_boxes[i].number, box_data[selected_boxes[i].box_pos].width, box_data[selected_boxes[i].box_pos].height, box_data[selected_boxes[i].box_pos].depth);
    }

    printf("\n");
    system("pause");

    //freeing memory used by adjacency lists
    for (int i = 0; i < total; i++)
    {
        deleteList(&box_data[i].head_adjacency_list);
        deleteList(&box_data_top_sort[i].head_adjacency_list);
    }


    fclose(fptr);

    ////printf("Program name: %s\nFirst argument: %s\nSecond argument: %s", argv[0], argv[1], argv[2]);
    return 0;
}