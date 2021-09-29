let displayThis1 = function() {
    let output = `${this}\n`
    for (let key in this) {
        output += `${key}\n`
    }
    return output
};

let displayThis2 = () => {
    let output = `${this}\n`
    for (let key in this) {
        output += `${key}\n`
    }
    return output
}

function displayThis3() {
    let output = `${this}\n`
    for (let key in this) {
        output += `${key}\n`
    }
    return output
}

console.log(displayThis1())
console.log(displayThis2())
console.log(displayThis3())

let person = {
    id: 500121635005,
    name: 'John',
    age: 30,
    languages: ['English', 'Spanish', 'French'],
    display1: displayThis1,
    display2: displayThis2,
    display3: displayThis3
}

console.log(person.display1())
console.log(person.display2())
console.log(person.display3())
