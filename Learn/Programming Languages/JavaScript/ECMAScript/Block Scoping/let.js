function matrix(){
    let output = ""

    let i = 0;
    while (i < 10) {
        output += `${i}: `
        let j = 0;
        while (j < 10) {
            let i = 10;
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