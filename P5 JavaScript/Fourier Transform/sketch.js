let time = 0;
let wave = [];

let yCoord = [];
let xCoord = [];

let xFourier = [];
let yFourier = [];

let xScale = 10;
let xOffset = 600;

let graphHeight = 300;

function setup(){
    createCanvas(2000, 1200);

    //yCoord = [300, 300, 300, -300, -300, -300, 300, 300, 300, -300, -300, -300];
    for (let i = 0 ; i < 100 ; i++){
        yCoord[i] = graphHeight * random(-1, 1);
    }

    yFourier = discrete_fourier_transform(yCoord);
    yFourier.sort( (a, b) => b.ampl - a.ampl);
}

function fourier_circles(x, y, fourier){
    let xPrev = x;
    let yPrev = y;
    
    for (let i = 0 ; i < fourier.length ; i++){
        let freq = fourier[i].freq;
        let radius = fourier[i].ampl;
        let phase = fourier[i].phase;

        x += radius * cos(freq * time + phase);
        y += radius * sin(freq * time + phase);

        stroke(255);
        noFill();
        ellipse(xPrev, yPrev, 2*radius);
        line(xPrev, yPrev, x, y);

        xPrev = x;
        yPrev = y;
    }

    line(x, y, xOffset, y);
    fill(255);
    ellipse(x, y, 10);
    
    wave.unshift(y);
}

function draw(){
    background(0);
    translate(500, 500);

    fourier_circles(0, 0, yFourier);

    beginShape();
    noFill();
    for (let i = 0 ; i < wave.length ; i++){
        vertex(i * xScale + xOffset, wave[i]);
    }
    endShape();
    
    if ( wave.length > 500 ){
        wave.pop();
    }

    //let dt = 2*PI/yCoord.length;
    time -= 0.01;
}