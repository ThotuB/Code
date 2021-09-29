// shorthand notation
function getDate() {
    return {
        d: 'Monday', 
        m: 'September', 
        y: 2021
    }
}

function getTime() {
    return {
        h: 3, 
        m: 30
    }
}

let {d, m, y} = getDate()
console.log(`${d}-${m}-${y}`)

let {h: hr, m: min} = getTime()
console.log(`${hr}:${min}`)


// deep matching
function getTimeAndDate() {
    return {
        time: getTime(), 
        date: getDate()
    };
}

let {time: {h: hour, m: minute}, date: {d: day, m: month, y: year}} = getTimeAndDate();
console.log(`${hour}:${minute} ${day}-${month}-${year}`)


function getCatPic() {
    return {
        pic: 'cat.jpg',
        details: {
            name: 'Mittens',
            age: 2
        }
    }
}

let {pic, details: {name, age}} = getCatPic()
console.log(`${name} is ${age} years old: ${pic}`)



