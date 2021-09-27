class Grid {
    constructor(rows, cols) {
        this.boundry = new Boundary(0, gridY, gridW, gridH);

        this.rows = rows;
        this.cols = cols;

        this.reset();
    }

    reset() {
        this.walls = [];
        this.path = [];

        this.grid = [];

        for (let y = 0; y < this.rows; y++) {
            this.grid[y] = [];
            for (let x = 0; x < this.cols; x++) {
                this.grid[y][x] = new Node(x, y, true);
            }
        }
        
        this.setStart(2, 5);
        this.setEnd(17, 5);  
    } 
    
    setStart(x, y) {
        this.start = this.grid[y][x];
        this.start.update(null, 0, 0, 0);
    }

    setEnd(x, y) {
        this.end = this.grid[y][x];
    }

    setWall(x, y) {
        if ( !this.grid[y][x].walkable ) {
            const index = this.walls.indexOf(this.grid[y][x]);
            this.walls.splice(index, 1);

            this.grid[y][x].walkable = true;
        }
        else {
            this.walls.push(this.grid[y][x]);

            this.grid[y][x].walkable = false;
        }
    }

    neighbors(node) {
        let nbrs = [];
        for (let y = -1; y <= 1; y++) {
            for (let x = -1; x <= 1; x++) {
                if (x === 0 && y === 0) {
                    continue;
                }
                let xgrid = node.x + x;
                let ygrid = node.y + y;
                if (xgrid >= 0 && xgrid < this.cols && ygrid >= 0 && ygrid < this.rows) {
                    nbrs.push(this.grid[ygrid][xgrid]);
                }
            }
        }
        return nbrs;
    }

    draw() {
        for (let y = 0; y < this.rows; y++) {
            for (let x = 0; x < this.cols; x++) {
                this.grid[y][x].draw(color(255));
            }
        }
        for (let wall of this.walls) {
            wall.draw(color(0));
        }
        this.start.draw(color(0, 255, 0));
        this.end.draw(color(255, 0, 0));
    }

    drawPath() {
        for (let node of this.path) {
            node.draw(color(255, 0, 255));
        }
    }
}