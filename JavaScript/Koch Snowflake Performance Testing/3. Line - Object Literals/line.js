class KochLine {
    constructor(pointA, angle) {
        this.pointA = pointA;
        this.pointB = {x: 0, y: 0};
        
        this.angle = angle;

        this.update();
    }

    update() {
        this.pointB.x = this.pointA.x + length * cos(this.angle);
        this.pointB.y = this.pointA.y + length * sin(this.angle);
    }

    split(){
        this.update();

        let pointA2 = {x: this.pointB.x, y: this.pointB.y};
        let angle2 = this.angle - PI / 3;

        let line2 = new KochLine(pointA2, angle2);

        let pointA3 = {x: line2.pointB.x, y: line2.pointB.y};
        let angle3 = line2.angle + 2 * PI / 3;

        let line3 = new KochLine(pointA3, angle3);

        let pointA4 = {x: line3.pointB.x, y: line3.pointB.y};
        let angle4 = line3.angle - PI / 3;

        let line4 = new KochLine(pointA4, angle4);

        return [this, line2, line3, line4];
    }

    draw() {
        line(this.pointA.x, this.pointA.y, this.pointB.x, this.pointB.y);
    }
    
}