#include "game.h"

Player player;
char buffer[MAX_BUF];
bool running = 1;

int main(){

  setlocale( LC_ALL, "en_US.UTF-8" );

  initscr();
  keypad(stdscr, true);
  


  while(running){
    switch(draw_welcome_screen()){
    
      case PLAY_ONLINE:
      player.name = get_player_name();
      if(!player.name) continue; // user selected 'go back'
      // player.gid = set_player_gid();
      start_game_online();
      break;
        start_game_computer();
      case PLAY_COMPUTER:
      break;

      case EXIT: running = 0; 
      break;
    }//switch
  }

  endwin();
  return 0;
}