#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void Traversal(struct Node *head){
    struct Node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr -> next;
    }

    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr -> prev;
    }
  
}

int main(){
     struct Node *head, *second, *third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head ->data = 2;
    head -> next  = second;
    head -> prev = NULL;

    second -> data = 4;
    second -> next = third;
    second -> prev = head;

    third -> data = 7;
    third -> next  = NULL;
    third -> prev = second;

    Traversal(head);


}