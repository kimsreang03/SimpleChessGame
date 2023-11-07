#ifndef GAME_SERVER
#define GAME_SERVER

/* header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>


#define SERVER_ADDR 0x7f000000 // 127.0.0.0
#define SERVER_PORT 0xabc // 2748
#define MAX_NAME 32
#define MAX_PLAYER 10
#define MAX_GID 4
#define MAX_BUF 1024

#define _err_return(re){ if(re == -1) return -1;}
#define _err_out(re, str){ if(re == -1){ perror(str); return -1; } }

typedef struct PLAYER{
  char* name; // name in game
  char* gid; // game id
  int sockfd; // socket descriptor
  int uid; // unique identifier
}Player;

// main.c
extern char buffer[MAX_BUF + 1];
extern Player* player_list[MAX_PLAYER];
extern int pcount;

// server.c
extern pthread_mutex_t mutex;

extern int open_listen_socket();
extern void* handling_player(void* pl);

// list.c
extern void add_player(Player* player);
extern void remove_player(Player* player);

#endif