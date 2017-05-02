#ifndef NBISHOP_H
#define NBISHOP_H
#include "../bishop.h"

class NBishop : public Bishop
{
  private:
  public:
    NBishop(int x, int y, int it);
    ~NBishop();
    string Move(coord newpos);
    bool checkSpawn(coord spot, Chess* c);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c); 
};
#endif
