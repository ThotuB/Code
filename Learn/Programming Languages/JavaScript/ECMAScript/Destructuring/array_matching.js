let list = [1, 2, 3, 4, 5];
let [left, , , , right] = list;
console.log(`${left} - ${right}`);

[left, right] = [right, left];
console.log(`${left} - ${right}`);


/// EXAMPLES
// 1. Error and Result
function func(n) {
    if ( n > 0 ) {
        return [false, 'positive']
    }
    return [true, 'negative']
}

[error, result] = func(5);
console.log(error);
console.log(result);

[error, result] = func(-5);
console.log(error);
console.log(result);

// 2. Swap
let a = 1;
let b = 2;
[a, b] = [b, a]
console.log(`${a} - ${b}`);