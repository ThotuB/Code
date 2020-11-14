let lenghtDecay;
let lengthDecaySlider;

let iterationMax;
let iterationMaxSlider;

let angles = [];

function setup(){
    createCanvas(2000, 1200);
    lengthDecaySlider = createSlider(0.1, 3, 2, 0.1);
    lengthDecaySlider.position(20, 80);
    iterationMaxSlider = createSlider(1, 16, 10, 1);

    angles = [PI/2, -PI/2];
}

function fractal_tree(x, y, length, angle, iteration){
    if ( length <= 1 || iteration >= iterationMax ){
        ;
    }
    else {
        let xNext = x + length * cos(angle);
        let yNext = y + length * sin(angle);

        line(x, y, xNext, yNext);

        for (let i = 0 ; i < angles.length ; i++){
            fractal_tree(xNext, yNext, length/lenghtDecay, angle + angles[i], iteration+1);
        }
    }
}

function draw(){
    background(0);
    translate(1000, 1000);

    let length = 300;

    lenghtDecay = lengthDecaySlider.value();
    iterationMax = iterationMaxSlider.value();

    stroke(255);
    fractal_tree(0, 0, length, -PI/2, 0);
}