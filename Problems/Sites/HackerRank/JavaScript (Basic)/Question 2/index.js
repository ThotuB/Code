function dataFinder(data) {
    const find = (minRange, maxRange, value) => {
        if ( minRange < 0 || maxRange > data.length - 1 || minRange > maxRange ) {
            throw new Error('Invalid range');
        }

        for (let i = minRange ; i <= maxRange ; i++) {
            if (data[i] === value) {
                return true;
            }
        }
        return false;
    }

    return find;
}

let data = [1, 6, 3, 0, 2, 15, 10];
let finder = dataFinder(data);

console.log(finder(2, 4, 10));
