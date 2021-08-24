class Koch {
    static split(Ax, Ay, Bx, By, angle){
        let x1 =  Ax + (Bx - Ax) /3;
        let y1 =  Ay + (By - Ay) /3;
        let angle1 = angle - PI/3;

        let x2 = x1 + length * cos(angle - PI/3);
        let y2 = y1 + length * sin(angle - PI/3);
        let angle2 = angle + PI/3;

        let x3 =  Ax + (Bx - Ax) /3 * 2;
        let y3 =  Ay + (By - Ay) /3 * 2;
        let angle3 = angle;

        return [[x1, x2, x3], [y1, y2, y3], [angle1, angle2, angle3]];
    }

    static drawLine(x1, y1, x2, y2) {
        line(x1, y1, x2, y2);
    }
}