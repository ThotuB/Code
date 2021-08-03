let rule = [];
rule["F"] = "FFF";
let sentance = "F";

let iter = 0;
let len = 400;
let angle = Math.PI/12

let DrawLines = [];
let style = 0;

let systemSentances = [];

function setup(){
    createCanvas(2000, 2000);
    background(0);
    translate(width / 2, height - 50);

    SetupStyles();
    DrawLines = [Style1, Style2];
    
    Reset();
}

function Reset(){
    sentance="F";
    iter = 0;
    len = 400;

    systemSentances = ["F"];
    PrintSentances();
    DrawLines[style](sentance);
}

function SetRule(){
    Reset();

    let ruleInput = select("#rule");
    let ruleText = select("#ruleText");

    rule["F"] = ruleInput.value();
    SetupStyles();
    ruleText.html(ruleInput.value());
}

function ChoseStyle(s){
    style = s;
    DrawLines[style](sentance);
}

function PrintSentances() {
    for (let i = 0 ; i <= iter ; i++){
        print(systemSentances[i]);
    }
}

function Iterate() {
    sentance = L_System(sentance);
    iter++;

    systemSentances[iter] = sentance;
    PrintSentances();

    DrawLines[style](sentance);
}

function L_System(text){
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

    len /= 2;

    return textNext;
}