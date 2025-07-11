#include "mechanics.h"
#include "type.h"

bool finish(Shape* block, Board &board)
{
    for(int y = 3; y >= 0; y--) { 
        for(int x = 0; x < 4; x++) {
            if (block->matrice[y][x] == 1) {
                int boardY = block->pos.y + y;
                int boardX = block->pos.x + x;


                if (board.grid[boardY][boardX].type != 7){
                    return true; 
                }
            }
        }
    }
        return false;
}
void break_row(Board &board, std::vector<int>& completed_lines)
{   std::vector<int> empty;
    std::sort(completed_lines.begin(), completed_lines.end(), std::greater<int>());
    for (int line : completed_lines) {
        // Move all rows above the cleared line down by one
        for (int y = line; y > 1; y--) {
            for (int x = 1; x < 11; x++) {  // Only copy playable area
                board.grid[y][x].type = board.grid[y-1][x].type;
                board.grid[y][x].color = board.grid[y-1][x].color;
            }
        }
        
        // Clear the top row
        for (int x = 1; x < 11; x++) {
            board.grid[1][x].type = 0;
            board.grid[1][x].color = Color::White;
        }
    }
    completed_lines = empty;
}

std::vector<int> check_completed_lines(Board &board) {
    std::vector<int> completed_lines;
    
    // Check rows 1 to 20 (playable area, excluding walls)
    for (int y = 1; y <= 20; y++) {
        int filled_blocks = 0;
        
        // Check columns 1 to 10 (excluding walls at 0 and 11)
        for (int x = 1; x < 11; x++) {
            if (board.grid[y][x].type == 7) {  // Frozen block
                filled_blocks++;
            }
        }
        
        if (filled_blocks == 10) {  // Full row
            completed_lines.push_back(y);
        }
    }
    
    return completed_lines;
}

void game_loop()
{

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        init_pair(2, 208, COLOR_BLACK); //orange
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
        init_pair(4, 44, COLOR_BLACK); //teal
        init_pair(5, 93, COLOR_BLACK); //purple
        init_pair(6, COLOR_GREEN, COLOR_BLACK);
        init_pair(7, COLOR_RED, COLOR_BLACK);
        init_pair(8, COLOR_WHITE, COLOR_BLACK);
        
    }

    noecho();
    cbreak();
    nodelay(stdscr, TRUE);  // Non-blocking input
    keypad(stdscr, TRUE);

    Board board;
    bool finish = false;
    int num = -1;
   while(!finish){
        Shape* block = new Shape(num);
        int next = rand() % 7;
        block->next = next;
        std::vector<int> tetris = check_completed_lines(board);
        if(tetris.size() > 0){
            break_row(board, tetris);
        }
        drop(block, board);
        num = next;
    }


    
}