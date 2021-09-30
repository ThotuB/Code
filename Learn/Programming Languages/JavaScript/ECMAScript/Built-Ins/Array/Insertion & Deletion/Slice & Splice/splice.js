let nums1 = [1, 2, 3, 4, 5];
let nums2 = [1, 2, 3, 4, 5];
let nums3 = [1, 2, 3, 4, 5];
let nums4 = [1, 2, 3, 4, 5];

let numsSpliced1 = nums1.splice(2)
let numsSpliced2 = nums2.splice(1, 2)
let numsSpliced3 = nums3.splice(1, 0, 2.5)
let numsSpliced4 = nums4.splice(3, 1, 3.5, 4.5)

console.log(numsSpliced1);
console.log(nums1);
console.log()

console.log(numsSpliced2);
console.log(nums2);
console.log()

console.log(numsSpliced3);
console.log(nums3);
console.log()

console.log(numsSpliced4);
console.log(nums4);
console.log()