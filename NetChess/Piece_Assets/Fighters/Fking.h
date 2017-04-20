#ifndef FKING_H
#define FKING_H
#include "../king.h"
#include <string>
class FKing : public King
{
  private:
	string debug_name;
  public:
    FKing(int x, int y, int it);
    ~FKing();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string Morale(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
    void levelUp();
};
#endif
