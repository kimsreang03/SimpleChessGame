#include "game.h"

#define SERVER_ADDR 0x7f000000 // 127.0.0.0
#define SERVER_PORT 0xabc // 2748

#define _err_check(re){if(re == -1) return re;}

int sockfd;

int connect_to_server(){

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  _err_check(sockfd);

  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(SERVER_ADDR);
  server_addr.sin_port = htons(SERVER_PORT);
  
  _err_check(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)));

  return 0;
}