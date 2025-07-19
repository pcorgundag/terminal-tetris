#pragma once

#include <unistd.h>
#include <algorithm>
#include "shape.h"
#include "type.h"
#include "player.h"
#include "board.h"


void clear_shape(Shape* block, Board &board);
void draw_shape(Shape* block, Board &board);
void move_down(Shape* block, Board &board);
void move_left(Shape* block, Board &board);
void move_right(Shape* block, Board &board);
bool can_move_sideways(Shape* block, Board &board, int type);
void rotate(Shape* block, Board &board);
bool can_rotate(Shape* block, Board &board);
bool collision_check(Shape* block, Board &board);
void freeze(Shape* block, Board &board);
void insta(Shape* block, Board &board);
void drop(Shape* block, Board &board, Player &player);