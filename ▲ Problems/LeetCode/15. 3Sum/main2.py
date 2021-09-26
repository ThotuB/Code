def threeSum(nums: list[int]) -> list[list[int]]:
    res = []

    nums.sort()
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        left = i + 1
        right = len(nums) - 1
        while left < right:
            sum = nums[i] + nums[left] + nums[right]

            if sum == 0:
                res.append([nums[i], nums[left], nums[right]])
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
            if sum < 0:
                left += 1
            else:
                right -= 1

    return res


if __name__ == '__main__':
    print(threeSum([-1, 0, 1, 2, -1, -4]))