let fibonacci = {
    *[Symbol.iterator]() {
        let a = 0, b = 1
        while (true) {
            [a, b] = [b, a + b]
            yield a
        }
    }
}

for (let n of fibonacci) {
    if (n > 20) {
        break
    }
    console.log(n)
}