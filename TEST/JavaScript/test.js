let arr = [1, 2, 3, 4, 5];

arr.reduce((acc, curr, index) => {
    console.log(index)
    return acc + curr;
})
