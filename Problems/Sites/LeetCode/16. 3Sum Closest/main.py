def threeSumClosest(nums: list[int], target: int) -> int:
    nums.sort()
    closest = nums[0] + nums[1] + nums[2]
    
    for i in range(len(nums) - 2):
        left = i + 1
        right = len(nums) - 1
        while left < right:
            sum = nums[i] + nums[left] + nums[right]
            
            if sum == target:
                return sum
            elif sum < target:
                left += 1
            else:
                right -= 1
                
            if abs(sum - target) < abs(closest - target):
                closest = sum
                
    return closest


if __name__ == '__main__':
    assert threeSumClosest([-1, 2, 1, -4], 1) == 2
    assert threeSumClosest([0, 2, 1, -3], 1) == 0
    assert threeSumClosest([1, 1, 1, 0], -100) == 2