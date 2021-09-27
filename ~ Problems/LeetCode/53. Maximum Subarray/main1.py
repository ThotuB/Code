def maxSubArray(nums: list[int]) -> int:
    max_sum = nums[0]
    sum = max_sum

    for i in range(1, len(nums)):
        sum = max(nums[i], sum + nums[i])
        max_sum = max(max_sum, sum)
    
    return max_sum


if __name__ == "__main__":
    print(maxSubArray([50, -20, 30]))