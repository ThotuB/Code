def twoSum(nums: list[int], target: int) -> list[int]:
    complementMap = dict()
    
    for i in range(len(nums)):
        complement = target - nums[i]
        if nums[i] in complementMap:
            return [complementMap[complement], i]
        complementMap[complement] = i