#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n){
    int *nums = (int *)malloc(sizeof(int) * (m + n));

    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            nums[k++] = nums1[i++];
        } else {
            nums[k++] = nums2[j++];
        }
    }

    while (i < m) {
        nums[k++] = nums1[i++];
    }

    while (j < n) {
        nums[k++] = nums2[j++];
    }

    for (k = 0; k < m + n; k++) {
        nums1[k] = nums[k];
    }
}

int main() {
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    merge(nums1, 3, nums2, 3);

    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }
}