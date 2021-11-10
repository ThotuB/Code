from typing import List

def two_number_sum(nums: List[int], target: int) -> List[int]:
    complement_dict = dict()
    complements = []
    
    for num in nums:
        complement = target - num

        if num in complement_dict:
            complements += [(complement_dict[num], num)]

        complement_dict[complement] = num

    return complements


if __name__ == '__main__':
    print(two_number_sum([3, 5, -4, 8, 11, 1, -1, 6], 11))