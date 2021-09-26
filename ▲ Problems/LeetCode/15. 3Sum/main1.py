def threeSum(nums: list[int]) -> list[list[int]]:
    results = []
    
    for i in range(len(nums)-2):
        for j in range(i+1, len(nums)-1):
            for k in range(j+1, len(nums)):
                if nums[i] + nums[j] + nums[k] == 0:
                    results.append([nums[i], nums[j], nums[k]])
    return results


if __name__ == '__main__':
    print(threeSum([-1, 0, 1, 2, -1, -4]))