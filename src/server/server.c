#include "server.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* handling_player(void* pl){
  Player* player = pl;
  bool connecting = true;

  // while(connecting){

  /* IMPLEMENT ME*/

  // }

  remove_player(player);
  pthread_detach(pthread_self());
  return NULL;
}


int open_listen_socket(){
  int listenfd;
  struct sockaddr_in server_addr;
  int optval = 1;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  _err_out(listenfd, "socket() failed!");

  
  _err_out(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)), 
          "setsockopt() failed");

  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(SERVER_ADDR);
  server_addr.sin_port = htons(SERVER_PORT);
  
  _err_out(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr)),
          "bind() failed!");
  _err_out(listen(listenfd, MAX_PLAYER), "listend() failed!");

  return listenfd;
}

