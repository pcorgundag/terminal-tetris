#pragma once

#include <vector>
#include "type.h"

class Shape{
public:
    std::vector<std::vector<bool>> matrice;
    int type;
    Position pos;
    int rotation;
    Color color;
    int next;
    int size;

    Shape(int num);
    
    void print_block_cell();
};
