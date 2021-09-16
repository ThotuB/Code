// Callbacks
function AStarStep() {
    astar.step();
}

function resetGrid() {
    grid.reset();
    grid.draw();
    astar = new AStar(grid);
}

function setPick(args) {
    pick = args[0];
}