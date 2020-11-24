const BJ = require("./blackjack.js");

const Discord = require("discord.js");
const client = new Discord.Client();

client.login("Nzc4Nzc2NjIzNTkwOTMyNTAx.X7W6QA.HpqLQeKTSbpy8C0slvlqAnZUG10");

client.on("ready", () => {
    console.log("Working!");
});

client.on("message", messageIN => {
    if ( messageIN.content.substring(0, 5) === "~play"){
        console.log(messageIN.mentions);

        messageIN.channel.send("playing Blackjack");
        play(messageIN);
    }
    console.log(messageIN);
});

/// ~~~~~ BLACKJACK FUNCTIONS ~~~~~

function get_players(messageIN){
    var players = [];

    players.push(new BJ.Player(messageIN.author.id, messageIN.author.username));

    const itKeys = messageIN.mentions.users.values();

    for (var i = 0 ; i < messageIN.mentions.users.size && i < 7 ; i++){
        var user = itKeys.next().value;
        var userID = user.id;
        var userName = user.username;

        if ( user.constructor.name == "User" ){
            if ( players.indexOf(userID) == -1 ){
                players.push(new BJ.Player(userID, userName));
            }
        }
    }

    return players;
}

function get_embed(game){
    var embed = new Discord.MessageEmbed()
        .setColor("#663399")
        .setTitle("Blackjack")
        .addFields(
            { name: "Dealer", value: "6R" },
            { name: "\u200B", value: "\u200B"}
        );

    // for (var i = 0 ; i < game.players.length ; i++){
    //     var name = new String(game.players[i].name);
    //     console.log(game.players.getCards());

    //     embed.addField(name, value, false);
    // }

    return embed;
}

function play(messageIN){
    console.log("Playing blackjack");
    const channel = messageIN.channel;

    var players = get_players(messageIN);

    game = new BJ.Game("data.txt", players);

    var messageOUT = get_embed(game);
    channel.send(messageOUT);

    console.log(game);
}

