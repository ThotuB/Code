function compute(dimensions) {
    let point = []
    for (let n = 0; n < dimensions; n++) {
        point.push(Math.random())
    }
    return point
}

var [x=0, y=0, z=0] = compute(2)
console.log(x, y, z)