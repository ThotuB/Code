let lines = [];

let x = 100;
let length;

let iter = 2;

function setup() {
    createCanvas(1200, 1200);

    length = width - 2*x;
    lines[0] = new KochLine(new Point(x, height/2), 0);
    drawKoch();
}

function drawKoch() {
    background(0);
    stroke(255);
    strokeWeight(2);

    for (let line of lines) {
        line.draw();
    }
}

function mousePressed() {
    length /= 3;

    let timer = millis();

    let newLines = [];
    for (let line of lines) {
        newLines.push(...line.split());
    }
    lines = newLines;

    console.log(iter + " - " + (millis() - timer));
    iter++;

    drawKoch();
}