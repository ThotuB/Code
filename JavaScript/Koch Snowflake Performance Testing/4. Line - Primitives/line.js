class KochLine {
    constructor(x, y, angle) {
        this.Ax = x;
        this.Ay = y;
        this.Bx = 0;
        this.By = 0;
        
        this.angle = angle;

        this.update();
    }

    update() {
        this.Bx = this.Ax + length * cos(this.angle);
        this.By = this.Ay + length * sin(this.angle);
    }

    split(){
        this.update();

        let A2x = this.Bx;
        let A2y = this.By;
        let angle2 = this.angle - PI / 3;

        let line2 = new KochLine(A2x, A2y, angle2);

        let A3x = line2.Bx;
        let A3y = line2.By;
        let angle3 = line2.angle + 2 * PI / 3;

        let line3 = new KochLine(A3x, A3y, angle3);

        let A4x = line3.Bx;
        let A4y = line3.By;
        let angle4 = line3.angle - PI / 3;

        let line4 = new KochLine(A4x, A4y, angle4);

        return [this, line2, line3, line4];
    }

    draw() {
        line(this.Ax, this.Ay, this.Bx, this.By);
    }
    
}