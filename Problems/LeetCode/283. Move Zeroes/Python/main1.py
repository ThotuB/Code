def moveZeroes(nums: list[int]) -> None:
    def swap(i, j):
        nums[i], nums[j] = nums[j], nums[i]

    right = len(nums) - 1
    while True:
        flag = False
        for i in range(right):
            if nums[i] == 0:
                flag = True
                swap(i, i+1)

        right -= 1
                
        if not flag:
            break


if __name__ == '__main__':
    nums = [0, 1, 0, 3, 12]
    moveZeroes(nums)
    print(nums)