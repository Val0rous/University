#include <stdio.h>
#include <stdlib.h>

void swap_val(int,int);
void swap_rif(int*,int*);

int main(){
    int x,y;
    printf("Inserisci x e y:\n");
    scanf("%d %d",&x,&y);
    fflush(stdin);
    swap_val(x, y);
    printf("Dopo lo swap con passaggio per valore: x vale %d, y vale %d\n",x,y);
    swap_rif(&x, &y);
    printf("Dopo lo swap con passaggio per indirizzo: x vale %d, y vale %d\n",x,y);
    return 0;
}

// swap con passaggio per valore
void swap_val(int x, int y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

// swap con passaggio per indirizzo
void swap_rif(int *px, int *py){
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}
