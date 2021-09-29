let str = "   Hello World!   ";
let trimmedStr;

// trim start
trimmedStr = str.trimStart();
console.log(`|${trimmedStr}|`);

// trim end
trimmedStr = str.trimEnd();
console.log(`|${trimmedStr}|`);

// trim both
trimmedStr = str.trim();
console.log(`|${trimmedStr}|`);