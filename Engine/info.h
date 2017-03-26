#ifndef INFO_H
#define INFO_H
#include "piece.h"


class Info{
    public:  
        Piece* game_board[8][8]
        vector<coord> WLocs; 
        vector<coord> BLocs; 
        vector<coord> validPos; //for 1st and 2nd click 
        char myColor; //returns the color of the 1st click
        int cp.y; //cur_piece y 
        int cp.x; //cur_piece x
        vector<coord> captureable; //for 2nd click 
}
