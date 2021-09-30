let nums = [1, [2, [3], [4, [5, 6, 7]], 8, 9], 10];

let numsFlat1 = nums.flat();
let numsFlat2 = nums.flat(3);

console.log(numsFlat1);
console.log(numsFlat2);