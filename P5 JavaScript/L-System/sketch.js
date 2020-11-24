let rule = [];
let sentance = "F";

let len = 340;
let angle = PI/6

function setup(){
    createCanvas(2000, 2000);

    rule["F"] = "FF+[+F-F-F]-[-F+F-[+F++F]-F]";

    var button = createButton("*");
    createP(sentance);
    button.mousePressed( function() {
        len /= 2;
        sentance = L_System(sentance, 1);
    } );
}

function L_System(text, iter){
    if ( iter == 0){
        //sentance = text;
        return text;
    }
    else {
        let textNext = "";
        let textLen = text.length;

        for (let i = 0 ; i < textLen ; i++){
            if ( rule[text[i]] != undefined ){
                textNext += rule[text[i]];
            }
            else {
                textNext += text[i];
            }
        }

        //createP(textNext);

        return L_System(textNext, iter - 1);
    }
}

function textToLines(text){
    stroke(255);
    for (let i = 0 ; i < text.length ; i++){
        let c = text[i];

        switch (c){
            case "F":
                line(0, 0, 0, -len);
                translate(0, -len);
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
}

function draw(){
    background(0);
    translate(1000, 1950);

    textToLines(sentance);
}