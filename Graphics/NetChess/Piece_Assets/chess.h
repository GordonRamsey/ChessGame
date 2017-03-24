#ifndef CHESS_H
#define CHESS_H
#include "piece.h"

class Chess
{
  private:
    Piece* board [14][14];
    vector<Piece>* pieces;

  public:
    //Set position of piece on board
    void setPos(int num, int x, int y);
    //remove piece from board
    void removePiece(int num);


};
#endif
