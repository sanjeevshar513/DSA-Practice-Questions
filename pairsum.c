
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[],int n);
void swap(int *x,int *y);
void Evaluate(int arr[],int target,int n);

int main(){
    int arr[50] = {10,20,30,40,50};
    int target = 60;
    int n = 5;

    sort(arr,n);
    printf("Sorted List :\n");
    for(int i=0;i<n;i++){
        printf("List[%d] = %d\n",i,arr[i]);
    }

    Evaluate(arr,target,n);
           

}

void sort(int arr[],int n){
    int i,j,min;
    for(i=0;i<n;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min = j;
        }
        swap(&arr[i],&arr[min]);
    }
}

void swap(int *x,int *y){
    int temp = *x;
    *x =*y;
    *y = temp;
}

void Evaluate(int arr[],int target,int n){
    int left,right,sum;
    left = 0;
    right = n-1;

    while(left<right){
        sum = arr[left] +arr[right];
        if(sum== target){
            printf("Pair Found");
            printf(" %d %d ",arr[left],arr[right]);
            break;
        }
        else
            printf("No pair found\n");
    

        if(sum<target)
            left++;
        else if(sum >target){
            right--;
        }
    }
}