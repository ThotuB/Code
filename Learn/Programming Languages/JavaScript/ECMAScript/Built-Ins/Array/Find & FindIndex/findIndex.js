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

let numIndex = nums.findIndex(num => num > 5);
let objIndex1 = objs.findIndex(obj => obj.name === 'Joe');
let objIndex2 = objs.findIndex(obj => obj.name === 'Jon');

console.log(numIndex);
console.log(objIndex1);
console.log(objIndex2);