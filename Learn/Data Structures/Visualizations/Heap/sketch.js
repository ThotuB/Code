let file = 'heap.txt'
let fileText

function preload(){
    fileText = loadStrings('../resources/' + file);
}

function setup() {
    createCanvas(1000, 1000);
    background(0);

    visualizeHeap(fileText);
}