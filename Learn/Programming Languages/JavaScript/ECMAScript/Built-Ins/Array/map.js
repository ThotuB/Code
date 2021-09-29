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

let numsMapped = nums.map((num) => Math.log(num))
let objsMapped = objs.map((obj) => {
    obj.name = obj.name.toUpperCase();
    return obj;
})

console.log(numsMapped);
console.log(objsMapped);