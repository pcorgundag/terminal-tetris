#include <unistd.h>
#include <type.h>

void clear_shape(Shape* block, Board &board)
{
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            if (block->matrice[y][x] == 1) {
                int boardY = block->pos.y + y;
                int boardX = block->pos.x + x;

                if (boardY >= 1 && boardY < HEIGHT && 
                    boardX >= 0 && boardX < WIDTH) {
                    board.grid[boardY][boardX].type = 0;
                    board.grid[boardY][boardX].color = Color::White;
                }
            
            }
        }
    }
}

void draw_shape(Shape* block, Board &board) 
{
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            if (block->matrice[y][x] == 1) {
                int boardY = block->pos.y + y;
                int boardX = block->pos.x + x;

                if (boardY >= 0 && boardY < HEIGHT && 
                    boardX >= 0 && boardX < WIDTH &&
                    board.grid[boardY][boardX].type == 0) {
                    board.grid[boardY][boardX].type = 6;
                    board.grid[boardY][boardX].color = block->color;
                }
            }
        }
    }
}


void move_down(Shape* block, Board &board) 
{
    clear_shape(block, board);
    block->pos.y++;
    draw_shape(block, board);
}

void move_left(Shape* block, Board &board)
{
    clear_shape(block, board);
    block->pos.x--;
    draw_shape(block, board);
}
void move_right(Shape* block, Board &board)
{
    clear_shape(block, board);
    block->pos.x++;
    draw_shape(block, board);
}


bool can_move_sideways(Shape* block, Board &board, int type){
    switch (type){
        case 0:
            for(int y = 3; y >= 0; y--) { 
                for(int x = 0; x < 4; x++) {
                    if (block->matrice[y][x] == 1) {
                        int boardY = block->pos.y + y;
                        int boardX = block->pos.x + x-1;


                        if (board.grid[boardY + 1][boardX].type != 0 && board.grid[boardY + 1][boardX].type != 6) {
                            return false; 
                        }
                    }
                }
            }     
            break;      
        case 1:
            for(int y = 3; y >= 0; y--) { 
                for(int x = 0; x < 4; x++) {
                    if (block->matrice[y][x] == 1) {
                        int boardY = block->pos.y + y;
                        int boardX = block->pos.x + x+1;


                        if (board.grid[boardY + 1][boardX].type != 0 && board.grid[boardY + 1][boardX].type != 6) {
                            return false; 
                        }
                    }
                }
            }     
            break;       
    }
    return true;
}


bool collision_check(Shape* block, Board &board)
{    
    for(int y = 3; y >= 0; y--) { 
        for(int x = 0; x < 4; x++) {
            if (block->matrice[y][x] == 1) {
                int boardY = block->pos.y + y;
                int boardX = block->pos.x + x;


                if (board.grid[boardY + 1][boardX].type != 0 && board.grid[boardY + 1][boardX].type != 6) {
                    return false; 
                }
            }
        }
    }
    return true;
}
void freeze(Shape* block, Board &board)
{
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            if (block->matrice[y][x] == 1) {
                int boardY = block->pos.y + y;
                int boardX = block->pos.x + x;

                board.grid[boardY][boardX].type = 7;
            
            }
        }
    }
}

void drop(Shape* block, Board &board)
{
    int drop_counter = 0;
    int drop_speed = 7;
    
    while(collision_check(block, board)){
        int ch = getch();
        if(ch != ERR) { 
            switch(ch) {
                case 'a':
                case KEY_LEFT:
                    if (can_move_sideways(block, board, 0)) {
                        move_left(block, board);
                    }
                    break;
                case 'd':
                case KEY_RIGHT:
                    if (can_move_sideways(block, board, 1)) {
                        move_right(block, board);
                    }
                    break;
                case 's':
                case KEY_DOWN:
                    move_down(block, board);
                    drop_counter = 0;  // Reset counter on manual drop
                    break;
                case 'q':
                    endwin();
                    exit(0);
                    break;
            }
        }
        
        // Auto-drop based on counter
        drop_counter++;
        if (drop_counter >= drop_speed) {
            move_down(block, board);
            drop_counter = 0;
        }
        
        clear();
        board.printBoard();
        usleep(20000);  // Much faster frame rate (20ms)
    }
    freeze(block, board);
    delete block;
}