class AStar {
    constructor(grid){
        this.grid = grid;
        this.open = new PriorityQueue();
        this.open.enqueue(grid.start);
    }

    step() {
        if ( this.open.isEmpty() ) {
            return;
        }
        let current = this.open.dequeue();
        current.walkable = false;

        current.draw(color(255,0,255),true);

        if ( current === this.grid.end ) {
            this.grid.end.drawPath();
            this.open.clear();
        }
        
        let neighbors = this.grid.neighbors(current);
        for (let i = 0; i < neighbors.length; i++) {
            let neighbor = neighbors[i];
            if ( !neighbor.walkable ) {
                continue;
            }

            let gCost = Node.distance(current, neighbor);
            let hCost = Node.distance(neighbor, this.grid.end);
            let fCost = gCost + hCost;

            if ( neighbor.f > fCost || neighbor.f === Infinity ) {
                neighbor.update(current, gCost, hCost, fCost);

                if ( !this.open.contains(neighbor) ) {
                    this.open.enqueue(neighbor);
                    neighbor.draw(color(100, 100, 255), true);
                }
            }
        }
    }
}