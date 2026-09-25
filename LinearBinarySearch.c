#include <stdio.h>

int LinearSearch(int arr[],int validcount, int element){
    for(int i=0;i<validcount;i++){
        if(arr[i]==element){
            printf("Element %d is found at index %d\n",element,i);
        }
    }
}
int BinarySearch(int arr[],int validcount,int element) {
    int low,mid,high;
    low = 0;
    high = validcount-1;
    
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]==element)
            return mid;
        
        else if(arr[mid]<element)
            low = mid+1;
        
        else
            high = mid-1;
        
    }
    return -1;
}    


int main() {
    int arr[100] = {1,2,3,4,5,10,23};
    int size = sizeof(arr)/sizeof(int);
    int element,validcount =7;
    printf("Enter element to search in array:");
    scanf("%d",&element);
    LinearSearch(arr,validcount,element);
    int searchindex =  BinarySearch(arr,validcount,element);
    printf("Element %d is found at index %d",element,searchindex);
    return 0;
}