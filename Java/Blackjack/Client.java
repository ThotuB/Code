import java.util.ArrayList;
import java.util.Scanner;

class T {
    public static String ab(int tabs){
        String printTabs = "";
        for (int i = 0 ; i < tabs ; i++){
            printTabs += "\t";
        }
        return printTabs;
    }
}
/// ~~~~~~~~~~~~ BLACKJACK ~~~~~~~~~~~~

class Game {
    private Deck deck;
    private Deck discard;

    private Player dealer;
    private ArrayList<Player> players;

    public Game(ArrayList<Player> players, int nrDecks){
        this.deck = new Deck(nrDecks);
        this.discard = new Deck(0);

        this.dealer = new Player("0", "Dealer", 42);
        this.players = players;
    }
    
    public Game(ArrayList<Player> players){
        this(players, 1);
    }

    // GETTERS
    public Deck getDeck(){
        return this.deck;
    }

    public Player getDealer(){
        return this.dealer;
    }

    public Player getPlayer(int index){
        if ( index >= 0 && index < this.players.size() ){
            return this.players.get(index);
        }
        return null;
    }

    public ArrayList<Player> getPlayers(){
        return this.players;
    }

    // AUTO MOVES
    public void deal(){
        for (int i = 0 ; i < 2 ; i++){
            for (Player p: players){
                p.deal(this.deck);
            }
            this.dealer.deal(this.deck);
        }
        this.dealer.hideCard(0);
        for (Player p: players){
            p.state();
        }
        this.dealer.state();
    }

    public void discard(){
        for (Player p: players){
            this.discardPlayer(p);
        }
        this.discardPlayer(this.dealer);
    }

    // PLAYER MOVES
    public void dealPlayer(Player player){
        player.deal(this.deck);
        player.state();
    }

    public boolean doubledownPlayer(Player player){
        if ( player.doubledown() ){
            dealPlayer(player);
            if ( !player.isBust() ){
                player.stand();
            }
            return true;
        }
        return false; 
    }

    public void standPlayer(Player player){
        player.stand();
    }

    public void discardPlayer(Player player){
        for (Card c: player.getHand()){
            this.discard.add(c);
        }
        player.discard();
    }

    // TOSTRING()
    public String toObjectString(int t){
        String printString = T.ab(t) + "Game {\n";
        printString += deck.toObjectString(t+1) + "\n";
        printString += discard.toObjectString(t+1) + "\n";
        printString += dealer.toObjectString(t+1) + "\n";
        for (Player p: players){
            printString += p.toObjectString(t+1) + "\n";
        }
        printString += T.ab(t) + "}";

        return printString;
    }
}

class Player {
    private String id;
    private String name;
    private int money;
    private int bet;

    private ArrayList<Card> hand;
    private int points;

    private boolean hiddenCardFlag;
    private boolean softAceFlag;

    private boolean blackjackFlag;
    private boolean standFlag;
    private boolean bustFlag;

    Player(String id, String name, int money){
        this.id = id;
        this.name = name;
        this.money = money;
        this.bet = 0;

        this.hand = new ArrayList<Card>();;
        this.points = 0;

        this.hiddenCardFlag = false;
        this.softAceFlag = false;

        this.standFlag = false;
        this.bustFlag = false;
    }

    // GETTERS
    public String getName(){
        return this.name;
    }

    public ArrayList<Card> getHand(){
        return this.hand;
    }

    public int getPoints(){
        return this.points;
    }
    
    public boolean hasBlackjack(){
        return this.blackjackFlag;
    }

    public boolean isStand(){
        return this.standFlag;
    }

    public boolean isBust(){
        return this.bustFlag;
    }

    // AUTO FUNCTIONS
    public void state(){
        if ( this.points == 21 ){
            this.blackjackFlag = true;
        }
        else if ( this.points > 21 ){
            if ( !this.softAceFlag ){
                this.bust();
            }
            else {
                this.points -= 10;
                this.softAceFlag = false;
            }
        }
    }

    public void discard(){
        this.hand.clear();
        this.points = 0;
        this.bet = 0;

        this.hiddenCardFlag = false;
        this.softAceFlag = false;

        this.blackjackFlag = false;
        this.standFlag = false;
        this.bustFlag = false;
    }

    // MANUAL FUNCTIONS
    public void deal(Deck deck){
        Card card = deck.draw();
    
        this.hand.add(card);
        this.points += card.getValue();

        if ( card.getValue() == 11 ){
            this.softAceFlag = true;
        }
    }

