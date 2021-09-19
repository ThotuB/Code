#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* sortedSquares(int* nums, int numsSize){
    int k = numsSize - 1;
    int i, j = k;

    int* squares = (int*)malloc(numsSize * sizeof(int));

    for (i = 0 ; i < numsSize ; i++) {
        nums[i] = nums[i] * nums[i];
    }
    
    i = 0;
    while (i <= j){
        if ( nums[i] > nums[j] ){
            squares[k--] = nums[i];
            i++;
        } else {
            squares[k--] = nums[j];
            j--;
        }
    }

    return squares;
}

// ----------------------------------------------
void test() {
    int nums[] = {-4,-1,0,3,5};
    int numsSize = sizeof(nums) / sizeof(int);
    free(sortedSquares(nums, numsSize));
}

void timer(int iter) {
    clock_t start = clock();
    for (int i = 0; i < iter; i++) {
        test();
    }
    clock_t end = clock();
    printf("Time: %dms\n", (end - start));
}

int main(){
    // test();
    timer(10000000);

    return 0;
}