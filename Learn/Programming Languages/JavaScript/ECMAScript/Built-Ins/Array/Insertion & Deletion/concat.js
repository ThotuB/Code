let nums = [1, 2, 3, 4, 5];

let numsConcat1 = nums.concat(6)
let numsConcat2 = nums.concat(6, 7)
let numsConcat3 = nums.concat([6, 7, 8])

console.log(numsConcat1);
console.log(numsConcat2);
console.log(numsConcat3);

// equivalent
nums = [1, 2, 3, 4, 5];

numsConcat1 = [...nums, 6]
numsConcat2 = [...nums, 6, 7]
numsConcat3 = [...nums, ...[6, 7, 8]]