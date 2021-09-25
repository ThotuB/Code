def thirdMax(nums: list[int]) -> int:
    max_1st = None
    max_2nd = None
    max_3rd = None
    
    for num in nums:
        if max_1st is None or num > max_1st:
            max_3rd = max_2nd
            max_2nd = max_1st
            max_1st = num
        elif (max_2nd is None or num > max_2nd) and num != max_1st:
            max_3rd = max_2nd
            max_2nd = num
        elif (max_3rd is None or num > max_3rd) and num != max_1st and num != max_2nd:
            max_3rd = num

    if max_3rd is None:
        return max_1st
    return max_3rd


if __name__ == "__main__":
    nums = [1, 2]
    print(thirdMax(nums))