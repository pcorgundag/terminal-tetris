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

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        init_pair(2, 208, COLOR_BLACK); //orange
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
        init_pair(4, 44, COLOR_BLACK); //teal
        init_pair(5, 93, COLOR_BLACK); //purple
        init_pair(6, COLOR_GREEN, COLOR_BLACK);
        init_pair(7, COLOR_RED, COLOR_BLACK);
        init_pair(8, COLOR_WHITE, COLOR_BLACK);
        
    }

    noecho();
    cbreak();
    nodelay(stdscr, TRUE);  // Non-blocking input
    keypad(stdscr, TRUE);

    game_loop();
        
    endwin();
    return 0;
}