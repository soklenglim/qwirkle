.default: all

all: qwirkle

clean:
	rm -rf qwirkle *.o *.dSYM

qwirkle: Tile.o Board.o Engine.o Player.o Node.o LinkedList.o Menu.o qwirkle.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
