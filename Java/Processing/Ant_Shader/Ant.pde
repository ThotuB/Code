float scaleToRange01(long state) {
    float newState = state / 4294967295.0;

    return newState;
}

class Ant {
    PVector position;
    float angle;

    void update(){
        long random = hash(this.position.y * width + this.position.x);

        PVector direction = new PVector(cos(this.angle), sin(this.angle));
        PVector newPos = this.position + direction * moveSpeed * deltaTime;

        if ( newPos.x < 0 || newPos.x >= width || newPos.y < 0 || newPos.y >= height ){
            newPos.x = min(width-1, max(0, newPos.x));
            newPos.y = min(height-1, max(0, newPos.y));
            this.angle = scaleToRange01(random) * 2 * PI;
        }

        this.position = newPos;
    }
}
