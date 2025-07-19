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
void Game::break_row(Board &board, std::vector<int>& completed_lines) {
    std::vector<int> empty;
    std::sort(completed_lines.begin(), completed_lines.end(), std::greater<int>());
    
    int lines_cleared = 0;
    int current_line_index = 0;
    
    // Process from bottom to top
    for (int y = 26; y >= 4; y--) {  // Assuming 24 is your bottom row
        // Check if current row should be cleared
        if (current_line_index < completed_lines.size() && 
            y == completed_lines[current_line_index]) {
            lines_cleared++;
            current_line_index++;
            continue;  // Skip this row (it gets cleared)
        }
        
        // Move this row down by the number of lines cleared below it
        if (lines_cleared > 0) {
            for (int x = 1; x < 11; x++) {
                board.grid[y + lines_cleared][x].type = board.grid[y][x].type;
                board.grid[y + lines_cleared][x].color = board.grid[y][x].color;
            }
        }
    }
    
    // Clear the top rows
    for (int y = 4; y < 4 + lines_cleared; y++) {
        for (int x = 1; x < 11; x++) {
            board.grid[y][x].type = 0;  // Assuming 0 is empty
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

void Game::render(Board& board, Player& player, Shape* block){
    clear();
    board.printBoard();
    block->print_block_cell();
    player.print_player_stats();
    usleep(20000);
}

void Game::init_ncurses(){
    if (has_colors()) {
        start_color();
        init_pair(1, 227, COLOR_BLACK); //yellow
        init_pair(2, 215, COLOR_BLACK); //orange
        init_pair(3, 25, COLOR_BLACK); //dark blue
        init_pair(4, 159, COLOR_BLACK); //teal
        init_pair(5, 213, COLOR_BLACK); //purple
        init_pair(6, 114, COLOR_BLACK); //green
        init_pair(7, 168, COLOR_BLACK); //red
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