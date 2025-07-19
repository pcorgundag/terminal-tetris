#pragma once 
#include <vector>
#include <ncurses.h>
#include "type.h"

class Board{
private:
    void initBoard();
    
public:
    std::vector<std::vector<Cell>> grid{HEIGHT, std::vector<Cell>(WIDTH)};

    Board();
    void printBoard();   

};
