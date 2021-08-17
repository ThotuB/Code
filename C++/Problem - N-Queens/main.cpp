#include <stdio.h>

#include <vector>

using namespace std;

#define SIZE 8
#define QUEENS SIZE

FILE *nqueens_out;

vector<unsigned> moves;  // moves possible on cols
unsigned table[SIZE][SIZE] = {0};
unsigned solutions = 0;

/// ------------------ INITIALIZING & PRINTING ------------------

void init_moves() {
    for (unsigned i = 0; i < SIZE; i++) {
        moves.push_back(i);
    }
}

void print_moves() {
    for (unsigned i = 0; i < moves.size(); i++) {
        printf("%u ", moves[i]);
    }
}

void print_table() {
    for (unsigned i = 0; i < SIZE; i++) {
        for (unsigned j = 0; j < SIZE; j++) {
            printf("%u ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/// ------------------ SVG DRAWING FUNCTIONS ------------------
#define LEN 60

void start_draw() {
    fprintf(nqueens_out, "<svg width=\"%u\" height=\"%u\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" overflow=\"scroll\">\n", (SIZE + 1) * LEN, 100 * (SIZE + 1) * LEN);
}

void stop_draw() {
    fprintf(nqueens_out, "</svg>");
}

void draw_queen(unsigned drawing, unsigned i, unsigned j) {
    unsigned cx = LEN * (1 + j);
    unsigned cy = LEN + drawing * (SIZE + 1) * LEN + i * LEN;
    unsigned r = LEN * 1 / 4;

    fprintf(nqueens_out, "<circle cx=\"%u\" cy=\"%u\" r=\"%u\" stroke-width=\"5\" stroke=\"black\" fill-opacity=\"0%%\" />\n", cx, cy, r);
    fprintf(nqueens_out, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke-width=\"5\" stroke=\"black\" fill-opacity=\"0%%\" />\n", cx + r / 4, cy + r / 4, cx + r, cy + r);
}

void draw_table() {
    static unsigned drawing = 0;

    unsigned color[2][3] = {{255, 206, 158}, {209, 139, 71}};

    unsigned x, y, r, g, b;

    for (unsigned i = 0; i < SIZE; i++) {
        for (unsigned j = 0; j < SIZE; j++) {
            x = LEN / 2 + j * LEN;
            y = LEN / 2 + drawing * (SIZE + 1) * LEN + i * LEN;
            r = color[(i + j) % 2][0];
            g = color[(i + j) % 2][1];
            b = color[(i + j) % 2][2];

            fprintf(nqueens_out, "<rect x=\"%u\" y=\"%u\" width=\"%u\" height=\"%u\" stroke-width=\"1\" stroke=\"rgb(%u,%u,%u)\" fill=\"rgb(%u,%u,%u)\" />\n", x, y, LEN, LEN, r, g, b, r, g, b);
            if (table[i][j]) {
                draw_queen(drawing, i, j);
            }
        }
    }
    drawing++;
}

/// ------------------ N-QUEENS PROBLEM ------------------

bool is_valid_move(unsigned x, unsigned y) {
    unsigned offset = min(x, y);

    for (unsigned i = 0; i < offset; i++) {  // check diag 1
        if (table[i + x - offset][i + y - offset] == 1) {
            return 0;
        }
    }
    y = SIZE - y - 1;
    offset = min(x, y);

    for (unsigned i = 0; i < offset; i++) {  // check diag 2
        if (table[i + x - offset][SIZE - (i + y - offset) - 1] == 1) {
            return 0;
        }
    }

    return 1;
}

void queen_problem(unsigned queen) {
    if (queen == QUEENS) {
        //print_table();
        draw_table();
        solutions++;
    } else {
        for (unsigned i = 0; i < moves.size(); i++) {
            if (is_valid_move(queen, moves[i])) {
                unsigned aux = moves[i];

                table[queen][aux] = 1;
                moves.erase(moves.begin() + i);

                queen_problem(queen + 1);

                moves.insert(moves.begin() + i, aux);
                table[queen][aux] = 0;
            }
        }
    }
}

int main() {
    nqueens_out = fopen("nqueens.svg", "w");

    start_draw();

    init_moves();
    queen_problem(0);

    stop_draw();
}
