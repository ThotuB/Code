let rows = 10;
let cols = 10;

let mines = 10;
let mineArr = [];
let board;

let sus;

// function preload(){
//     sus = loadImage("imgs/sus.png");
// }

function setup(){
    createCanvas(1200, 1200);
    background(0);
    for (let element of document.getElementsByClassName("p5Canvas")) {
        element.addEventListener("contextmenu", (e) => e.preventDefault());
    }

    board = new Board(width, height, rows, cols, mines);
}

function draw(){

}

function mousePressed(){
    switch ( mouseButton ){
        case LEFT:
            board.leftClick();
            break;
        case RIGHT:
            board.rightClick();
            break;
    }
}