let nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let objs = [
    { name: 'John', age: 20 },
    { name: 'Jane', age: 21 },
    { name: 'Joe', age: 22 },
    { name: 'Jack', age: 23 },
    { name: 'Jill', age: 24 },
    { name: 'Jim', age: 25 },
    { name: 'Jenny', age: 26 },
]

let numEntries = nums.keys();
let objEntries = objs.keys();

console.log(Array.from(numEntries));
console.log(Array.from(objEntries));