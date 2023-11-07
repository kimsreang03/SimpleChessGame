#include "game.h"
#include <errno.h>

Player player;

int main(int argc, char* argv[]){

  if(argc != 2){
    printf("usage: %s <game-name>\n", argv[0]);
    return 0;
  } 

  if(connect_to_server() == 0) printf("connect to the server successfully\n");
  else printf("err: %s\n", strerror(errno));

  player.name = argv[1];
  player.gid = generate_gid();

  printf("name: %s\n", player.name);
  printf("gid: %s\n", player.gid);

  free(player.gid);

  return 0;
}