class Board{
    constructor(width, height, rows, cols, mines){
        this.cellW = width / cols;
        this.cellH = height / rows;

        this.rows = rows;
        this.cols = cols;

        this.flags = mines;
        this.mines = mines;

        this.board = create2DCellArray(rows, cols);
        this.drawTable();
        this.placeMines();
    }

    flag(y, x){
        if ( this.board[y][x].isRevealed ){
            return;
        }
        
        if ( this.board[y][x].isFlagged ) {
            this.flags++;
            this.board[y][x].drawReset(this.cellW, this.cellH);
        }
        else {
            if ( this.flags == 0 ){
                return;
            }
            this.flags--;
            this.board[y][x].drawFlag(this.cellW, this.cellH);
        }
        this.board[y][x].flag();
    }

    updateNeighbors(y, x){
        for (let i = y-1; i <= y+1; i++){
            for (let j = x-1; j <= x+1; j++){
                if ( i >= 0 && i < this.rows && j >= 0 && j < this.cols ){
                    if ( !this.board[i][j].isMine ){
                        this.board[i][j].inc();
                    }
                }
            }
        }
    }

    placeMines(){
        for (let i = 0; i < this.mines; ){
            let x = floor(random(0, this.cols - 1));
            let y = floor(random(0, this.rows - 1));
    
            if ( !this.board[y][x].isMine ){
                this.board[y][x].prime();
                this.updateNeighbors(y, x);
                i++;
            }
        }
    }

    fillAlg(y, x) {
        if ( x < 0 || x >= this.cols || y < 0 || y >= this.rows || this.board[y][x].isRevealed ){
            return;
        }
        this.board[y][x].draw(this.cellW, this.cellH);
        if ( !this.board[y][x].isEmpty ){
            return;
        }
    
        const dirX = [1, -1, 0, 0, 1, 1, -1, -1];
        const dirY = [0, 0, 1, -1, 1, -1, 1, -1];
        for (let i = 0; i < 8; i++){
            let x2 = x + dirX[i];
            let y2 = y + dirY[i];
    
            this.fillAlg(y2, x2);
        }
    }

    drawTable(){
        stroke(255);
        fill(0);
        for (let i = 0; i < this.rows; i++){
            for (let j = 0; j < this.cols; j++){
                let x = j * this.cellW;
                let y = i * this.cellH;
    
                rect(x, y, this.cellW, this.cellH);
            }
        }
    }

    // MOUSE EVENTS
    leftClick() {
        let x = floor(mouseX / this.cellW);
        let y = floor(mouseY / this.cellH);

        if ( !this.board[y][x].isFlagged ){
            if ( this.board[y][x].isMine ){
                this.board[y][x].drawMine(this.cellW, this.cellH);
            }
            else {
                this.fillAlg(y, x);
            }
        }
    }

    rightClick() {
        let x = floor(mouseX / this.cellW);
        let y = floor(mouseY / this.cellH);

        this.flag(y, x);
    }
}

function create2DCellArray(rows, cols){
    var a = [];
    for (var i = 0; i < rows; i++){
        a[i] = [];
        for (var j = 0; j < cols; j++){
            a[i][j] = new Cell(i, j);
        }
    }
    return a;
}