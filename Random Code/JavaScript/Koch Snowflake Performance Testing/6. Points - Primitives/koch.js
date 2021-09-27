class KochPoint {
    constructor(x, y, angle) {
        this.x = x;
        this.y = y;
        this.angle = angle;
    }

    static split(pointA, pointB){
        let x1 =  pointA.x + (pointB.x - pointA.x) /3;
        let y1 =  pointA.y + (pointB.y - pointA.y) /3;

        let x2 = x1 + length * cos(pointA.angle - PI/3);
        let y2 = y1 + length * sin(pointA.angle - PI/3);

        let x3 =  pointA.x + (pointB.x - pointA.x) /3 * 2;
        let y3 =  pointA.y + (pointB.y - pointA.y) /3 * 2;

        let point1 = new KochPoint(x1, y1, pointA.angle - PI/3);
        let point2 = new KochPoint(x2, y2, pointA.angle + PI/3);
        let point3 = new KochPoint(x3, y3, pointA.angle);

        return [point1, point2, point3];
    }

    drawLine(point) {
        line(this.x, this.y, point.x, point.y);
    }
}