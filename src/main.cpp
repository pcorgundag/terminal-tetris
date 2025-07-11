#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.h"

int main() {
    initscr();
    srand(time(0) ^ getpid());
    rand();

    game_loop();
    endwin();
    system("reset");

    return 0;
}