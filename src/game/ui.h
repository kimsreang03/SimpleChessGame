#ifndef UI_H
#define UI_H


#define _welcome_screen(y, x){ \
  mvprintw(y-9,x-20, " ██████╗██╗  ██╗███████╗███████╗███████╗");\
  mvprintw(y-8,x-20, "██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝");\
  mvprintw(y-7,x-20, "██║     ███████║█████╗  ███████╗███████╗");\
  mvprintw(y-6,x-20, "██║     ██╔══██║██╔══╝  ╚════██║╚════██║");\
  mvprintw(y-5,x-20, "╚██████╗██║  ██║███████╗███████║███████║");\
  mvprintw(y-4,x-20, " ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝");\
  mvprintw(y-3,x-28, "╔╝ ╚══════════════════════════════════════════════════╝ ╚╗");\
  mvprintw(y-2,x-28, "╚╗ ╔══════════════════════════════════════════════════╗ ╔╝");\
  mvprintw(y-1,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y  ,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+1,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+2,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+3,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+4,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+5,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+6,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+7,x-28, " ║ ║                                                  ║ ║");\
  mvprintw(y+8,x-28, "╔╝ ╚══════════════════════════════════════════════════╝ ╚╗");\
  mvprintw(y+9,x-28, "╚╗ ╔══════════════════════════════════════════════════╗ ╔╝");\
}

#define _ws_menu(y, x, opt) {\
  if(opt == PLAY_ONLINE) attron(COLOR_PAIR(1)); \
  mvprintw(y-1,x-19, "┌────────────────────────────────────┐");\
  mvprintw(y  ,x-19, "              PLAY ONLINE             ");\
  mvprintw(y+1,x-19, "└────────────────────────────────────┘");\
  if(opt == PLAY_ONLINE) attroff(COLOR_PAIR(1));\
  if(opt == PLAY_COMPUTER) attron(COLOR_PAIR(1)); \
  mvprintw(y+2,x-19, "┌────────────────────────────────────┐");\
  mvprintw(y+3,x-19, "              PLAY COMPUTER           ");\
  mvprintw(y+4,x-19, "└────────────────────────────────────┘");\
  if(opt == PLAY_COMPUTER) attroff(COLOR_PAIR(1));\
  if(opt == EXIT) attron(COLOR_PAIR(1)); \
  mvprintw(y+5,x-19, "┌────────────────────────────────────┐");\
  mvprintw(y+6,x-19, "                 EXIT                 ");\
  mvprintw(y+7,x-19, "└────────────────────────────────────┘");\
  if(opt == EXIT) attroff(COLOR_PAIR(1));\
}



#endif