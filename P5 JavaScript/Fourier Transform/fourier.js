function discrete_fourier_transform(x){
    let X = [];
    const N = x.length;

    for (let k = 0 ; k < N ; k++){
        let re = 0;
        let im = 0;

        for (let n = 0 ; n < N ; n++){
            let phi = (2*PI*k*n)/N;

            re += x[n] * cos(phi);
            im -= x[n] * sin(phi);
        }
        re /= N;
        im /= N;

        let freq = k;
        let ampl = sqrt(re*re + im*im);
        let phase = atan2(im, re) + HALF_PI;

        X[k] = {re, im, freq, ampl, phase};
    }

    return X;
}