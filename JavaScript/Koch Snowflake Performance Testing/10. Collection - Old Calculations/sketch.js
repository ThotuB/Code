let list;

let x = 100;
let length;

let iter = 2;

function setup() {
    createCanvas(1200, 1200);

    length = width - 2 * x;

    list = new KochCollection();
    drawKoch();
}

function drawKoch() {
    background(0);
    stroke(255);
    strokeWeight(2);

    for (let i = 0 ; i < list.length - 1 ; i++) {
        KochCollection.drawLine(list.xs[i], list.ys[i], list.xs[i+1], list.ys[i+1]);
    }
}

function mousePressed() {
    length /= 3;
    
    let timer = millis();
    
    for (let i = 0 ; i < list.xs.length - 1 ; i += 4) {
        KochCollection.split(list.xs[i], list.ys[i], list.xs[i+1], list.ys[i+1]);
    }

    console.log(iter + " - " + (millis() - timer));
    iter++;

    drawKoch();
}