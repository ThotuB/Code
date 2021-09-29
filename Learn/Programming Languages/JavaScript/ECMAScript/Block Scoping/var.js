function matrix(){
    let output = ""

    var i = 0;
    while (i < 10) {
        output += `${i}: `
        var j = 0;
        while (j < 10) {
            var i = 10;
            output += `${j} `
            i++;
            j++;
        }
        i++;
        output += "\n"
    }

    return output;
}

console.log(matrix());