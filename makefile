exe_file = crazyeights
CC = g++ -std=c++11

$(exe_file): main.o game.o player.o util.o
		$(CC) -o $(exe_file) main.o game.o player.o util.o

main.o:	main.cpp
		$(CC) -c main.cpp

game.o:
		$(CC) -c game.cpp

player.o:
		$(CC) -c player.cpp

util.o:
		$(CC) -c util.cpp

clean:
		rm -f *.out *.o $(exe_file)