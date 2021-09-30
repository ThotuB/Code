let nums = [1, 2, 3, 4, 5];

let numsUnshift1 = nums.unshift(0)
let numsUnshift2 = nums.unshift(-2, -1)
let numsUnshift3 = nums.unshift([-5, -4, -3])

console.log(numsUnshift1);
console.log(numsUnshift2);
console.log(numsUnshift3);

console.log(nums)