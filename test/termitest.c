// #define _XOPEN_SOURCE_EXTENDED
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>

#define reset "\x1b0m"
#define fyellow "\x1b38:5:220m"

int main(void){


  setlocale( LC_ALL, "en_US.UTF-8" );
  initscr();
  
  start_color();
  init_pair(1, COLOR_YELLOW, 0);

  attron(COLOR_PAIR(1));
  printw("┌─────┬─────┬────    ─┬─────┬─────┬─────┬─────┬─────┐\n");
  attroff(COLOR_PAIR(1));
  
  
  getch();
  endwin();

  return 0;
}