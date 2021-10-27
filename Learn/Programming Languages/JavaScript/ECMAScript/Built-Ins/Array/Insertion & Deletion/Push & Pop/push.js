let nums = [1, 2, 3, 4, 5];

let numsPush1 = nums.push(6)
let numsPush2 = nums.push(7, 8)
let numsPush3 = nums.push([9, 10])

console.log(numsPush1);
console.log(numsPush2);
console.log(numsPush3);

console.log(nums)

// equivalent

nums = [1, 2, 3, 4, 5];

nums = [...nums, 6]
numsPush1 = nums.length

nums = [...nums, 7, 8]
numsPush2 = nums.length

nums = [...nums, [9, 10]]
numsPush3 = nums.length