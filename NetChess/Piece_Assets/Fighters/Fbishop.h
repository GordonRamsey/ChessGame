#ifndef FBISHOP_H
#define FBISHOP_H
#include "../bishop.h"
class FBishop : public Bishop
{
	private:
		bool m_level;

	public:
		FBishop(int x, int y, int it);
		~FBishop();
		string Move(coord newpos);
		vector<coord> validSpots(Chess* c);
};
#endif
