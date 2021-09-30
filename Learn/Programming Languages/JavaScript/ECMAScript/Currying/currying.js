// shortened version
let plot =
    coordX =>
        coordY =>
            coordZ =>
                `(${coordX}, ${coordY}, ${coordZ})`

console.log(plot(1)(2)(3))

// expanded version
function plotExpanded(coordX) {
    return function(coordY) {
        return function(coordZ) {
            return `(${coordX}, ${coordY}, ${coordZ})`
        }
    }
}

console.log(plotExpanded(1)(2)(3))


let plot00 = plot(0)(0)
console.log(plot00(0))
console.log(plot00(1))
console.log(plot00(2))

