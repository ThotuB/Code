class Node {
    constructor(x, y, walkable) {
        this.x = x;
        this.y = y;

        this.walkable = walkable;
        
        this.g = Infinity;
        this.h = Infinity;
        this.f = Infinity;

        this.parent = null;
    }

    update(node, g, h, f){
        this.g = g;
        this.h = h;
        this.f = f;
        this.parent = node;
    }

    drawPath() {
        for (let node = this; node !== null ; node = node.parent) {
            node.draw(color(255, 255, 0));
        }
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

    draw(color, dataFlag) {
        fill(color);
        stroke(0);
        rect(this.x * scl, this.y * scl + gridY, scl, scl);
        if ( dataFlag ){
            textSize(20);
            fill(0);
            textAlign(LEFT);
            text(this.g, scl * (this.x + 1/10), scl * (this.y + 1/5) + gridY);
            textAlign(RIGHT);
            text(this.h, scl * (this.x + 9/10), scl * (this.y + 1/5) + gridY);
            textSize(30);
            textAlign(CENTER);
            text(this.f, scl * (this.x + 1/2), scl * (this.y + 2/3)  + gridY);
        }
    }

    print() {
        console.log(`x: ${this.x}, y: ${this.y}, f: ${this.f}`);
    }
}