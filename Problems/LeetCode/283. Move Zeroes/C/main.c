#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int i = 0, j = 0;
    while ( j < numsSize ){
        if ( nums[j] != 0 ){
            nums[i++] = nums[j];
        }
        j++;
    }
    while ( i < numsSize ){
        nums[i++] = 0;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    moveZeroes(nums, 5);
    for (int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
}