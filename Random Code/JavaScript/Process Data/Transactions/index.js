import fs from 'fs'

let data = fs.readFile('./data.csv', 'utf8')

/// Get Total Spent
let total = data
    .trim()
    .split('\n')
    .map(line => line.split(', '))
    .map(transaction => {
        let [name, , amount, price] = transaction
        return {
            name: name,
            amount: Number(amount),
            price: Number(price)
        }
    })
    .filter(transaction => transaction.name === 'john doe')
    .reduce((total, transaction) => {
        let {name, amount, price} = transaction
        return total + amount * price
    }, 0)
    .toString() + '$'


console.log(total)

/// Get Customer Transactions
let transactions = data
    .trim()
    .split('\n')
    .map(line => line.split(', '))
    .map(transaction => {
        let [name, item, amount, price] = transaction
        return {
            name: name,
            item: item,
            amount: Number(amount),
            price: Number(price)
        }
    })
    .reduce((customers, transaction) => {
        let {name, item, amount, price} = transaction
        customers[name] = customers[name] || []

        customers[name].push({
            item: item,
            amount: amount,
            price: price
        })

        return customers
    }, {})

console.log(JSON.stringify(transactions, null, 2))