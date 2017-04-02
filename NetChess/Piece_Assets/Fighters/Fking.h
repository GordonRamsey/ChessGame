#ifndef FKING_H
#define FKING_H
#include "king.h"
class FKing : public King
{
  private:
	bool m_level;

  public:
    FKing(int x, int y, int it);
    ~FKing();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
