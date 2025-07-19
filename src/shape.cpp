#include "shape.h"

Shape::Shape(int num)
{
    if(num == -1){
        type = rand() % 7;
    }
    else{
        type = num;
    }

    switch (type){
        case 0:
            size = 4;
            matrice.resize(size, std::vector<bool>(size, 0));

            color = Color::Yellow;
            matrice = {
                {0, 0, 0, 0},
                {0, 1, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                };
                break;
            case 3:
                size = 4;
                matrice.resize(size, std::vector<bool>(size, 0));

                color = Color::Teal;
                matrice = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                };
                break;
            case 6:
                size = 3;
                matrice.resize(size, std::vector<bool>(size, 0));

                color = Color::Red;
                matrice = {
                {0, 0, 0},
                {0, 1, 1},
                {1, 1, 0},
                };
                break;
            case 5:
                size = 3;
                matrice.resize(size, std::vector<bool>(size, 0));

                color = Color::Green;
                matrice = {
                {0, 0, 0},
                {1, 1, 0},
                {0, 1, 1},
                };
                break;
            case 1:
                size = 3;
                matrice.resize(size, std::vector<bool>(size, 0));

                color = Color::Orange;
                matrice = {
                {0, 0, 0},
                {1, 1, 1},
                {1, 0, 0},
                };
                break;
            case 2:
                size = 3;
                matrice.resize(size, std::vector<bool>(size, 0));

                color = Color::Blue;
                matrice = {
                {0, 0, 0},
                {1, 1, 1},
                {0, 0, 1},
                };
                break;
            case 4:
                size = 3;
                matrice.resize(size, std::vector<bool>(size, 0));

                color = Color::Purple;
                matrice = {
                {0, 0, 0},
                {0, 1, 0},
                {1, 1, 1},
                };
                break; 
                
        }
    
    pos.x = 4;
    pos.y = -2;    
}
    
void Shape::print_block_cell()
{
    attron(COLOR_PAIR(8));
    int startY = 5;
    int startX = 82;
    
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
