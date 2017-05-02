#ifndef WPAWN_H
#define WPAWN_H
#include "../pawn.h"
class WPawn : public Pawn
{
  private:
    string debug_name;
  public:
    WPawn(int x, int y, int it, char dir);
    ~WPawn();
    void wurmSpots(vector<coord> &spots, Chess* c);
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
