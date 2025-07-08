
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>  

#ifndef HEADERFILE_H
#define HEADERFILE_H

const int HEIGHT = 23;
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

    Shape(){
        type = rand() % 7;
        switch (type){
            case 0:
                color = Color::Yellow;
                matrice = {
                {0, 1, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                };
                break;
            case 1:
                color = Color::Teal;
                matrice = {
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                };
                break;
            case 2:
                color = Color::Red;
                matrice = {
                {0, 1, 1, 0},
                {1, 1, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                };
                break;
            case 3:
                color = Color::Green;
                matrice = {
                {1, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                };
                break;
            case 4:
                color = Color::Orange;
                matrice = {
                {1, 1, 1, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                };
                break;
            case 5:
                color = Color::Blue;
                matrice = {
                {0, 1, 1, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                };
                break;
            case 6:
                color = Color::Purple;
                matrice = {
                {0, 1, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                };
                break; 
                
        }
        pos.x = 4;
        pos.y = 0;
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
        
        int startY = 5;
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
        //vertical walls
        for(int i = 1; i < 21; i++){
            grid[i][0].type = 1;
            grid[i][11].type = 2;
        }
        //horizontal walls
        for(int i = 1; i < 11; i++){
            grid[21][i].type = 3;
        }
        //bottom part
        for(int i = 1; i < 11; i++){
            grid[22][i].type = 4;
        }
        grid[21][0].type = 1;
        grid[21][11].type = 2;
        grid[22][0].type = 5;
        grid[22][11].type = 5;

        for(int y = 0; y < HEIGHT; y++){
            for (int x = 0; x < WIDTH; x++){
                grid[y][x].pos.x = x;
                grid[y][x].pos.y = y;
            }
        }
        
    }
};
#endif

