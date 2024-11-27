const arr = [
    "1324",
    "1325",
    "1326",
    "1327",
    "",
    "1329",
    "1330",
    "1331",
    "",
    "1333",
    "1334",
    "1335",
    "1336",
    "1337",
    "1338",
    "",
    "1340",
    "1341",
]

// split the array into chunks at the empty strings
const arr2 = arr.reduce((acc, val) => {
    if (val === "") {
        acc.push([])
    } else {
        acc[acc.length - 1].push(val)
    }
    return acc
}, [[]])

arr2