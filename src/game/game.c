#include "game.h"

char boards[9]; 
char buffer[MAX_BUF];




void reset_board(){

  for(int i = 0; i < 9; i++){
    boards[i] = ' ';  
  }

}


void draw_board(){

    printf("\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", boards[0], boards[1], boards[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", boards[3], boards[4], boards[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", boards[6], boards[7], boards[8]);
    printf("     |     |     \n");

    printf("\n");
}
