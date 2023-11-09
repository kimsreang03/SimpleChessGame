#include "game.h"
#include "ui.h"

// welcome menu and return option
byte draw_welcome_screen(){

  noecho(); // don't output when user type anything
  curs_set(0); // hide the cursor
  
  start_color(); 
  init_pair(1, COLOR_YELLOW, 0);

  short x, y; 
  byte option = PLAY_ONLINE;
  
  // get the center position of the screen
  y = getmaxy(stdscr)/2;
  x = getmaxx(stdscr)/2;
  
  
  _welcome_screen(y, x); // ui.h    
  _ws_menu(y, x, option); // ui.h

  while(true){
    // get input from user
    switch (getch()){
      
      case KEY_RESIZE: 
        x = getmaxx(stdscr)/2;
        y = getmaxy(stdscr)/2;
        clear();
        _welcome_screen(y, x);
        _ws_menu(y, x, option); // ui.h
        refresh();
      break;

      case KEY_UP:
        option++;
        if(option > 2) option = EXIT;
      break;

      case KEY_DOWN:
        option--;
        if(option < 0) option = PLAY_ONLINE;
      break;

      case 10: return option; // when user hit enter
      default: continue;
    }// switch(c)
    _ws_menu(y, x, option);

  } //while(true)
  

}// welcome_screen();


char* get_player_name(){

    

  return 0;
}