    // CARD FUNCTIONS
    public void hideCard(int index){
        Card card = this.hand.get(index);

        card.hide();
        this.points -= card.getValue();
        // TODO: Handle softAceFlag if value == 11
        this.hiddenCardFlag = true;
    }

    public void showCard(int index){
        Card card = this.hand.get(index);

        card.show();
        this.points += card.getValue();
        // TODO: Handle softAceFlag if value == 11
        this.hiddenCardFlag = false;
    }

    // PLAYER MOVES
    public boolean bet(int bet){
        if ( bet <= this.money ){
            if ( bet % 2 == 0 && bet > 0 ){
                this.money -= bet;
                this.bet = bet;

                return true;
            }
        }
        return false;
    }

    public boolean doubledown(){
        if ( this.bet <= this.money ){
            this.money -= this.bet;
            this.bet *= 2;

            return true;
        }
        return false;
    }

    public void stand(){
        this.standFlag = true;
    }

    public void bust(){
        this.bustFlag = true;
    }

    public void payout(double multiplier){
        this.money += this.bet + (int)Math.round(this.bet * multiplier);
        this.bet = 0;
    }

    // TOSTRING()
    public String toObjectString(int t){
        String printString = T.ab(t) + "Player {\n";
        printString += T.ab(t+1) + "id: " + this.id + "\n";
        printString += T.ab(t+1) + "name: " + this.name + "\n";
        printString += T.ab(t+1) + "money: " + this.money + "\n";
        printString += T.ab(t+1) + "bet: " + this.bet + "\n";
        printString += T.ab(t+1) + "Hand {" + "\n";
        for (Card c: hand){
            printString += c.toObjectString(t+2) + "\n";
        }
        printString += T.ab(t+1) + "}\n";
        printString += T.ab(t+1) + "points: " + this.points;
        if ( this.hiddenCardFlag ){
            printString += "?";
        }
        printString += "\n";
        printString += T.ab(t+1) + "blackjackFlag: " + this.blackjackFlag + "\n";
        printString += T.ab(t+1) + "standFlag: " + this.standFlag + "\n";
        printString += T.ab(t+1) + "bustFlag: " + this.bustFlag + "\n";
        printString += T.ab(t) + "}";

        return printString;
    }
}

class Deck {
    private int size;
    private ArrayList <Card> cards;

    public Deck(int nrDecks){
        this.cards = new ArrayList<Card>();
        this.reset(nrDecks);
    }

    // AUTO FUNCTIONS
    public void reset(int nrDecks){
        this.cards.clear();
        for (int k = 0 ; k < nrDecks ; k++){
            for (int i = 0 ; i < 4 ; i++){
                for (int j = 0 ; j < 13 ; j++){
                    this.cards.add(new Card(i, j));
                }
            }
        }  
        this.size = this.cards.size();
    }

    public void shuffle(){
        for (int indexCurr = this.size ; indexCurr != 0 ; indexCurr--){
            int indexRand = (int)Math.floor(Math.random() * indexCurr);

            Card tempCard = this.cards.get(indexCurr-1);
            this.cards.set(indexCurr-1, this.cards.get(indexRand));
            this.cards.set(indexRand, tempCard);
        }
    }

    public Card draw(){
        Card card = this.cards.get(0);

        this.cards.remove(0);
        this.size = this.cards.size();

        return card;
    }

    public void add(Card card){
        this.cards.add(card);
        this.size = this.cards.size();
    }

    // TOSTRING()
    public String toObjectString(int t){
        var printString = T.ab(t) + "Deck {\n";
        printString += T.ab(t+1) + "size: " + this.size + "\n";
        for (Card c: this.cards){
            printString += c.toObjectString(t+1) + "\n";
        }
        printString += T.ab(t) + "}";

        return printString;
    }
}

class Card {
    private static final String[] SUITS = {"♠️", "♥️", "♣", "♦️"};
    private static final String[] NUMBS = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    private int suit;
    private int number;

    private boolean hiddenFlag;

    public Card(int suit, int number, boolean hidden){
        this.suit = suit;
        this.number = number;
        this.hiddenFlag = hidden;
    }

    public Card(int suit, int number){
        this(suit, number, false);
    }

    // GETTERS
    public int getValue(){
        if (this.number == 0){
            return 11;
        }
        if ( this.number > 9 ){
            return 10;
        }
        return this.number + 1;
    }

    public boolean isHidden(){
        return this.hiddenFlag;
    }

    // FUNCTIONS
    public void hide(){
        this.hiddenFlag = true;
    }

