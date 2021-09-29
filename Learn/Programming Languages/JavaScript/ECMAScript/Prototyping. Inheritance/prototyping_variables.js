// Version 1
let Particle = {
    create: function (x, y) {
        let obj = Object.create(this);
        obj.x = x;
        obj.y = y;
        return obj;
    },
    move: function () {
        this.x += Math.random() * 2 - 1;
        this.y += Math.random() * 2 - 1;
    },
    draw: function () {
        return `${this.x}, ${this.y}`
    }
}

let Confetti = {
    create: function (x, y, color) {
        let obj = Particle.create(x, y);
        obj.color = color;
        return obj;
    },
    getColor: function () {
        return this.color;
    },
    setColor: function (color) {
        this.color = color;
    }
}

// Example
let particle = Particle.create(0, 0)
console.log(particle.draw())
particle.move()
console.log(particle.draw())

let confetti = Confetti.create(0, 0, 'red')
console.log(confetti.color)
console.log(confetti.draw())
confetti.move()
console.log(confetti.draw())