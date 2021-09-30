let transactions = [
    { id: 101, amount: 10 },
    { id: 102, amount: 20 },
    { id: 103, amount: -42 },
    { id: 104, amount: -100 },
    { id: 105, amount: +200 },
    { id: 106, amount: -300 },
    { id: 107, amount: +550 },
    { id: 108, amount: -80 },
    { id: 109, amount: -100 },
]

let sign = (sgn) => (transaction) => sgn * transaction.amount >= 0

let profits = transactions
    .filter(sign(+1))
let losses = transactions
    .filter(sign(-1))

console.log(profits)
console.log(losses)