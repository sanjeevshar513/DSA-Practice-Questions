# include <stdio.h>
# include <stdlib.h>
#define MAX 100
struct Stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr){
    if(ptr->top ==-1)
        return 1;
    else
        return 0;      
}

int isFull(struct Stack *ptr){
    if(ptr->top == MAX - 1)
        return 1;
    else
        return 0;      
}


void push(struct Stack *s,char val){
    if(isFull(s)){
        printf("Stack Overflow");
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}


char pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow");
        return '\0';
    }
    else{
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int peek(struct Stack *s,int i){
    int arrayInd = s->top - i + 1;
    if(arrayInd< 0){
        printf("Invalid input");
        return -1;
    }
    else
        return s->arr[s->top-i+1]; 
}

int parenthesisMatch(char * exp){
    struct Stack *sp = (struct Stack*) malloc(sizeof(struct Stack));
    sp->size  = MAX;
    sp->top = -1;
    sp->arr = (char*) malloc(sp->size * sizeof(char));
    for(int i = 0;exp[i]!='\0';i++){
        if(exp[i] == '('){
            push(sp,'(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)) 
                return 0;
            pop(sp);
        } 
    }
    return isEmpty(sp);
}
int main(){
    char *exp =  "8*(9))";

    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching\n");
    }
    else{
        printf("The parenthesis is not matching\n");
    }
}