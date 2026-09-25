#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr -> next;
    }
}
struct Node* InsertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct Node* InsertAtIndex(struct Node *head, int data,int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;

}

struct Node* InsertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;

}

struct Node* InsertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;

}
// Deleting First Node of Linked List
struct Node * DeleteFirst(struct Node * head){
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
    
}

struct Node * DeleteAtIndex(struct Node *head, int index){
    struct Node *t1 = head;
    struct Node *t2 = head->next;
    for(int i=0;i<index-1;i++){
        t1 = t1->next;
        t2 = t2->next;
    }
    t1->next= t2->next;
    free(t2);
    return head;
}

struct Node * DeleteAtVal(struct Node *head, int value){
    struct Node *t1 = head;
    struct Node *t2 = head->next;
    while(t2->data!=value && t2->next!= NULL){
        t1 = t1->next;
        t2 = t2->next;
    }
    if(t2->data==value){
       t1->next= t2->next;
       free(t2);
    }
    else{
        printf("Value %d not found in the linked list\n", value);
    }
    return head;
}

struct Node * DeleteLast(struct Node *head){
    struct Node *t1 = head;
    struct Node *t2 = head->next;
    while(t2->next!=NULL){
        t1 = t1->next;
        t2 = t2->next;
    };
    t1->next= NULL;
    free(t2);
    return head;
}

int main()
{
    struct Node *head, *second, *third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head ->data = 2;
    head -> next  = second;

    second -> data = 4;
    second -> next = third;

    third -> data = 7;
    third -> next  = NULL;

    printf("Before Linked List\n");
    Traversal(head);
    printf("\nAfter Linked List\n");
    //head = InsertAtFirst(head, 56);
    //head = InsertAtIndex(head, 56, 2);
    //head = InsertAtEnd(head, 56);
    //head = InsertAfterNode(head, second,56);
    //head = DeleteFirst(head);
    //head = DeleteAtIndex(head,1);
    //head = DeleteLast(head);
    head = DeleteAtVal(head,9);

    Traversal(head);

    return 0;
}