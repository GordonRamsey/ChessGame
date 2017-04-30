#ifndef WROOK_H
#define WROOK_H
#include "../rook.h"
class WRook : public Rook
{
	private:
		string debug_name;
	public:
		WRook(int x, int y, int it);
		~WRook();
		string Move(coord newpos);
		vector<coord> validSpots(Chess* c);
}
#endif
