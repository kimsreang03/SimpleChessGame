#include "server.h"

void add_player(Player* player){
  pthread_mutex_lock(&mutex);

  for(int i = 0; i < MAX_PLAYER; i++){
    if(player_list[i] == NULL){
      player_list[i] = player;
      pcount++;
      break;
    }
  }

  pthread_mutex_unlock(&mutex);
}

void remove_player(Player* player){
  pthread_mutex_lock(&mutex);

  for(int i = 0; i < MAX_PLAYER; i++){

    if(player_list[i]->uid == player->uid){
      close(player->sockfd);
      free(player->name);
      free(player->gid);
      free(player);
      player_list[i] = NULL;
      pcount--;
      break;
    }

  }

  pthread_mutex_unlock(&mutex);
}