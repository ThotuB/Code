function* getNumbers() {
    yield 1;
    yield 2;
    yield 3;
    yield 4;
    yield 5;
}

let numbers = getNumbers();
console.log(numbers.next());
console.log(numbers.next());
console.log(numbers.next());
console.log(numbers.next());
console.log(numbers.next());
console.log(numbers.next());
