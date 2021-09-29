let nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

let numsReduced1 = nums.reduce((acc, curr) => { // counts even numbers
    return acc + curr % 2
}, 0)

nums.reduce((acc, curr, index, array) => { // cumulative sum
    sum = acc + curr
    array[index] = sum

    return sum
}, 0)

console.log(numsReduced1)
console.log(nums)