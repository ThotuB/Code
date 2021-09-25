def sortArrayByParity(nums: list[int]) -> list[int]:
    left = 0
    right = len(nums) - 1

    while left < right:
        while left < right and nums[left] % 2 == 0:
            left += 1
        while left < right and nums[right] % 2 == 1:
            right -= 1
        
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1
    
    return nums


if __name__ == "__main__":
    nums = [3,1,2,4]
    print(sortArrayByParity(nums))
