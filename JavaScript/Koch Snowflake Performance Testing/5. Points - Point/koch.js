class KochPoint {
    constructor(point, angle) {
        this.pos = point;
        this.angle = angle;
    }

    static split(pointA, pointB){
        let x1 =  pointA.pos.x + (pointB.pos.x - pointA.pos.x) /3;
        let y1 =  pointA.pos.y + (pointB.pos.y - pointA.pos.y) /3;

        let x2 = x1 + length * cos(pointA.angle - PI/3);
        let y2 = y1 + length * sin(pointA.angle - PI/3);

        let x3 =  pointA.pos.x + (pointB.pos.x - pointA.pos.x) /3 * 2;
        let y3 =  pointA.pos.y + (pointB.pos.y - pointA.pos.y) /3 * 2;

        let point1 = new KochPoint(new Point(x1, y1), pointA.angle - PI/3);
        let point2 = new KochPoint(new Point(x2, y2), pointA.angle + PI/3);
        let point3 = new KochPoint(new Point(x3, y3), pointA.angle);

        return [point1, point2, point3];
    }

    drawLine(point) {
        line(this.pos.x, this.pos.y, point.pos.x, point.pos.y);
    }
}