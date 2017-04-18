#ifndef WBISHOP_H
#define WBISHOP_H
#include "../bishop.h"
class WBishop : public Bishop
{
	private:
		string debug_name;
	public:
		WBishop(int x, int y, int it);
		~WBishop();
		string Move(coord newpos);
		vector<coord> validSpots(Chess* c);
};
#endif
