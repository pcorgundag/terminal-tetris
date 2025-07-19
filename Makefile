main: src/main.cpp src/game.cpp src/mechanics.cpp src/player.cpp src/shape.cpp src/board.cpp
	g++ -std=c++17 -I include -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1 -o main src/main.cpp src/mechanics.cpp src/game.cpp src/board.cpp src/shape.cpp src/player.cpp -lncurses

clean:
	rm -f main