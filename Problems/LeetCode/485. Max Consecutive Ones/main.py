def findMaxConsecutiveOnes(nums: list[int]) -> int:
    max_ones = 0
    ones = 0

    for num in nums:
        if num == 1:
            ones += 1
        else:
            max_ones = max(max_ones, ones)
            ones = 0

    return max(max_ones, ones)