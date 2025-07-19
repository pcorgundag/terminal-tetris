#pragma once
#include "shape.h"

class Player{
private:
    int block_curr;
    int block_next;

public:
    int score;
    int lines;
    int level;
    int highscore;

    Player();
    Shape* create_block();
    void print_score();
    void print_high_score();
    void print_lines();
    void print_level();
    void print_player_stats();
    

};
