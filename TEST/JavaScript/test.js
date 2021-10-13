let lst = [1, 2, 3, 4, 5, 1, 1, 2, 4];

let lst2 = lst.reduce((acc, elem) => {
    if ( acc[elem] == undefined ) {
        acc[elem] = 1;
    } else {
        acc[elem]++;
    }
    return acc;
}, {});

console.log(lst2)