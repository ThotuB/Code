#include <stdio.h>
#include <stdlib.h>

void rotateLeft(int* nums, int numsSize, int k) {
    int *arr = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k ; i++){
        arr[i] = nums[i];
    }

    for (int i = 0 ; i < numsSize - k ; i++){
        nums[i] = nums[i + k];
    }

    for (int i = numsSize - k ; i < numsSize ; i++){
        nums[i] = arr[i - (numsSize - k)];
    }
}

void rotateRight(int* nums, int numsSize, int k) {
    int *arr = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k ; i++){
        arr[i] = nums[numsSize - k + i];
    }

    for (int i = numsSize - 1 ; i >= k ; i--){
        nums[i] = nums[i - k];
    }

    for (int i = 0; i < k ; i++){
        nums[i] = arr[i];
    }
}

void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    
    if ( k < numsSize / 2 ){
        rotateRight(nums, numsSize, k);
    }
    else {
        rotateLeft(nums, numsSize, numsSize - k);
    }
}

void test(){
    int nums[] = {1,2,3,4,5,6,7};
    int numsSize = 7;
    int k = 5;
    rotate(nums, numsSize, k);
    for (int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
}

int main() {
    test();

    return 0;
}