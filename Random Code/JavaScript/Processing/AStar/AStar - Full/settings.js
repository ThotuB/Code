let height = 1200;
let width = 1800;

let rows = 10;
let cols = 20;

let scl = width / cols;

// Grid Positions
let gridH = scl * rows;
let gridW = scl * cols;

let gridY = (height - gridH) / 2;

// Button Positions
let buttonW = 100;
let buttonH = 50;

let buttonY = gridY / 2 - buttonH / 2;