#include <stdio.h>
int DeleteOddElements(int arr[],int n){
    int j = 0;

    for(int i=0;i<n;i++){
        if(arr[i]%2 == 0){
            arr[j] = arr[i];
            j++;
        }
    
    }
    return j;
}
    
int main() {
    int arr[50] = {10,2,3,7,8,6,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    arr[n] = DeleteOddElements(arr,n);
}