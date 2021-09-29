class Boundary {
    constructor(x, y, width, height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    mouseOver() {
        return (mouseX > this.x && mouseX < this.x + this.width && mouseY > this.y && mouseY < this.y + this.height);
    }

    draw(color) {
        fill(color);
        rect(this.x, this.y, this.width, this.height);
    }

    drawText(txt) {
        fill(255);
        textSize(20);
        textAlign(CENTER, CENTER)
        text(txt, this.x + this.width / 2, this.y + this.height / 2);
    }
}