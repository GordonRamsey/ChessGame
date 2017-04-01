#ifndef FQUEEN_H
#define FQUEEN_H
#include "queen.h"

class Queen : public Piece
{
  private:
    bool m_level;
  public:
    Queen(int x, int y, int it);
    ~Queen();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
