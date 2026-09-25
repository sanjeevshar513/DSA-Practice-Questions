#include <stdio.h>
#include <stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void CreateArray(struct myArray * s,int tsize, int usize){
    s -> total_size = tsize;
    s -> used_size = usize;
    s -> ptr = (int*) malloc (tsize * sizeof(int));
}

void InsertElements(struct myArray * s){
    int n;
    for(int i = 0; i < s-> used_size; i++){
       printf("Enter Elements:");
       scanf("%d\t",&(s->ptr)[i]);
    }
}

void ShowElements(struct myArray * s){ 
    for(int i = 0; i < s-> used_size; i++){
       printf("%d\n",(s->ptr)[i]);
    }
}


int main() {
    struct myArray classsize;
    int tsize;
    printf("Enter size of an array:");
    scanf("%d",&tsize);

    CreateArray(&classsize,tsize, 5);

    InsertElements(&classsize);

    ShowElements(&classsize);

    

    return 0;
}