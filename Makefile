main: src/main.cpp src/mechanics.cpp src/game.cpp
	g++ -std=c++17 -I include -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1 -o main src/main.cpp src/mechanics.cpp src/game.cpp -lncurses

clean:
	rm -f main