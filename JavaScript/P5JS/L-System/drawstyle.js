// Style 1 Vars
let countF;
let colorJmp = 1;

function SetupStyles() {
    countF = rule["F"].split('').reduce( (acc, char) => {
        return acc + (char === 'F'); 
    }, 0);
}

function Style1(text){
    strokeWeight(5);
    background(0);
    push();

    colorJmp = 240 / Math.pow(countF, iter);
    let color = 255;
    for (let i = 0 ; i < text.length ; i++){
        stroke(color, color, color);

        switch (text[i]){
            case "F":
                line(0, 0, 0, -len);
                translate(0, -len);
                color -= colorJmp;
                break;
            case "+":
                rotate(angle);
                break;
            case "-":
                rotate(-angle);
                break;
            case "[":
                push();
                break;
            case "]":
                pop();
                break;
        }
    }
    pop();
}

function Style2(text) {
    strokeWeight(5);
    background(0);
    push();

    let color;
    let colors = [125];
    let cnt = 0;
    for (let i = 0 ; i < text.length ; i++){
        color = colors[cnt];
        stroke(color, color, color);

        switch (text[i]){
            case "F":
                line(0, 0, 0, -len);
                translate(0, -len);
                break;
            case "+":
                colors[cnt] += 10;
                rotate(angle);
                break;
            case "-":
                colors[cnt] -= 10;
                rotate(-angle);
                break;
            case "[":
                colors.push(color);
                cnt++;
                push();
                break;
            case "]":
                colors.pop();
                cnt--;
                pop();
                break;
        }
    }
    pop();
}