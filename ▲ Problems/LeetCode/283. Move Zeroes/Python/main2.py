def moveZeroes(nums: list[int]) -> None:
    zero_count = 0
    new_nums = []

    for num in nums:
        if num == 0:
            zero_count += 1
        else:
            new_nums.append(num)

    for i in range(zero_count):
        new_nums.append(0)

    nums[:] = new_nums[:]


if __name__ == '__main__':
    nums = [0, 1, 0, 3, 12]
    moveZeroes(nums)
    print(nums)