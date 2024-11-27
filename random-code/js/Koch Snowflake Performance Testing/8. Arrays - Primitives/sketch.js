let xs = [];
let ys = [];
let angles = [];

let x = 100;
let length;

let iter = 2;

function setup() {
    createCanvas(1200, 1200);

    length = width - 2 * x;

    xs[0]= x;
    ys[0] = height/2;
    angles[0] = 0;

    xs[1] = x + length;
    ys[1] = height/2;
    angles[1] = 0;

    drawKoch();
}

function drawKoch() {
    background(0);
    stroke(255);
    strokeWeight(2);

    for (let i = 0 ; i < xs.length - 1 ; i++) {
        Koch.drawLine(xs[i], ys[i], xs[i+1], ys[i+1]);
    }
}

function mousePressed() {
    length /= 3;

    let timer = millis();

    for (let i = 0 ; i < xs.length - 1 ; i += 4) {
        let data = Koch.split(xs[i], ys[i], xs[i+1], ys[i+1], angles[i]);
        let xsNew = data[0];
        let ysNew = data[1];
        let anglesNew = data[2];

        xs.splice(i+1, 0, ...xsNew);
        ys.splice(i+1, 0, ...ysNew);
        angles.splice(i+1, 0, ...anglesNew);
    }

    console.log(iter + " - " + (millis() - timer));
    iter++;

    drawKoch();
}