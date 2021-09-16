// Callbacks
function findPath() {
    grid.findPath();
}

function resetGrid() {
    grid.reset();
    grid.draw();
}

function setPick(args) {
    pick = args[0];
}

let crtStep = 0;
function step() {
    if (crtStep < steps.length) {
        steps[crtStep].draw();
        crtStep++;
    }
    if ( crtStep === steps.length) {
        grid.drawPath();
        crtStep++;
    }
}