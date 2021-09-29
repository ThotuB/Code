function* range(start, end, step) {
    while (start < end) {
        yield start;
        start += step;
    }
}

for (let i of range(0, 10, 2)) {
    console.log(i);
}

function* fibonacci(numbers) {
    let a = 0, b = 1;
    while (numbers-- > 0) {
        [a, b] = [b, a + b];
        yield a;
    }
}

for (let n of fibonacci(10)) {
    console.log(n);
}