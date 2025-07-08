#include "mechanics.h"
#include <type.h>

void game_loop(){
    Board board;
    bool finish = false;
   for(int i = 0; i < 20; i++){
        Shape* block = new Shape;
        drop(block, board);
    }
    
}