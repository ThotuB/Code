def maxArea(height: list[int]) -> int:
    max_area = 0
    left = 0
    right = len(height) - 1
    
    while left < right:
        area = (right - left) * min(height[left], height[right])
        max_area = max(max_area, area)
        
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
            
    return max_area 

if __name__ == '__main__':
    assert maxArea([1,8,6,2,5,4,8,3,7]) == 49
    assert maxArea([1,1]) == 1