class KochCollection {
    constructor() {
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

    static split(Ax, Ay, Bx, By){
        let x1 =  Ax + (Bx - Ax) /3;
        let y1 =  Ay + (By - Ay) /3;

        let angle = KochCollection.calcAngle(Ax, Ay, Bx, By);
        let x2 = x1 + length * cos(angle - PI/3);
        let y2 = y1 + length * sin(angle - PI/3);

        let x3 =  Ax + (Bx - Ax) /3 * 2;
        let y3 =  Ay + (By - Ay) /3 * 2;

        return [[x1, x2, x3], [y1, y2, y3]];
    }

    static drawLine(x1, y1, x2, y2) {
        line(x1, y1, x2, y2);
    }
}