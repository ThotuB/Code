public class Mandelbrot {
    static int compute(Complex c, int iterMax, int magMax){
        Complex z = c;

        for (int i = 0; i < iterMax; i++) {
            z = iterate(z, c);
            
            if ( z.mag() > magMax) {
                return i;
            }
        }

        return -1;
    }

    static Complex iterate(Complex z, Complex c) {
        Complex z2 = Complex.mult(z, z);
        z2.add(c);

        return z2;
    }
}
