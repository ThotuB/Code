nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

slice1 = slice(2, 4) # [2:4]
slice2 = slice(0, 10, 2) # ~= [0:10:2]

print(slice1)
print(nums[slice1])
print(slice2)
print(nums[slice2])