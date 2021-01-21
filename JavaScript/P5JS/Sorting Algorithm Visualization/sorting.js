async function compare(a, b){
    await sleep(DELAY);

    compares++;
    return a-b;
}

async function swap(Arr, i, j){
    if ( i != j ){
        let temp = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = temp;

        swaps++;
    }
}

function sleep(ms){
    return new Promise(resolve => setTimeout(resolve, ms));
}