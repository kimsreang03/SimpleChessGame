server_src = $(wildcard src/server/*.c)
game_src = $(wildcard src/game/*.c)
server_obj = $(server_src:.c=.o)
game_obj = $(game_src:.c=.o)

flags = -g -Wall

server: $(server_obj)
	cc $(server_obj) $(flags) -o server

game: $(game_obj)
	cc $(game_obj) $(flags) -o game


clean:
	@rm src/server/*.o src/game/*.o
