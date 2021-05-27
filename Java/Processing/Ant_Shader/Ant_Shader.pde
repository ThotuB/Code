long hash(long state){
    state ^= 2747652419L;
    state *= 2654435769L;
    state ^= state >> 16;
    state *= 2654435769L;
    state ^= state >> 16;
    state *= 2654435769L;

    return state;
}

void random_test(int width, int height){
    for (int i = 0 ; i < width ; i++){
        for (int j = 0 ; j < height ; j++){
            long pixelIndex = j * width + i;

            long pseudoRandomNr = hash(pixelIndex);

            loadPixels();
            pixels[(int)pixelIndex] = color(pseudoRandomNr/4294967295L);
            updatePixels();
        }
    }
}

void setup(){
    size(300, 300);
    background(0);
    random_test(300, 300);
}

void draw(){
}