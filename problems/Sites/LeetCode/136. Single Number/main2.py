# Time: O(n)
# Space: O(1)

def singleNumber(nums: list[int]) -> int:
    result = nums[0]

    for i in range(1, len(nums)):
        result ^= nums[i]

    return result


if __name__ == "__main__":
    print(singleNumber([2, 2, 1]))
    print(singleNumber([4, 1, 2, 1, 2]))
    print(singleNumber([1, 2, 1, 3, 3, 4, 4, 5, 5]))