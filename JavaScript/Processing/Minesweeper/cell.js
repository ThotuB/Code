class Cell{
    constructor(y, x){
        this.y = y;
        this.x = x;

        this.isMine = false;
        this.isRevealed = false;
        this.isFlagged = false;
        
        this.isEmpty = true;
        this.adjacentMines = 0;
    }

    get(){
        return this.adjacentMines;
    }

    prime() {
        this.isMine = true;
    }

    flag() {
        this.isFlagged = !this.isFlagged;
    }

    reveal() {
        this.isRevealed = true;
    }

    inc() {
        this.adjacentMines++;
        this.isEmpty = false;
    }

    drawReset(w, h) {
        fill(0);
        stroke(255);
        rect(this.x * w, this.y * h, w, h);
    }

    drawFlag(w, h){
        fill(255);
        stroke(255);
        rect(w * (this.x  + 0.1), h * (this.y  + 0.1), w * 0.7, h * 0.3);
        rect(w * (this.x + 0.8), h * (this.y + 0.1), w * 0.1,  h * 0.8);
    }

    drawMine(w, h){
        this.reveal();
        fill(255, 0, 0);
        stroke(0);
        rect(this.x * w, this.y * h, w, h);
    }

    draw(w, h) {
        this.reveal();
        fill(255);
        stroke(0);
        rect(this.x * w, this.y * h, w, h);

        if ( !this.isEmpty ) {
            stroke(0);
            fill(0);
            textAlign(CENTER, CENTER);
            textSize(64);
            text(this.adjacentMines.toString(), this.x * w + w/2, this.y * h + h/2);
        }

    }
}