    public void show(){
        this.hiddenFlag = false;
    }

    // TOSTRING()
    public String toObjectString(int t){
        String printString = T.ab(t) + "Card { ";
        if ( this.hiddenFlag ){
            printString += "number: " + "?" + " suit: " + "?" + " }";
        }
        else {
            printString += "number: " + NUMBS[this.number] + " suit: " + SUITS[this.suit] + " }";
        }

        return printString;
    }
}

class Client {
    public static void placeBet(Player player, Scanner scan){
        System.out.print(player.getName() + "'s bet: ");
        int bet = scan.nextInt();

        if ( !player.bet(bet) ){
            System.out.println("Invalid bet amount!");
            Client.placeBet(player, scan);
        }
        else {
            scan.nextLine();
        }
    }

    public static void manualdeal(Game game, Player player, Scanner scan){
        int move = 1;
        while ( !player.isBust() && !player.isStand() && !player.hasBlackjack() )
        {
            System.out.print(player.getName() + ": ");
            String option = scan.nextLine();

            if ( option.equalsIgnoreCase("double") ){
                if ( move == 1 ){
                    if ( !game.doubledownPlayer(player) ){
                        System.out.println("Can't Double Down!");
                        continue;
                    }
                }
                else {
                    continue;
                }
            }
            else if ( option.equalsIgnoreCase("hit") ){
                game.dealPlayer(player);
            }
            else if ( option.equalsIgnoreCase("stand") ){
                game.standPlayer(player);
            }
            else {
                continue;
            }

            move++;
            System.out.println(game.toObjectString(0));
        }
    }

    public static void autodeal(Game game, Player player, int standPoints){
        while ( !player.isBust() && !player.isStand() && !player.hasBlackjack() )
        {
            System.out.print(player.getName() + ": ");

            if ( player.getPoints() < standPoints ){
                System.out.println("Hit");
                game.dealPlayer(player);
            }
            else {
                System.out.println("Stand");
                game.standPlayer(player);
            }

            System.out.println(game.toObjectString(0));
        }
    }

    public static void payout(Player player, Player dealer){
        System.out.print(player.getName() + ": ");
        String outcome;
        double multi;

        if ( player.isBust() ){
            outcome = "BUST"; multi = 0;
        }
        else if ( player.isStand() ){
            if ( dealer.hasBlackjack() ){
                outcome = "LOSS"; multi = 0;
            }
            else if ( dealer.isStand() ){
                if ( player.getPoints() < dealer.getPoints() ){
                    outcome = "BUST"; multi = 0;
                }
                else if ( player.getPoints() == dealer.getPoints() ){
                    outcome = "PUSH"; multi = 1;
                }
                else {
                    outcome = "WIN"; multi = 2;
                }
            }
            else {
                outcome = "WIN"; multi = 2;
            }
        }
        else if ( player.hasBlackjack() ){
            if ( dealer.hasBlackjack() ){
                outcome = "PUSH"; multi = 1;
            }
            else {
                outcome = "BLACKJACK"; multi = 2.5;
            }
        }
        else {
            outcome = "HOW DID YOU GET HERE?"; multi = 100;
        }
        
        player.payout(multi);
        System.out.println(outcome + " x" + multi);
    }
    public static void main(String[] args){
        ArrayList<Player> playerArr = new ArrayList<Player>();
        playerArr.add(new Player("42324", "Thotu", 100));
        playerArr.add(new Player("43324", "Fake Thotu", 100));

        Game game = new Game(playerArr);

        game.getDeck().shuffle();

        Scanner scan = new Scanner(System.in);

        boolean goNext = true;

        while ( goNext ){
            // ROUND START
            game.deal();
            System.out.println(game.toObjectString(0));

            // BETS
            for (Player player : game.getPlayers())
            {
                Client.placeBet(player, scan);
            }

            // PLAYERS' TURNS
            for (Player player : game.getPlayers())
            {
                Client.manualdeal(game, player, scan);
            }

            // DEALER'S TURN
            Player dealer = game.getDealer();

            dealer.showCard(0);
            System.out.println(game.toObjectString(0));

            Client.autodeal(game, dealer, 17);

            // PAYOUT
            for (Player player : game.getPlayers())
            {
                payout(player, dealer);
            }
            
            // ROUND END
            game.discard();
            System.out.println(game.toObjectString(0));

            System.out.print("Another round? (Y): ");
            goNext = ( scan.nextLine().equalsIgnoreCase("Y") );
        }

        scan.close();
    }
}