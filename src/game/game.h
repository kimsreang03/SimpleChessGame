#ifndef CHESS_GAME
#define CHESS_GAME

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

/*              */

#define MAX_BUF 1024
#define MAX_NAME 32
#define GID_LEN 4

typedef struct PLAYER{
  char* name;
  char* gid;
  int8_t namelen;
}Player;
// use struct to make code more readable cuz it has prefix "player."
extern Player player;
extern char buffer[MAX_BUF];

// game.c
extern char* generate_gid(); // generate a new game id for player
extern void initialize_board();
extern void draw_board();
extern char boards[8][8]; 

// ui.c
extern void draw_welcome_screen(); //print welcome screen

//  net.c
extern int sockfd;
extern int connect_to_server();



#endif
