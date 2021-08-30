function visualizeHeap(fileText){
    let heap = fileText[0].split(" ");
    heap.pop();
    let heapH = floor(Math.log2(heap.length)) + 1;

    let Ydiff = height / (heapH + 1);
    let d = width / (pow(2, heapH - 1) + 1);

    visualizeHeapDivide(heap, 0, 0, width, 1, Ydiff, d);
}

function visualizeHeapDivide(heap, index, xleft, xright, row, yDiff, d) {
    settings(d);

    let x = (xleft + xright) / 2;
    let y = yDiff * row;
    
    ellipse(x, y, d);
    text(heap[index], x, row * yDiff);

    if ( index*2 + 1 < heap.length ){
        let xNext = (xleft + x) / 2;
        let yNext = yDiff * (row + 1);
        line(x, y + d/2, xNext, yNext - d/2);

        visualizeHeapDivide(heap, index * 2 + 1, xleft, x, row + 1, yDiff, d);
    }
    if ( index*2 + 2 < heap.length ){
        let xNext = (x + xright) / 2;
        let yNext = yDiff * (row + 1);
        line(x, y + d/2, xNext, yNext - d/2);

        visualizeHeapDivide(heap, index * 2 + 2, x, xright, row + 1, yDiff, d);
    }
}

function settings(diameter) {
    textSize(diameter / 2);
    stroke(255);
    textStyle(BOLD);
    textAlign(CENTER, CENTER);
}