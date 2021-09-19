def twoSum(numbers: list[int], target: int) -> list[int]:
    complementMap = dict()
    
    for i in range(len(numbers)):
        complement = target - numbers[i]
        if numbers[i] in complementMap:
            return [complementMap[numbers[i]] + 1, i + 1]
        complementMap[complement] = i