
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>  

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

class Shape{
public:
    std::vector<std::vector<bool>> matrice{4, std::vector<bool>(4)};
    int type;
    Position pos;
    int rotation;
    Color color;
    int next;

    Shape(int num){
        if(num == -1){
            type = rand() % 7;
        }
        else{
            type = num;
        }
        switch (type){
            case 0:
                color = Color::Yellow;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 1, 0},
                {0, 1, 1, 0},
                };
                break;
            case 3:
                color = Color::Teal;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                };
                break;
            case 6:
                color = Color::Red;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 1, 0},
                {1, 1, 0, 0},
                };
                break;
            case 5:
                color = Color::Green;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 1, 0},
                };
                break;
            case 1:
                color = Color::Orange;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {1, 0, 0, 0},
                };
                break;
            case 2:
                color = Color::Blue;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 1, 1},
                {0, 0, 0, 1},
                };
                break;
            case 4:
                color = Color::Purple;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 1, 0},
                };
                break; 
                
        }
        pos.x = 4;
        pos.y = -2;
    }
    
    void print_block_cell()
    {
    attron(COLOR_PAIR(8));
    int startY = 5;
    int startX = 90;
    
    // Draw the box
    mvprintw(startY, startX, "NEXT          ");
    mvprintw(startY+1, startX, "|------------|");
    
    for(int i = 2; i < 4; i++){
        mvprintw(startY + i, startX, "|            |");
    }
    mvprintw(startY + 4, startX, "|------------|");
    
    int shapeColor = static_cast<int>(next) + 1;
    attron(COLOR_PAIR(shapeColor));
    
    switch(next){
        case 0: // Yellow Square
            mvprintw(startY + 2, startX + 5, "[][]");
            mvprintw(startY + 3, startX + 5, "[][]");
            break;
        case 3: // Teal Line
            mvprintw(startY + 2, startX + 3, "[][][][]");
            break;
        case 6: // Red Z
            mvprintw(startY + 2, startX + 6, "[][]");
            mvprintw(startY + 3, startX + 4, "[][]");
            break;
        case 5: // Green S
            mvprintw(startY + 2, startX + 4, "[][]");
            mvprintw(startY + 3, startX + 6, "[][]");
            break;
        case 1: // Orange L
            mvprintw(startY + 2, startX + 4, "[][][]");
            mvprintw(startY + 3, startX + 4, "[]");
            break;
        case 2: // Blue J
            mvprintw(startY + 2, startX + 4, "[][][]");
            mvprintw(startY + 3, startX + 8, "[]");
            break;
        case 4: // Purple T
            mvprintw(startY + 2, startX + 6, "[]");
            mvprintw(startY + 3, startX + 4, "[][][]");
            break;
    }
    
    attroff(COLOR_PAIR(shapeColor));
    attroff(COLOR_PAIR(8));
    refresh();
}

};

struct Cell{
    Color color;
    int type = 0; //0 means fillable, 1 means left vertical wall, 2 means right vertical wall, 3 means horizontal wall, 4 means bottom part, 5 means empty, 6 means block, 7 means filled
    Position pos;
    Cell() : color(Color::White) {}
};


class Board{
public:
    std::vector<std::vector<Cell>> grid{HEIGHT, std::vector<Cell>(WIDTH)};

    Board(){
        initBoard();
    }

    void printBoard()
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

private:
    void initBoard()
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
};

class Player{
    int block_curr;
    int block_next;
    
    //int score;
    //int highscore
public:
    Player(){
        block_curr = -1;
    }
    Shape* create_block()
    {
        Shape* block = new Shape(block_curr);
        
        block_next = rand() % 7;
        block->next = block_next;
        block_curr = block_next;
        return block;
    }
    

};

#endif

