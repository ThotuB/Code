int resolution = 1;

int iterMax = 100;
int colorDelta;

float startR;
float startG;
float startB;

ArrayList<Color> colors = new ArrayList<Color>();

void setup() {
    size(1200, 1200, P3D);

    startR = findColorInNoise(123, 0);
    System.out.println(startR + " -  " + (noise(startR) * 255));
    startG = 70;
    startB = findColorInNoise(210, 1000);
    System.out.println(startB + " - " + (noise(startB) * 255));


    colors.add(new Color(0, 0, 0));
    generateColors(iterMax);
    drawMandelbrot();
}

void draw() {
}

void mousePressed() {
    switch ( mouseButton ){
        case LEFT:
            iterMax++;
            drawMandelbrot();
            break;
    }
}

void drawMandelbrot() {
    loadPixels();
    for (int i = 0 ; i < height ; i+=resolution) {
        for (int j = 0 ; j < width ; j+=resolution) {
            int x = j - width/2;
            int y = height/2 - i;

            float xCoord = map(x, -width/2, width/2, -2, 1);
            float yCoord = map(y, -height/2, height/2, -1.5, 1.5);

            int iterFail = Mandelbrot.compute(new Complex(xCoord, yCoord), iterMax, 2);
            
            int index = i * width + j;
            if ( iterFail == -1 ) {
                pixels[index] = color(0, 0, 0);
                continue;
            }
            Color c = colors.get(iterFail);
            pixels[index] = color(c.r, c.g, c.b);
            
            //if (millis() % 100 == 0){
            //    System.out.println("Progress: " + (((float)index)/(width * height) * 100) + "%");
            //}
        }
    }
    updatePixels();
}

void generateColors(int size){
    for (int i = 0 ; i < size ; i++) {
        colors.add(new Color(noise(i * 0.05f + startR) * 255, startG, noise(i * 0.05f + startB) * 255));
    }
}

float findColorInNoise(int val, int off) {
    float valFound;
    int x = off;

    do {
        valFound = noise(x * 0.01f) * 255;
        x++;
    }while ( abs(val - valFound) > 1 );

    return x * 0.01f;
}
