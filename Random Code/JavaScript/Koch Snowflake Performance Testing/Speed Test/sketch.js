function setup() {
    let ITER_MAX = 1000000;
    let timer = millis();

    for (let i = 0; i < ITER_MAX; i++) {
        let x = i + (434.34643262 - 432.654364364) / 3;
    }

    console.log("" + (millis() - timer));
    timer = millis();

    for (let i = 0; i < ITER_MAX; i++) {
        let y = cos(1.5);
    }

    console.log("" + (millis() - timer));
}