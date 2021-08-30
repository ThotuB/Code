class KochCollection {
    constructor() {
        this.length = 2;
        this.xs = [];
        this.ys = [];

        this.setup();
    }

    setup() {
        this.xs[0]= x; 
        this.ys[0] = height/2;

        this.xs[1] = x + length;
        this.ys[1] = height/2;
    }

    static calcAngle(x1, y1, x2, y2) {
        return atan2(y2 - y1, x2 - x1);
    }

    split(Ax, Ay, Bx, By, index){
        let angle = KochCollection.calcAngle(Ax, Ay, Bx, By);

        let x1 =  Ax + length * cos(angle);
        let y1 =  Ay + length * sin(angle);

        let x2 = x1 + length * cos(angle - PI/3);
        let y2 = y1 + length * sin(angle - PI/3);

        let x3 =  x2 + length * cos(angle + PI/3);
        let y3 =  y2 + length * sin(angle + PI/3);

        this.xs.splice(index+1, 0, ...[x1, x2, x3]);
        this.ys.splice(index+1, 0, ...[y1, y2, y3]);

        this.length += 3;
    }

    static drawLine(x1, y1, x2, y2) {
        line(x1, y1, x2, y2);
    }
}