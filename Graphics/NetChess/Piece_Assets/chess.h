#ifndef CHESS_H
#define CHESS_H
#include "piece.h"

class Chess
{
  public:
    int validspots [14][14] =
    {{0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0}};
    
    Piece* board [14][14];
    vector<Piece>* pieces;

    Chess();
    ~Chess();
    
    //Set position of piece on board
    void setPiecePos(int num, int x, int y);
    //remove piece from board
    void removePiece(int num);
    bool isValid(int x, int y);


};
#endif
