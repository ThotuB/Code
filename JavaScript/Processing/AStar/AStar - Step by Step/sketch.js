let grid;
let astar;
let buttons = [];

let GridElems = {
    START : 0,
    END : 1,
    WALL : 2,
}

let pick = GridElems.WALL;

function setup() {
    createCanvas(width, height);
    background(0);

    scl = width / cols;

    grid = new Grid(rows, cols);
    astar = new AStar(grid);
    grid.draw();
    setButtons();
}

function draw() {
    for (let button of buttons) {
        button.update();
        button.draw();
    }
}

function mousePressed() {
    if ( grid.boundry.mouseOver() ) {
        let x = floor(mouseX / scl);
        let y = floor((mouseY - grid.boundry.y) / scl);

        switch ( pick ) {
            case GridElems.START :
                grid.setStart(x, y);
                break;
            case GridElems.END :
                grid.setEnd(x, y);
                break;
            case GridElems.WALL :
                grid.setWall(x, y);
                break;
        }
        grid.draw();
    }
    else {
        for (let button of buttons) {
            if ( button.boundry.mouseOver() ) {
                button.action();
            }
        }
    }
}

function setButtons() {
    buttons = [
        new Button(200, buttonY, buttonW, buttonH, "Start", setPick, GridElems.START),
        new Button(400, buttonY, buttonW, buttonH, "End", setPick, GridElems.END),
        new Button(600, buttonY, buttonW, buttonH, "Wall", setPick, GridElems.WALL),
        new Button(800, buttonY, buttonW, buttonH, "Reset", resetGrid, null),
        new Button(1000, buttonY, buttonW, buttonH, "A*", AStarStep, null),
    ]
}
