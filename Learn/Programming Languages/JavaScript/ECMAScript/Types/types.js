// Type: number
let nr1 = 1;
let nr2 = 2.0;
console.log(typeof(nr1))
console.log(typeof(nr2))

// Type: string
let str1 = "Hello";
let str2 = 'World';
console.log(typeof(str1))
console.log(typeof(str2))

// Type: boolean
let bool1 = true;
let bool2 = false;
console.log(typeof(bool1))
console.log(typeof(bool2))

// Type: undefined
let undef1 = undefined;
console.log(typeof(undef1))
console.log(typeof(undef2))

// Type: object
let obj1 = {}
let obj2 = new Object()
console.log(typeof(obj1))
console.log(typeof(obj2))

// Type: bigint
let bigint1 = BigInt(123)
let bigint2 = 2n
console.log(typeof(bigint1))
console.log(typeof(bigint2))

// Type: symbol
let sym1 = Symbol("Hello")
let sym2 = Symbol("World")
console.log(typeof(sym1))
console.log(typeof(sym2))