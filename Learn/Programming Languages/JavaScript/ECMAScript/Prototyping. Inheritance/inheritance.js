// Inheritance
class Particle {
    constructor(x, y) {
        this.x = x
        this.y = y
    }

    move() {
        this.x += Math.random() * 2 - 1
        this.y += Math.random() * 2 - 1
    }

    draw() {
        return `(${this.x}, ${this.y})`
    }
}

class Confetti extends Particle {
    constructor(x, y, color) {
        super(x, y);
        this.color = color
    }

    set color(color) { this._color = color }
    get color() { return this._color }
}

// Example
let particle = new Particle(0, 0)
console.log(particle.draw())
particle.move()
console.log(particle.draw())

let confetti = new Confetti(0, 0, 'red')
console.log(confetti.color)
console.log(confetti.draw())
confetti.move()
console.log(confetti.draw())
