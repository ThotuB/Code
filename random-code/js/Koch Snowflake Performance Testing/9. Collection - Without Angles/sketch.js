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

    for (let i = 0 ; i < list.xs.length - 1 ; i++) {
        KochCollection.drawLine(list.xs[i], list.ys[i], list.xs[i+1], list.ys[i+1]);
    }
}

function mousePressed() {
    length /= 3;
    
    let timer = millis();
    
    for (let i = 0 ; i < list.xs.length - 1 ; i += 4) {
        let data = KochCollection.split(list.xs[i], list.ys[i], list.xs[i+1], list.ys[i+1]);
        let xsNew = data[0];
        let ysNew = data[1];

        list.xs.splice(i+1, 0, ...xsNew);
        list.ys.splice(i+1, 0, ...ysNew);
    }

    console.log(iter + " - " + (millis() - timer));
    iter++;

    drawKoch();
}