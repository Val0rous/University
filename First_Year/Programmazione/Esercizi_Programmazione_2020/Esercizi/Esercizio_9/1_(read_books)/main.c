/*
Realizzare un programma che gestisca la lista di tutti i libri letti in un anno.
Per ognuno di essi, il programma deve memorizzare una serie di informazioni, ad esempio
il titolo, l’autore, l’anno di pubblicazione, la casa editrice, la lunghezza, il genere, il codice identificativo, la valutazione.
Il programma dovrà permettere di
inserire un nuovo libro, cancellarne uno, visualizzarli tutti, visualizzare solo quelli con una certa valutazione.
Il programma deve lavorare leggendo e scrivendo le informazioni da e su file binario.
Consegnare un file .zip contente un progetto che comprenda tutti i file necessari per testare il programma.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//define max string lenght
#define MAX_TITLE 10
#define MAX_AUTHOR 10
#define MAX_PUBLISHER 10
#define MAX_GENRE 10
//define structure of the book
typedef struct book_s
{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    short unsigned int year;
    char publisher[MAX_PUBLISHER];
    int lenght;
    char genre[MAX_GENRE];
    int id;
    short unsigned int rating;
} book_t;
//define node structure
typedef struct bookNode_s
{
    book_t book;
    struct bookNode_s* next;
} bookNode_t;

void addBook(bookNode_t**head) //to create new space in head
{
    bookNode_t*cursor=(bookNode_t*)malloc(sizeof(bookNode_t)); //call malloc
    if(cursor==NULL)                                            //check
    {
        printf("error malloc");
        system("pause");
        exit(1);
    }
    cursor->next=*head;//update new element
    *head=cursor;       //update head
}
void delHead(bookNode_t**head)     //delete first item
{
    bookNode_t*del=*head;   //temp variable
    *head=(*head)->next;    //update head
    free(del);              //del temp variable
}
void printList(bookNode_t* head)    //print list
{

    if(head!=NULL)printf("Name:\tAuthor:\tYear:\tPublisher:\tLenght:\tGenre:\tId:\tRating:\n");//if list is not empty print title
    else printf("The list is empty\n");
    for(bookNode_t* cursor=head; cursor!=NULL; cursor=cursor->next) //for each node print information
    {
        printf("%s\t%s\t%hu\t%s\t\t%d\t%s\t%d\t%hu\n",cursor->book.title,cursor->book.author,cursor->book.year,cursor->book.publisher,cursor->book.lenght,cursor->book.genre,cursor->book.id,cursor->book.rating);
    }
}

int main()
{

    while(1)//main cycle
    {



//read list from file
        FILE *fp=fopen("library.dat","rb");//open file
        if(fp==NULL)        //check
        {
            printf("the file is not existing(continue relaxed, it will be created) or inaccessible(exit now to avoid overwriting)\n");
        }

        bookNode_t* head=NULL;//initialize list
        do
        {
            addBook(&head);
        }
        while(fread(&(head->book), sizeof(book_t), 1, fp)>0);       //while there's data to read add items to the list
        delHead(&head);                                            //delete the first item(the previous cycle creates one empty)
        fclose(fp);                                                //close file

        //above the menu display the library
        printList(head);


        //menu and answer collection
        printf("\nMenu:\n");
        printf("1)New book\n");
        printf("2)Delete book\n");
        printf("3)Show all\n");
        printf("4)Filter by rating\n");
        printf("0)exit\n");
        char answer;
        while(1)
        {
            answer=getch();
            if (answer>='0'&&answer<'5')break;
        }


        //new book
        if (answer=='1')
        {
            system("cls");
            addBook(&head);//create space
            //get title
            printf("Which is the title?:");
            fgets(head->book.title, MAX_TITLE + 1, stdin);
            fflush(stdin);
            head->book.title[strlen(head->book.title) - 1] = '\0';
            //get author
            printf("Who is the author?:");
            fgets(head->book.author, MAX_AUTHOR + 1, stdin);
            fflush(stdin);
            head->book.author[strlen(head->book.author) - 1] = '\0';
            //get year
            printf("Which is the year of pubblication?:");
            while(1)
            {
                if(scanf("%hu",&(head->book.year)))break;
                fflush(stdin);
                printf("Invalid input, try again\n");
            }
            fflush(stdin);
            //get publisher
            printf("Who is the publisher?:");
            fgets(head->book.publisher, MAX_PUBLISHER + 1, stdin);
            fflush(stdin);
            head->book.publisher[strlen(head->book.publisher) - 1] = '\0';
            //get lenght
            printf("How long is the book?:");
            while(1)
            {
                if(scanf("%d",&(head->book.lenght)))break;
                fflush(stdin);
                printf("Invalid input, try again\n");
            }
            fflush(stdin);
            //get genre
            printf("Which is the genre?:");
            fgets(head->book.genre, MAX_GENRE + 1, stdin);
            fflush(stdin);
            head->book.genre[strlen(head->book.genre) - 1] = '\0';
            //get id
            printf("Which is the id of the book?\n(it will be used to delete the book so use univocal id if you want unique delete)\n");
            while(1)
            {
                if(scanf("%d",&(head->book.id)))break;
                fflush(stdin);
                printf("Invalid input, try again\n");
            }
            fflush(stdin);
            //get rating
            printf("Which is the rating of the book?:\n");
            while(1)
            {
                if(scanf("%hu",&(head->book.rating)))break;
                fflush(stdin);
                printf("Invalid input, try again\n");
            }
            fflush(stdin);
            printf("book added correctly\n");
            printf("press any key to continue...\n");
            fflush(stdin);
            getch();
            fflush(stdin);




        }

        //delete book
        if (answer=='2')
        {
            int canc=0; //flag to check if found
            system("cls");

            //ask the id to delete
            int idToDel;
            printf("Type the Id of the book to delete:\n");
            while(1)
            {
                if(scanf("%d",&idToDel))break;
                fflush(stdin);
                printf("Invalid input, try again\n");
            }
            fflush(stdin);


            bookNode_t* previus=NULL;//to keep track of the previous element
            for(bookNode_t* cursor=head; cursor!=NULL; cursor=cursor->next)//for each element
            {
                if(cursor->book.id==idToDel)//if matches
                {
                    canc=1; //mark as found
                    if(previus!=NULL)//if it's not the first element
                    {
                        previus->next=cursor->next;//update the previous
                    }
                    else head=cursor->next; //else update head

                    free(cursor);//delete element
                    break;
                }
                previus=cursor;//update previous at each cycle
            }
            //print feedback
            if(canc==0)printf("book not found!\n");
            else printf("book deleted correctly\n");
            printf("press any key to continue...\n");
            fflush(stdin);
            getch();
            fflush(stdin);
        }

        //print list
        if (answer=='3')
        {

            system("cls");
            printList(head);    //call function
            printf("press any key to continue...");
            fflush(stdin);
            getch();
            fflush(stdin);
        }

        //filter by rating
        if (answer=='4')
        {
            system("cls");

            //ask for min rating
            int minRating;
            printf("Type the minimum rating of the book to search:\n");
            while(1)
            {
                if(scanf("%d",&minRating)&&minRating>0)break;
                fflush(stdin);
                printf("Invalid input, try again\n");
            }
            fflush(stdin);

            //print filtered list

            //count how many elements are suitable
            system("cls");
            int results=0;
            for(bookNode_t* cursor=head; cursor!=NULL; cursor=cursor->next)
            {
                if(cursor->book.rating>=minRating)results++;
            }

            //print filtered list
            if(head!=NULL&&results>0)printf("Name:\tAuthor:\tYear:\tPublisher:\tLenght:\tGenre:\tId:\tRating:\n");//print title
            else printf("No results!\n");
            for(bookNode_t* cursor=head; cursor!=NULL; cursor=cursor->next)//for each element
            {
                //print if suitable
                if(cursor->book.rating>=minRating)printf("%s\t%s\t%hu\t%s\t\t%d\t%s\t%d\t%hu\n",cursor->book.title,cursor->book.author,cursor->book.year,cursor->book.publisher,cursor->book.lenght,cursor->book.genre,cursor->book.id,cursor->book.rating);
            } //print feedback
            if(results>0)printf(" %d result%c \n", results, results > 1 ? 's' : '\0');
            printf("press any key to continue...");
            fflush(stdin);
            getch();
            fflush(stdin);
        }




//save everithing
        fp=fopen("library.dat","wb");
        if(fp==NULL)
        {
            printf("error opening the file, exit and try again.");
            system("pause");
            exit(1);
        }//save each element
        for(bookNode_t* cursor=head; cursor!=NULL; cursor=cursor->next)
        {
            fwrite(&(cursor->book), sizeof(book_t), 1, fp);

        }
        fclose(fp);

        system("cls");

        //exit
        if (answer=='0')
        {
            //free all
            while(head!=NULL)
            {
                delHead(&head);
            }
            break;
        }
    }

    return 0;
}
