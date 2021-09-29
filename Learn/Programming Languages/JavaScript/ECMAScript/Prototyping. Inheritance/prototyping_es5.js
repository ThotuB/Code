function Particle(x, y) {
    this.x = x;
    this.y = y;
}

Particle.prototype.move = function() {
    this.x += Math.random() * 2 - 1;
    this.y += Math.random() * 2 - 1;
}

Particle.prototype.draw = function() {
    return `${this.x}, ${this.y}`
}

function Confetti(x, y, color) {
    Particle.call(this, x, y);

    this.color = color;
}

Confetti.prototype = Object.create(Particle.prototype);

Confetti.prototype.getColor = function() {
    return this.color;
}

Confetti.prototype.setColor = function(color) {
    this.color = color;
}

// Example
let particle = new Particle(0, 0)
console.log(particle.draw())
particle.move()
console.log(particle.draw())

let confetti = new Confetti(0, 0, 'red')
console.log(confetti.getColor())
console.log(confetti.draw())
confetti.move()
console.log(confetti.draw())