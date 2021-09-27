def tictactoe(moves: list[list[int]]) -> str:
    rows = [0, 0, 0]
    cols = [0, 0, 0]
    diag = [0, 0]

    player = 0
    for row, col in moves:
        num = 1 if player == 0 else 4

        rows[row] += num
        cols[col] += num
        if row == col:
            diag[0] += num
        if row + col == 2:
            diag[1] += num

        if ( rows[row] == 3 * num or cols[col] == 3 * num or diag[0] == 3 * num or diag[1] == 3 * num ):
            return "A" if player == 0 else "B"
        
        player = (player + 1) % 2
    
    return "Draw" if len(moves) == 9 else "Pending"
        



if __name__ == "__main__":
    moves = [[0, 0], [2, 0], [1, 1], [2, 1], [2, 2]]
    print(tictactoe(moves))