#include "player.h"

Player::Player(){
    block_curr = -1;
    score = 0;
    lines = 0;
    highscore = 0;
    level = 0;
}

Shape* Player::create_block()
{
    Shape* block = new Shape(block_curr);
    
    block_next = rand() % 7;
    block->next = block_next;
    block_curr = block_next;
    return block;
}

void Player::print_score(){
    attron(COLOR_PAIR(8));
    int startY = 24;
    int startX = 82;

    mvprintw(startY, startX, "SCORE: %d", score);
    refresh();
}

void Player::print_high_score(){
    attron(COLOR_PAIR(8));
    int startY = 25;
    int startX = 82;

    mvprintw(startY, startX, "HIGHSCORE: %d", highscore);
    refresh();

}
void Player::print_lines(){
    attron(COLOR_PAIR(8));
    int startY = 24;
    int startX = 44;

    mvprintw(startY, startX, "LINES: %d", lines);
    refresh();

}
void Player::print_level(){
    attron(COLOR_PAIR(8));
    int startY = 25;
    int startX = 44;

    mvprintw(startY, startX, "LEVEL: %d", level);
    refresh();

}
void Player::print_player_stats(){
    print_score();
    print_high_score();
    print_lines();
    print_level();
}
