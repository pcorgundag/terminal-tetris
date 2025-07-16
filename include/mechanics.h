#ifndef MECHANICS_H
#define MECHANICS_H

#include "type.h"


void move_down(Shape* block, Board &board);
void clear_shape(Shape* block, Board &board);
bool collision_check(Shape* block, Board &board);
void drop(Shape* block, Board &board, Player &player);

#endif
