class Button {
    constructor(x, y, w, h, text, callback, ...args) {
        this.boundry = new Boundary(x, y, w, h);

        this.text = text;

        this.callback = callback;
        this.args = args;

        this.hover = false;
        this.pressed = false;
    }

    update() {
        if ( this.boundry.mouseOver() ) {
            this.hover = true;
        }
        else {
            this.hover = false;
        }
    }
    action() {
        this.callback(this.args);
    }

    getColor() {
        if ( this.pressed ) {
            return color(255, 0, 0);
        }
        if ( this.hover ) {
            return color(0, 255, 0);
        }
        return color(0, 0, 255);
    }

    draw() {
        let color = this.getColor();
        this.boundry.draw(color);
        this.boundry.drawText(this.text);
    }
}