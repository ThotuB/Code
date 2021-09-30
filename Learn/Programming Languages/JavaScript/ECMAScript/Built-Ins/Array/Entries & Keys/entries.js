let nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

let iter = nums.entries();

console.log(iter);
for (let num of iter) {
    console.log(num[1]);
}
