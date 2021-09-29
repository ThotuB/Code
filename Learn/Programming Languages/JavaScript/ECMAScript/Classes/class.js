class Shape {
    constructor(index, color) {
        this.index = index;
        this.color = color;
    }

    get color() { return this._color; }
    set color(value) { this._color = value; }
}

class Rectangle extends Shape {
    constructor(index, color, width, height) {
        super(index, color);
        this.width = width;
        this.height = height;
    }

    get width() { return this._width; }
    set width(value) { this._width = value; }

    get height() { return this._height; }
    set height(value) { this._height = value; }

    get area() { return this._width * this._height; }

    static defaultRectangle() {
        return new Rectangle(0, "red", 1, 1);
    }
}


let rect = new Rectangle(1, "red", 2, 3);
console.log(rect)

rect.color = "blue";
rect.height = 4;
console.log(rect)
console.log(rect.area)