def kSum(nums: list[int], target: int, k: int) -> list[list[int]]:
    def TwoSum(nums, target):
        left = 0
        right = len(nums) - 1

        result = []
        while left < right:
            sum = nums[left] + nums[right]

            if sum == target:
                result += [[nums[left], nums[right]]]
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

        return result
        

    def KSum(nums, target, k):
        if ( k == 2 ):
            return TwoSum(nums, target)

        result = []
        for i in range(len(nums) - k + 1):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for subset in KSum(nums[i + 1:], target - nums[i], k - 1):
                result += [[nums[i]] + subset]

        return result


    nums.sort()
    return KSum(nums, target, k)


if __name__ == "__main__":
    nums = [1, 0, -1, 0, -2, 2, 1]
    target = 0
    k = 3
    results = kSum(nums, target, k)
    print(results)