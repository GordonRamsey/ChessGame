#ifndef WQUEEN_H
#define WQUEEN_H
#include "../queen.h"
class WQueen : public Queen
{
	private:
		string debug_name;
	public:
		WQueen(int x, int y, int it);
		~WQueen();
		string Move(coord newpos);
		vector<coord> validSpots(Chess* c);
};
#endif
