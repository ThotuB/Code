# Time: O(n)
# Space: O(n)

def singleNumber(nums: list[int]) -> int:
    num_dict = {}
    for num in nums:
        if num in num_dict:
            num_dict[num] += 1
        else:
            num_dict[num] = 1
    for key, value in num_dict.items():
        if value == 1:
            return key


if __name__ == "__main__":
    print(singleNumber([2, 2, 1]))
    print(singleNumber([4, 1, 2, 1, 2]))
    print(singleNumber([1, 2, 1, 3, 3, 4, 4, 5, 5]))