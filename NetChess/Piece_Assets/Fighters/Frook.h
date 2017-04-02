#ifndef FROOK_H
#define FROOK_H
#include "rook.h"
class FRook : public Rook
{
	private:
		bool m_level;

	public:
		FRook(int x, int y, int it);
		~FRook();
		string Move(coord newpos);
		vector<coord> validSpots(Chess* c);		
};
#endif
