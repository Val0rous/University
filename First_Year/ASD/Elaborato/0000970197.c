/*
*   FRANCESCO VALENTINI
*   # MAT: 0000970197
*   GRUPPO A
*   MAIL: francesco.valentin11@studio.unibo.it      (no typos)
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#define ARRAY_SIZE 10000


//* DECLARING STRUCTURES
//structure for box_data and box_data_top_sort
struct BoxData
{
    //sizes of box sides
    float width;
    float height;
    float depth;

    int number;     //original box number, before sorting
    int box_pos;    //position in array after first sorting

    //DFS-purposed stuff
    struct BoxData *parent; //pointer to parent node
    int start_time;
    int end_time;
        
    enum dfs_color_states
    {
        WHITE,
        GRAY,
        BLACK
    } color;

    struct AdjacencyList *head_adjacency_list;  //pointer to adjacency list
};

//structure for adjacency lists
struct AdjacencyList
{
    int box_pos;                 //box position in array
    int number;                  //box number
    struct AdjacencyList *next;  //pointer to next element
};

//structure for final selection of boxes
struct BoxSelect
{
    int box_pos;   //box position in array
    int number;    //box number
};

//structure to check longest link among boxes
struct LongestLink
{
    int box_pos;
    int number;
    int numberofnext;     //number of box to which it points
    struct LongestLink *next;
    int longest_link;
};



//* LIST MANAGEMENT FUNCTIONS
void initList (struct AdjacencyList **lis)
{
    //initializes list to empty list
    *lis = NULL;
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



//* QUICKSORT ALGORITHM
//swap two elements of struct BoxData type (used in quicksort)
void swap(struct BoxData *a, struct BoxData *b)
{
    struct BoxData temp = *a;
    *a = *b;
    *b = temp;
}

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



//* DFS ALGORITHM
void DFS_Visit(struct BoxData graph[], int vertex, int *time)
{
    (*time)++;
    graph[vertex].start_time = *time;
    graph[vertex].color = GRAY;

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
    //time variable initialized here
    int time = 0;
    //--- END OF INIT ---

    for (int i = 0; i < num_vertices; i++)
    {
        if (graph[i].color == WHITE)
        {
            DFS_Visit(graph, i, &time);
        }
    }
}



int main(int argc, char *argv[])
{
    //opening file from command line
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    assert(fptr);

    int total;  //total number of boxes

    //gets first number of text input (total number of boxes)
    int temp_check;
    temp_check = fscanf(fptr, "%d", &total);

    //error check
    if (temp_check != 1)     
    {
        fprintf(stderr, "\n\nError in scanning first number of input file\n\n");
        exit(1);
    }
    
    //initializing array of boxes
    struct BoxData box_data[ARRAY_SIZE];
    for (int counter = 0; counter < total; counter++)
    {
        temp_check = fscanf(fptr, "%f %f %f", 
                            &box_data[counter].width, 
                            &box_data[counter].height, 
                            &box_data[counter].depth);

        //error check
        if (temp_check != 3)
        {
            fprintf(stderr, "Error in scanning line %d of input file", (counter + 1));
            exit(1);
        }

        //saving box number
        box_data[counter].number = counter;

        //initializing parent pointer to NULL
        box_data[counter].parent = NULL;

        //current box index is being saved
        box_data[counter].box_pos = counter;
    }

    //creating adjacence list
    for (int i = 0; i < total; i++)
    {
        //initializing list and head pointer
        initList(&box_data[i].head_adjacency_list);

        //links all following acceptable elements
        for (int j = 0; j < total; j++)
        {
            //if current box parameters are all smaller than reference box parameters
            if (box_data[j].width < box_data[i].width &&
                box_data[j].height < box_data[i].height &&
                box_data[j].depth < box_data[i].depth)
            {
                //increment counter and add current box to list
                insertTailList(&box_data[i].head_adjacency_list, j, box_data[j].number);
            }
        }
    }

    //final selection of boxes
    struct BoxSelect selected_boxes[ARRAY_SIZE];
    //index counter
    int index = 0;
    //keeps a pointer to the best starting node for box linkage
    struct LongestLink max_connected_nodes;
    max_connected_nodes.longest_link = 0;

    //calling dfs to compute end visit times (for topological sort)
    DFS(box_data, total);

    //making a copy of the array so we're not gonna lose adjacence list references
    struct BoxData box_data_top_sort[ARRAY_SIZE];
    memcpy(&box_data_top_sort, &box_data, sizeof(box_data));

    //TOPOLOGICAL SORT (on newer array)
    quicksort(box_data_top_sort, 0, total - 1);

    //keeps track of longest links of boxes using dynamic programming
    struct LongestLink box_selection[ARRAY_SIZE];

    //elements in box_selection will be sorted by box number 
    //rather than box position in box_data_top_sort
    
    //items in box_selection are sorted by number, so the index is box number
    #define BOX_NUM box_data_top_sort[i].number

    //getting longest list of stacked boxes
    for (int i = total - 1; i >= 0; i--)
    {
        //for all elements adjacent to current one
        //temporary pointer to head of adjacency list
        struct AdjacencyList *temp = box_data_top_sort[i].head_adjacency_list;
        
        //no elements in adjacency list
        if (temp == NULL)
        {
            box_selection[BOX_NUM].longest_link = 1;
            box_selection[BOX_NUM].number = BOX_NUM;
            //next element doesn't exist!!
            box_selection[BOX_NUM].numberofnext = -1;
            box_selection[BOX_NUM].next = NULL;
            box_selection[BOX_NUM].box_pos = box_data_top_sort[i].box_pos;
            continue;   //analyze next element
        }

        //selected elements are being placed like this: 
        //box_selection[box-number] = box-number

        //now, items must have at least one element in adjacency list
        //run through all elements of adjacency list
        int max = 0;
        do
        {
            //updating longest link for each box 
            //(only keeps largest value, as smaller ones would 
            //still be ignored later on)

            //checking links for current box
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

            //keeping track of record-holder node 
            //(the one with the largest link chain)
            if (max + 1 > max_connected_nodes.longest_link)
            {
                max_connected_nodes.longest_link = max + 1;
                max_connected_nodes.number = BOX_NUM;
                max_connected_nodes.numberofnext = BOX_NUM;
                max_connected_nodes.next = &box_selection[BOX_NUM];
            }

            //next element
            temp = temp->next;
        } while (temp != NULL);
    }

    //if no boxes can be stacked
    if (max_connected_nodes.longest_link == 0)
    {
        //add first box to the list we're gonna print
        max_connected_nodes.longest_link = 1;
        max_connected_nodes.number = box_data_top_sort[0].number;
        max_connected_nodes.numberofnext = -1;
        max_connected_nodes.next = &box_selection[0];
    }

    //pointer to first chosen node
    struct LongestLink *temp = max_connected_nodes.next;
    index = 0;
    assert(temp);   //check (temp != NULL)

    //putting boxes in selected_boxes
    while (temp != NULL)
    {
        selected_boxes[index].number = temp->number;
        selected_boxes[index].box_pos = temp->box_pos;
        index++;
        temp = temp->next;
    }

    //displaying final output
    //print first line of output (total boxes)
    printf("\n%d scatole\n", max_connected_nodes.longest_link);

    //print all chosen boxes, ordered by size
    for (int i = 0; i < max_connected_nodes.longest_link; i++)
    {
        printf("scatola %d: %.6f %.6f %.6f\n",
                selected_boxes[i].number,
                box_data[selected_boxes[i].box_pos].width,
                box_data[selected_boxes[i].box_pos].height,
                box_data[selected_boxes[i].box_pos].depth);
    }
    
    //free memory used by adjacency lists
    for (int i = 0; i < total; i++)
    {
        deleteList(&box_data[i].head_adjacency_list);
    }

    //close currently open input file
    fclose(fptr);
    return 0;
}