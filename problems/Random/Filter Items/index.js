let nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

function isPrime(num) {
    if ( num < 2 ) return false;
    if ( num === 2 ) return true;
    if ( num % 2 === 0 ) return false;
    for ( let i = 3; i <= Math.sqrt(num); i += 2 ) {
        if ( num % i === 0 ) return false;
    }
    return true;
}

function filterNums(fn, nums) {
    
}