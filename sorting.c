#include <stdio.h>

void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[50] = {4, 6, 2, 7, 1, 9, 0};
    int size = 7;

    BubbleSort(arr, size);

    for (int a = 0; a < size; a++) {
        printf("%d ", arr[a]);
    }
    printf("\n");

    return 0;
}