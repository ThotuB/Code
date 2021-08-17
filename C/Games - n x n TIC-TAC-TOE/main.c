#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 3

int moves = TABLE_SIZE * TABLE_SIZE;                            // possible moves at a given moment
const int decisiveMoves = (TABLE_SIZE - 1) * (TABLE_SIZE - 1);  // possible moves after which a winner is possible

void init_table(char table[TABLE_SIZE][TABLE_SIZE]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            table[i][j] = '-';
        }
    }
}

void print_table(char table[TABLE_SIZE][TABLE_SIZE]) {
    printf("\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid(char table[TABLE_SIZE][TABLE_SIZE], int x, int y) {
    if ((x >= 0 && x < TABLE_SIZE) && (y >= 0 && y < TABLE_SIZE)) {
        if (table[x][y] == '-') {
            return 1;
        }
    }
    printf("INVALID MOVE\n");
    return 0;
}

void make_move(char table[TABLE_SIZE][TABLE_SIZE], char c, int x, int y) {
    table[x][y] = c;
}

char change_player(char p) {
    if (p == 'X') {
        return 'O';
    }
    return 'X';
}

char check_win(char table[TABLE_SIZE][TABLE_SIZE]) {
    if (moves <= decisiveMoves) {
        int sum;

        // CHECKS ROWS
        for (int i = 0; i < TABLE_SIZE; i++) {
            sum = 0;
            for (int j = 0; j < TABLE_SIZE; j++) {
                sum += table[i][j];
            }
            sum /= TABLE_SIZE;
            if (sum == 'X' || sum == '0') {
                return sum;
            }
        }

        // CHECKS COLS
        for (int i = 0; i < TABLE_SIZE; i++) {
            sum = 0;
            for (int j = 0; j < TABLE_SIZE; j++) {
                sum += table[j][i];
            }
            sum /= TABLE_SIZE;
            if (sum == 'X' || sum == '0') {
                return sum;
            }
        }

        // CHECKS DIAGS
        sum = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            sum += table[i][i];
        }
        sum /= TABLE_SIZE;
        if (sum == 'X' || sum == '0') {
            return sum;
        }
        sum = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            sum += table[i][TABLE_SIZE - i - 1];
        }
        sum /= TABLE_SIZE;
        if (sum == 'X' || sum == '0') {
            return sum;
        }
    }
    return '-';
}

int main() {
    char Tab[TABLE_SIZE][TABLE_SIZE];
    char winner = '-';
    char player = 'X';
    int x, y;

    init_table(Tab);

    while (winner == '-' && moves) {
        do {
            printf("%c moves: ", player);
            scanf("%d %d", &x, &y);
            x--;
            y--;
        } while (!is_valid(Tab, x, y));
        make_move(Tab, player, x, y);

        print_table(Tab);

        moves--;
        player = change_player(player);
        winner = check_win(Tab);
    }

    switch (winner) {
        case 'X':
            printf("X WINS!");
            break;
        case '0':
            printf("0 WINS!");
            break;
        case '-':
            printf("DRAW...");
            break;
    }
    return 0;
}
