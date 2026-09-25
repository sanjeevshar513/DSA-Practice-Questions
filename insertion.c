#include <stdio.h>

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int InsertElements(int arr[],int size, int capacity){
    int element,index;
    printf("Enter element to be inserted and at which index value respectively:\n");
    scanf("%d %d",&element, &index);
    if(size>=capacity){
        printf("Array is full\n");
        return -1;
    }

    for(int i=size-1;i>=index;i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 0;
}

void deletion(int arr[],int size){
    int index;
    printf("enter index: ");
    scanf("%d",&index);
    for(int i=index;i<size-1;i++){
        arr[i] = arr[i+1];
    }
}
int main() {
    int arr[100]= {1,10,23,4,12,55};
    int size = 6, capacity = 100;
    
    deletion(arr,size);
    size--;
    display(arr,size);
    
    return 0;
}
