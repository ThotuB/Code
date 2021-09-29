let person = {
    name: 'John',
    surname: 'Smith',
    age: 30,
    languages: ['English', 'Spanish', 'Italian'],
    address: {
        street: 'Main street',
        number: '1'
    },
    details: function () {
        return `${this.name} ${this.surname} is ${this.age} years old.`;
    },
    sayHello: function () {
        return 'Hello!';
    }
}

let desctiptor = Object.getOwnPropertyDescriptor(person, 'name');
let desctiptors = Object.getOwnPropertyDescriptors(person);
let names = Object.getOwnPropertyNames(person);
let symbols = Object.getOwnPropertySymbols(person);
let prototype = Object.getPrototypeOf(person);

console.log("Descriptor: " + JSON.stringify(desctiptor, null, 2) + "\n");
console.log("Descriptors: " + JSON.stringify(desctiptors, null, 2) + "\n");
console.log("Names: " + JSON.stringify(names, null, 2) + "\n");
console.log("Symbols: " + JSON.stringify(symbols, null, 2) + "\n");
console.log("Prototype: " + JSON.stringify(prototype, null, 2) + "\n");