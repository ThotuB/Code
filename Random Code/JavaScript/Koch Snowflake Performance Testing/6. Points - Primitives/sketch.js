let points = [];

let x = 100;
let length;

let iter = 2;

function setup() {
    createCanvas(1200, 1200);

    length = width - 2 * x;

    timer = millis();

    points[0] = new KochPoint(x, height/2, 0);
    points[1] = new KochPoint(x + length, height/2, 0);
    drawKoch();
}

function drawKoch() {
    background(0);
    stroke(255);
    strokeWeight(2);

    for (let i = 0 ; i < points.length - 1 ; i++) {
        points[i].drawLine(points[i+1]);
    }
}

function mousePressed() {
    length /= 3;

    let timer = millis();

    for (let i = 0 ; i < points.length - 1 ; i += 4) {
        let pts = KochPoint.split(points[i], points[i+1]);
        points.splice(i+1, 0, ...pts);
    }

    console.log(iter + " - " + (millis() - timer));
    iter++;

    drawKoch();
}