def fourSum(nums: list[int], target: int) -> list[list[int]]:
    res = []

    nums.sort()
    for i in range(len(nums) - 3):
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        for j in range(i + 1, len(nums) - 2):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue

            left = j + 1
            right = len(nums) - 1
            while left < right:
                sum = nums[i] + nums[j] + nums[left] + nums[right]

                if sum == target:
                    res.append([nums[i], nums[j], nums[left], nums[right]])
                    # skip duplicates
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    # move margins
                    left += 1
                    right -= 1
                    continue

                # move margin
                if sum < target:
                    left += 1
                else:
                    right -= 1

    return res


if __name__ == '__main__':
    print(fourSum([-1, 0, 1, 0, -2, 2], 0))
    print(fourSum([2, 2, 2, 2, 2], 8))