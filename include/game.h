#pragma once

#include "type.h"
#include "mechanics.h"
#include "board.h"
#include "player.h"
#include "board.h"

class Game{
private:
    Board board;
    Player player;
    int num = -1;
    int inc_score = 0;
    int inc_lines = 0;
    int tens = 0;
    
    bool finish(Board &board);
    void break_row(Board &board, std::vector<int>& completed_lines);
    std::vector<int> check_completed_lines(Board &board);
    void init_ncurses();

public:
    void game_loop();
};