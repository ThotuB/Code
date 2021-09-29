// parameter matching
function listMatch([name, val]) {
    return {name, val}
}

function objMatch({name, val}) {
    return {name, val}
}

listMatch(['name', 'value'])
objMatch({name: 'name', val: 'value'})

// object parameters
function getFullName({firstName, lastName}) {
    return `${firstName} ${lastName.toUpperCase()}`
}

let person = {
    firstName: 'John',
    lastName: 'Doe',
    age: 30,
    languages: ['en', 'es'],
    address: {
        street: 'Main St.',
        city: 'New York',
        state: 'NY'
    }
}

console.log(getFullName(person))
