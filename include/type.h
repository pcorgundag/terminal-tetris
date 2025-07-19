
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>  

#pragma once

#ifndef TYPE_H
#define TYPE_H

const int HEIGHT = 26;
const int WIDTH = 12;

enum class Color {
    Yellow,
    Orange,
    Blue,
    Teal,
    Purple,
    Green,
    Red,
    White
};

class Position{
public:
    int x;
    int y;
};

struct Cell{
    Color color;
    int type = 0; //0 means fillable, 1 means left vertical wall, 2 means right vertical wall, 3 means horizontal wall, 4 means bottom part, 5 means empty, 6 means block, 7 means filled
    Position pos;
    Cell() : color(Color::White) {}
};


#endif

