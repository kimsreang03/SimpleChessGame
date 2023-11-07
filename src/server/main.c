#include "server.h"

Player* player_list[MAX_PLAYER];
char buffer[MAX_BUF + 1];
int pcount = 0;


static int listenfd;
static int pfd;
static Player* pl;
static int uid = 0xa;
static pthread_t thread;

static char* get_player_name();
static char* generate_gid();

int main(void){

  listenfd = open_listen_socket();
  _err_out(listenfd, "failed to open listen socket!");

  while(true){
    
    pfd = accept(listenfd, NULL, NULL);
    if(pfd == -1) continue;

    if(pcount == MAX_PLAYER){
      close(pfd);
      continue;
    }

    pl = malloc(sizeof(Player));
    pl->sockfd = pfd;
    pl->uid = uid++;
    pl->name = get_player_name();
    pl->gid = generate_gid();
    add_player(pl);

    pthread_create(&thread, NULL, handling_player, pl);

    sleep(1);
  } // while(true)

  return 0;
}

static char* get_player_name(){

  char* name;

  int n = recv(pfd, buffer, MAX_NAME, 0);
  if(n < 0) return NULL;
  buffer[n] = 0;

  name = calloc(n, sizeof(char));
  memcpy(name, buffer, n);

  return name;
} // get_player_name();

static char* generate_gid(){

  char* gid = calloc(MAX_GID + 1, sizeof(char)); // 5 bytes

  char codes[] = "0123456789abcdef"; // 16 total
  int i;

  gid[0] = uid + 0x57;

  srand(time(NULL));
  gid[1] = codes[rand() % 16];
  gid[2] = codes[rand() % 16];
  gid[3] = codes[rand() % 16];
  gid[4] = 0;
  
  return gid;
} // generate_gid();



