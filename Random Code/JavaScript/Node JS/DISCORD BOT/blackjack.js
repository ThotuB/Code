const SUITS = ["♠️", "♥️", "♣", "♦️"];
const NUMBS = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"];

/// ~ DECK CLASS ~

class Game {
    constructor(stream, players){
        this.deck = new Deck(stream);
        this.dealer = new Player(0, "Dealer");
        this.players = players;
    }

    draw(player){
        const card = this.deck.draw();

        player.cards.push(card);
    }
}

class Player {
    constructor(id, name){
        this.id = id;
        this.name = name;
        this.cards = [];
    }

    getCards(){
        printString = "";

        if ( this.cards.length == 0 ){
            printString = "\u200B";
        }
        else {
            for (var i in cards){
                printString += this.cards[i].toString();
            }
        }

        return printString;
    }
}

class Deck {
    size = 52;

    constructor(stream){
        if ( stream == "reset" ){
            this.reset();
        }
        else {
            this.fread(stream);
        }
    }

    reset(){
        this.cards = [];
        for (let i = 0 ; i < 4 ; i++){
            for (let j = 0 ; j < 13 ; j++){
                this.cards.push(new Card(i, j));
            }
        }
    }

    // Read Deck Data from Stream
    fread(streamIN){
        const fs = require("fs");

        var data = fs.readFileSync(streamIN, "utf8");

        this.cards = [];
        for (let i = 0 ; i < this.size ; i++){
            var suit = Number(data[4*i]);
            var numb = Number(data[4*i+1]) * 10 + Number(data[4*i+2]);
            this.cards.push(new Card(suit, numb));
        }
    }

    // Write Deck Data to Stream
    fwrite(streamOUT){
        const fs = require("fs");

        fs.writeFile(streamOUT, this.toDataString(), (err) => {
            if ( err ){
                return console.error(err);
            }
        });
    }

    // Shuffle Deck
    shuffle(){
        for (var indexCurr = this.size ; indexCurr !== 0 ; indexCurr--){
            var indexRand = Math.floor(Math.random() * indexCurr);

            var tempCard = this.cards[indexCurr-1];
            this.cards[indexCurr-1] = this.cards[indexRand];
            this.cards[indexRand] = tempCard;
        }
    }

    dealCard(){
        var card = this.cards.shift();
        this.size--;

        return card;
    }

    putCard(card){
        this.cards.push(card);
    }

    // Get Deck Data String
    toDataString(){
        var printString = "";

        for (let i = 0 ; i < this.size ; i++){
            printString += this.cards[i].toDataString() + "\n";
        }

        return printString;
    }

    // toString
    toString(){
        var printString = "";

        for (let i = 0 ; i < this.size ; i++){
            printString += this.cards[i].toString() + "\n";
        }

        return printString;
    }
}

/// ~ CARD CLASS ~

class Card {
    constructor(suit, number){
        this.suit = suit;
        this.number = number;
    }

    // Get Card Data
    toDataString(){
        var printString = this.suit + "";
        if ( this.number < 10 ){
            printString += "0";
        }
        printString += this.number;

        return printString;
    }

    // toString
    toString(){
        return NUMBS[this.number] + "" + SUITS[this.suit];
    }
}

module.exports = {
    Game: Game,
    Player: Player,
    Deck: Deck,
    Card: Card
}