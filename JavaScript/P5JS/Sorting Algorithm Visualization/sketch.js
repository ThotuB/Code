const DELAY = 10;

const SIZE = 100;
let Arr = [];

let timer = 0;
let swaps = 0;
let compares = 0;

let lenX;
let lenY;

function setup(){
    createCanvas(1000, 500);
    lenX = (width-100)/SIZE;
    lenY = (height-150)/SIZE;
    
    for (let i = 0 ; i < SIZE ; i++){
        Arr[i] = new SortNode( Math.ceil( Math.random() * SIZE ) );
        //Arr[i] = new SortNode( SIZE-i );
    }

    //bubble_sort1();
    //bubble_sort2();
    //bubble_sort3()
    cocktail_shaker_sort();
    //insertion_sort();
    //quick_sort(0, Arr.length-1);
    //radix_sort1(2);
    //radix_sort2(0, Arr.length-1, 6);
    //selection_sort();
    //shell_sort([7,5,3,2,1]);
}

function draw(){
    background(0);

    textSize(25);
    fill(255);
    text('Swaps: ' + str(swaps), 10, 30);
    text('Comparisons: ' + str(compares), 10, 60);

    translate(50, height-50);
    strokeWeight(0);
    for (let i = 0 ; i < Arr.length ; i++){
        Arr[i].show(0, 0);
        translate(lenX, 0);
    }
}