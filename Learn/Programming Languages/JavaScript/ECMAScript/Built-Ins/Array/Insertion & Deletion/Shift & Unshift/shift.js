let nums = [1, 2, 3, 4, 5];

let numShifted = nums.shift()

console.log(numShifted)

console.log(nums)

// equivalent

nums = [1, 2, 3, 4, 5];

[numShifted, ...nums] = nums;