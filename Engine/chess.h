#ifndef CHESS_H
#define CHESS_H
#include "piece.h"
#include <vector>


class Chess{
    public:  

        Piece* game_board[8][8]
        vector<coord> WLocs; 
        vector<coord> BLocs; 
        vector<coord> validPos; //for 1st and 2nd click 
        vector<coord> captureable; //for 2nd click 
        Piece* cur_piece;

        Chess();
        ~Chess();
        vector<coord> PotentialMoves(Piece* board);
        bool Move(coord);
        vector<coord> CaptureableMoves() const;
        bool Move(const coord place);

};
#endif
