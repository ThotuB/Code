const str = '0101'
let paddedStr;

// pad start
paddedStr = str.padStart(8, '0')
console.log(paddedStr)

// pad end
paddedStr = str.padEnd(8, '0')
console.log(paddedStr)


// EXAMPLES
// mask a number
const num = '0123456789abcdef'
const halfnum = num.slice(-8)
const maskedNum = halfnum.padStart(num.length, '*')
console.log(maskedNum)