#ifndef WKING_H
#define WKING_H
#include "../king.h"
class WKing : public King
{
	private:
		string debug_name;
	public:
		WKing(int x, int y, int it);
		~WKing();
		string Move(coord newpos);
		vector<coord> validSpots(Chess* c);
};
#endif
