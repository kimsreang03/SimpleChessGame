#include "game.h"

wchar_t boards[8][8];
int screen_width, screen_height;

static void initialize_board();
static void draw_board();
static void draw_inverted_board();





void start_game_online(){
  initialize_board();

  

  refresh();
}

void start_game_computer(){

  /* IMPLEMENT ME*/

}

static void initialize_board(){

  boards[0][0] = boards[0][7] = wrook;
  boards[0][1] = boards[0][6] = wknight;
  boards[0][2] = boards[0][5] = wbishop;
  boards[0][3] = wking; boards[0][4] = wqueen;
    
  boards[7][0] = boards[7][7] = brook;
  boards[7][1] = boards[7][6] = bknight;
  boards[7][2] = boards[7][5] = bbishop;
  boards[7][3] = bking; boards[7][4] = bqueen;

  for(int i = 0; i < 8; i++){
    boards[1][i] = wpawn;
    boards[6][i] = bpawn;
    boards[2][i] = boards[3][i] = boards[4][i] = boards[5][i] = none; 
  }
  
}

static void draw_board() {
  printw("\n");
  printw("          a     b     c     d     e     f     g     h     \n");
  printw("       ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐   \n");
  printw("     8 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 8 \n", boards[0][0], boards[0][1], boards[0][2], boards[0][3], boards[0][4], boards[0][5], boards[0][6], boards[0][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     7 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 7 \n", boards[1][0], boards[1][1], boards[1][2], boards[1][3], boards[1][4], boards[1][5], boards[1][6], boards[1][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     6 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 6 \n", boards[2][0], boards[2][1], boards[2][2], boards[2][3], boards[2][4], boards[2][5], boards[2][6], boards[2][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     5 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 5 \n", boards[3][0], boards[3][1], boards[3][2], boards[3][3], boards[3][4], boards[3][5], boards[3][6], boards[3][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     4 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 4 \n", boards[4][0], boards[4][1], boards[4][2], boards[4][3], boards[4][4], boards[4][5], boards[4][6], boards[4][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     3 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 3 \n", boards[5][0], boards[5][1], boards[5][2], boards[5][3], boards[5][4], boards[5][5], boards[5][6], boards[5][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     2 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 2 \n", boards[6][0], boards[6][1], boards[6][2], boards[6][3], boards[6][4], boards[6][5], boards[6][6], boards[6][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     1 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 1 \n", boards[7][0], boards[7][1], boards[7][2], boards[7][3], boards[7][4], boards[7][5], boards[7][6], boards[7][7]);
  printw("       └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘   \n");
  printw("          a     b     c     d     e     f     g     h     \n\n");
}

static void draw_inverted_board() {
  printw("\n");
  printw("          h     g     f     e     d     c     b     a     \n");
  printw("       ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐   \n");
  printw("     1 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 1 \n", boards[7][0], boards[7][1], boards[7][2], boards[7][3], boards[7][4], boards[7][5], boards[7][6], boards[7][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     2 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 2 \n", boards[6][0], boards[6][1], boards[6][2], boards[6][3], boards[6][4], boards[6][5], boards[6][6], boards[6][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     3 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 3 \n", boards[5][0], boards[5][1], boards[5][2], boards[5][3], boards[5][4], boards[5][5], boards[5][6], boards[5][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     4 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 4 \n", boards[4][0], boards[4][1], boards[4][2], boards[4][3], boards[4][4], boards[4][5], boards[4][6], boards[4][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     5 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 5 \n", boards[3][0], boards[3][1], boards[3][2], boards[3][3], boards[3][4], boards[3][5], boards[3][6], boards[3][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     6 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 6 \n", boards[2][0], boards[2][1], boards[2][2], boards[2][3], boards[2][4], boards[2][5], boards[2][6], boards[2][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     7 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 7 \n", boards[1][0], boards[1][1], boards[1][2], boards[1][3], boards[1][4], boards[1][5], boards[1][6], boards[1][7]);
  printw("       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   \n");
  printw("     8 │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │  %lc  │ 8 \n", boards[0][0], boards[0][1], boards[0][2], boards[0][3], boards[0][4], boards[0][5], boards[0][6], boards[0][7]);
  printw("       └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘   \n");
  printw("          h     g     f     e     d     c     b     a     \n\n");
}

