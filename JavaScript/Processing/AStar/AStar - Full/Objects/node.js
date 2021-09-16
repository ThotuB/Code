class Node {
    constructor(x, y, walkable) {
        this.x = x;
        this.y = y;

        this.walkable = walkable;
        
        this.f = Infinity;

        this.parent = null;
    }

    update(node, cost){
        this.f = cost;
        this.parent = node;
    }

    path() {
        let path = [];
        
        for (let node = this; node != null; node = node.parent) {
            path.push(node);
        }
        path = path.reverse();

        return path;
    }

    compareTo(other) {
        return this.f - other.f;
    }

    static distance(a, b) {
        let dx = abs(a.x - b.x);
        let dy = abs(a.y - b.y);

        if ( dx > dy ){
            return dy * 14 + 10 * (dx - dy);
        }
        return dx * 14 + 10 * (dy - dx);
    }

    draw(color) {
        fill(color);
        stroke(0);
        rect(this.x * scl, this.y * scl + gridY, scl, scl);
    }

    print() {
        console.log(`x: ${this.x}, y: ${this.y}, f: ${this.f}`);
    }
}