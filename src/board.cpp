#include "board.h"
Board::Board(){
    initBoard();
}

void Board::printBoard()
{

    attron(COLOR_PAIR(8));
    
    int startY = 2;
    int startX = 55;
    
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            int color = static_cast<int>(grid[y][x].color) + 1;

            switch (grid[y][x].type)
            {
            case 0:
                mvprintw(startY + y, startX + x*2, " .");  // x*2 for spacing
                break;
            case 1:
                mvprintw(startY + y, startX + x*2, "<!");
                break;
            case 2:
                mvprintw(startY + y, startX + x*2, "!>");
                break;
            case 3:
                mvprintw(startY + y, startX + x*2, "==");
                break;
            case 4:
                mvprintw(startY + y, startX + x*2, "\\/");
                break;
            case 5:
                mvprintw(startY + y, startX + x*2, "  ");
                break;
            case 6:
                attron(COLOR_PAIR(color));
                mvprintw(startY + y, startX + x*2, "[]");
                attroff(COLOR_PAIR(color));
                break;
            case 7:
                attron(COLOR_PAIR(color));
                mvprintw(startY + y, startX + x*2, "[]");
                attroff(COLOR_PAIR(color));
                break;
            }


        }
    }
    refresh();

}


void Board::initBoard()
{
    for(int i = 0; i < 12; i++){
        grid[0][i].type = 5;
    }
        for(int i = 0; i < 12; i++){
        grid[1][i].type = 5;
    }
        for(int i = 0; i < 12; i++){
        grid[2][i].type = 5;
    }
        for(int i = 0; i < 12; i++){
        grid[3][i].type = 5;
    }
    

    //vertical walls
    for(int i = 4; i < 24; i++){
        grid[i][0].type = 1;
        grid[i][11].type = 2;
    }
    //horizontal walls
    for(int i = 1; i < 11; i++){
        grid[24][i].type = 3;
    }
    //bottom part
    for(int i = 1; i < 11; i++){
        grid[25][i].type = 4;
    }
    grid[24][0].type = 1;
    grid[24][11].type = 2;
    grid[25][0].type = 5;
    grid[25][11].type = 5;

    for(int y = 2; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            grid[y][x].pos.x = x;
            grid[y][x].pos.y = y;
        }
    }
    
}
