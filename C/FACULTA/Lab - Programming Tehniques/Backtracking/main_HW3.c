#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // SIZE x SIZE table - default: 8
#define QUEENS SIZE

typedef struct _coord {
  unsigned x;
  unsigned y;
}coord_t;

unsigned table[SIZE][SIZE] = {0};
unsigned solutions = 0;

/// ------------------ PRINTING FUNCTIONS ------------------

void print_table(){
  for (unsigned i = 0; i < SIZE ; i++){
    for (unsigned j = 0; j < SIZE ; j++){
      printf("%u   ", table[i][j]);
    }
    printf("\n\n");
  }
  printf("\n");
}

/// ------------------ SVG DRAWING FUNCTIONS ------------------
#define LEN 60

void start_draw(FILE *stream){
  fprintf(stream, "<svg width=\"%u\" height=\"%u\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" overflow=\"scroll\">\n", (SIZE + 1) * LEN, 100 * (SIZE + 1) * LEN);
}

void stop_draw(FILE *stream){
  fprintf(stream, "</svg>");
}

void draw_queen(FILE *stream, unsigned drawing, unsigned i, unsigned j){
  unsigned cx = LEN * ( 1 + j );
  unsigned cy = LEN + drawing * (SIZE + 1) * LEN + i * LEN;
  unsigned r = LEN*1/4;

  fprintf(stream, "<circle cx=\"%u\" cy=\"%u\" r=\"%u\" stroke-width=\"5\" stroke=\"black\" fill-opacity=\"0%%\" />\n", cx, cy, r);
  fprintf(stream, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke-width=\"5\" stroke=\"black\" fill-opacity=\"0%%\" />\n", cx + r/4, cy + r/4, cx + r, cy + r);
}

void draw_table(FILE *stream){
  static unsigned drawing = 0;

  unsigned color[2][3] = {{255, 206, 158},{209, 139, 71}};

  unsigned x, y, r, g, b;

  for (unsigned i = 0 ; i < SIZE ; i++){
    for (unsigned j = 0 ; j < SIZE ; j++){
      x = LEN/2 + j * LEN;
      y = LEN/2 + drawing * (SIZE + 1) * LEN + i * LEN;
      r = color[(i+j)%2][0];
      g = color[(i+j)%2][1];
      b = color[(i+j)%2][2];

      fprintf(stream, "<rect x=\"%u\" y=\"%u\" width=\"%u\" height=\"%u\" stroke-width=\"1\" stroke=\"rgb(%u,%u,%u)\" fill=\"rgb(%u,%u,%u)\" />\n", x, y, LEN, LEN, r, g, b, r, g, b);
      if ( table[i][j] ){
        draw_queen(stream, drawing, i, j);
      }
    }
  }
  drawing++;
}

/// ------------------ PATH FINDING FUNCTIONS ------------------

unsigned min(unsigned x, unsigned y){
  return (x < y) ? x : y;
}

unsigned is_valid(unsigned x, unsigned y){
  for (unsigned i = 0 ; i < x ; i++){ // check cols
    if ( table[i][y] == 1 ){
      return 0;
    }
  }
  unsigned offset = min(x, y);

  for (unsigned i = 0 ; i < offset ; i++){ // check diag 1
    if ( table[i + x - offset][i + y - offset] == 1 ){
      return 0;
    }
  }
  y = SIZE - y - 1;
  offset = min(x, y);

  for (unsigned i = 0 ; i < offset ; i++){ // check diag 2
    if ( table[i + x - offset][SIZE - (i + y - offset) - 1] == 1 ){
      return 0;
    }
  }

  return 1;
}

void queens_problem(FILE * stream, unsigned queen){
  if ( queen == QUEENS ){
    print_table();
    draw_table(stream);
    solutions++;
  }
  else {
    for (unsigned j = 0 ; j < SIZE ; j++){
      // n-th queen -> placed on n-th row
      // every row has 1 queen
      if ( is_valid(queen, j) ){
        table[queen][j] = 1;
        queens_problem(stream,  queen + 1);
        table[queen][j] = 0;
      }
    }
  }
}

int main(){
  FILE *queens_out = fopen("queens.svg", "w");

  print_table();

  start_draw(queens_out);
  queens_problem(queens_out, 0);
  stop_draw(queens_out);

  printf("Total distinct solutions: %u", solutions);


  return 0;
}
