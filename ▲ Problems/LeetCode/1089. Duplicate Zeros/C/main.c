#include <stdio.h>

void insertZero(int* arr, int arrSize, int index) {
    for (int i = arrSize - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
}

void duplicateZeros(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            insertZero(arr, arrSize, i);
            i++;
        }
    }
}

int main() {
    int arr[] = {1, 0, 2, 3, 0, 4, 5, 0};
    int arrSize = sizeof(arr) / sizeof(int);
    duplicateZeros(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
}