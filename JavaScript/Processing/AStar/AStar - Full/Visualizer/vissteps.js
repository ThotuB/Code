let steps = [];

class Step {
    constructor(node, type) {
        this.node = node;

        this.type = type;
    }

    draw() {
        switch ( this.type ) {
            case 'active':
                this.node.draw(color(255, 0, 255));
                break;
            case 'peek':
                this.node.draw(color(0, 100, 200));
                break;
        }
    }
}