#ifndef GROOK_H
#define GROOK_H
#include "../rook.h"

class GRook : public Rook
{
  private:
    bool rock = false;
  public:
    GRook(int x, int y, int it);
    ~GRook();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
    bool isRock() const;
    void Rock();
};
#endif
