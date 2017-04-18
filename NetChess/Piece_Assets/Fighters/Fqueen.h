#ifndef FQUEEN_H
#define FQUEEN_H
#include "../queen.h"

class FQueen : public Queen 
{
  private:
    string debug_name;
  public:
    FQueen(int x, int y, int it);
    ~FQueen();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
