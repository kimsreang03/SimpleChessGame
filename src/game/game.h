#ifndef CHESS_GAME
#define CHESS_GAME

/*      header files     */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <wchar.h>
#include <locale.h>
#include <ncursesw/ncurses.h>


/*      chess piece       */
#define none 0x20 // space

#define wking   0x2654
#define wqueen  0x2655
#define wrook   0x2656
#define wbishop 0x2657
#define wknight 0x2658
#define wpawn   0x2659

#define bking   0x265a
#define bqueen  0x265b
#define brook   0x265c
#define bbishop 0x265d
#define bknight 0x265e
#define bpawn   0x265f

/**************************/

#define EXIT 0
#define PLAY_COMPUTER 1
#define PLAY_ONLINE 2


#define MAX_BUF 1024
#define MAX_NAME 16

typedef signed char byte;
typedef unsigned char ubyte;

typedef struct PLAYER{
  char* name;
  int gid;
  byte namelen;
}Player;
// use struct to make code more readable cuz it has prefix "player."
extern Player player;

extern char buffer[MAX_BUF];


// game.c
extern wchar_t boards[8][8]; 
extern int screen_width, screen_height;
extern void start_game_online();
extern void start_game_computer();


// ui.c
extern byte draw_welcome_screen(); //print welcome screen
extern char* get_player_name();


//  net.c
extern int sockfd;
extern int connect_to_server();



#endif
