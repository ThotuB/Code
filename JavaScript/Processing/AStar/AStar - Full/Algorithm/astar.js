function AStar(grid) {
    let open = new PriorityQueue();

    open.enqueue(grid.start);
    while ( !open.isEmpty() ) {
        let current = open.dequeue();
        steps.push(new Step(current, "active"));
        current.walkable = false;

        if ( current === grid.end ) {
            return grid.end.path();
        }

        let neighbors = grid.neighbors(current);
        for (let i = 0; i < neighbors.length; i++) {
            let neighbor = neighbors[i];
            if ( !neighbor.walkable ) {
                continue;
            }

            let gCost = Node.distance(current, neighbor);
            let hCost = Node.distance(neighbor, grid.end);
            let fCost = gCost + hCost;

            if ( neighbor.f > fCost || neighbor.f === Infinity ) {
                neighbor.update(current, fCost);

                if ( !open.contains(neighbor) ) {
                    open.enqueue(neighbor);
                    steps.push(new Step(neighbor, "peek"));
                }
            }
        }
    }
    return null;
}