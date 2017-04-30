#ifndef NPAWN_H
#define NPAWN_H
#include "../pawn.h"
class NPawn : public Pawn
{
  private:
    Piece* bitten = NULL;
  public:
    NPawn(int x, int y, int it, char state);
    ~NPawn();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
