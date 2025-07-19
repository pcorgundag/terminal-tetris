#include "game.h"

bool Game::finish(Board &board)
{
    for(int y = 0; y < 4; y++){
        for(int x = 1; x < 11; x++){
            if(board.grid[y][x].type == 7){
                return true;
            }
        }
    }
        return false;
}
void Game::break_row(Board &board, std::vector<int>& completed_lines)
{   std::vector<int> empty;
    std::sort(completed_lines.begin(), completed_lines.end(), std::greater<int>());
    for (int line : completed_lines) {
        // Move all rows above the cleared line down by one
        for (int y = line; y > 4; y--) {
            for (int x = 1; x < 11; x++) { 
                board.grid[y][x].type = board.grid[y-1][x].type;
                board.grid[y][x].color = board.grid[y-1][x].color;
            }
        }
    }
    completed_lines = empty;
}

std::vector<int> Game::check_completed_lines(Board &board) {
    std::vector<int> completed_lines;
    
    for (int y = 4; y <= 24; y++) {
        int filled_blocks = 0;
        
        for (int x = 1; x < 11; x++) {
            if (board.grid[y][x].type == 7) {  
                filled_blocks++;
            }
        }
        
        if (filled_blocks == 10) {  // Full row
            completed_lines.push_back(y);
        }
    }
    
    return completed_lines;
}

void Game::init_ncurses(){
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
}

void Game::game_loop()
{
    init_ncurses();

   while(!finish(board)){
        Shape* block = player.create_block();
        drop(block, board, player);

        std::vector<int> tetris = check_completed_lines(board);
        while (!tetris.empty()) {
            inc_score += tetris.size();
            inc_lines += tetris.size();
            break_row(board, tetris);
            tetris = check_completed_lines(board);
        }

        player.score += inc_score;
        player.lines += inc_lines;
        tens = inc_lines;
        if(tens == 10){
            player.level++;
            tens = 0;
        } 
       
        inc_lines = 0;
        inc_score = 0;
        
    }
    return;


    
}