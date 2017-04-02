#ifndef FPAWN_H
#define FPAWN_H
#include "pawn.h"
class FPawn : public Pawn
{
	private:
		bool m_level;

	publice:
		FPawn(int x, int y, int it);
		~FPawn();
		string Move(coord newpos);
		vecotr<coord> validSpots(Chess* c);
};
#endif
