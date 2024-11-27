def moveZeroes(nums):
    return nums.sort(key=lambda x: x==0)