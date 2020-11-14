let time = 0;
let wave = [];

let xScale = 0.5;
let yScale = 1;
let xOffset = 500;

let drawing;

function setup(){
    createCanvas(2000, 1200);
    wave[0] = [];
    wave[1] = [];
    wave[2] = [];
}

function draw(){
    background(0);
    translate(400, 200);

    let radius = 100;

    for (drawing = 0 ; drawing < 3 ; drawing ++){
        stroke(255);
        noFill();
        fourierCircles(time, radius, 0, 0, 0, 1 + 10 * drawing * drawing);

        beginShape();
        noFill();
        for (let i = 0 ; i < 1000 ; i++){
            vertex(i * xScale + xOffset, wave[drawing][i] * yScale);
        }
        endShape();
        
        translate(0, 4 * radius);
    } 

    time -= 0.01;
}