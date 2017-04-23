#ifndef GQUEEN_H
#define GQUEEN_H
#include "../queen.h"

class GQueen : public Queen
{
  private:
  public:
    GQueen(int x, int y, int it);
    ~GQueen();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
    bool isRock() const;
    void Rock();
};
#endif
