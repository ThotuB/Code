function findWinningCardIndex(board, trump) {
    let winningCardIndex = 0;

    for (let i = 1; i < board.length; i++) {
        const card = board[i];
        const winningCard = board[winningCardIndex];

        if (winningCard.suit !== trump && card.suit === trump) {
            winningCardIndex = i;
        }
        else if (card.suit === winningCard.suit && card.value > winningCard.value) {
            winningCardIndex = i;
        }
    }

    return winningCardIndex;
}

const cards = [{
    suit: 'spades',
    value: 2
}, {
    suit: 'spades',
    value: 10
}, {
    suit: 'hearts',
    value: 1
}, {
    suit: 'hearts',
    value: 2
}]

const trump = 'clubs';

console.log(findWinningCardIndex(cards, trump));