#ifndef FPAWN_H
#define FPAWN_H
#include "pawn.h"
class FPawn : public Pawn
{
	private:
        string debug_name;
	publice:
		FPawn(int x, int y, int it);
		~FPawn();
		string Move(coord newpos);
		vecotr<coord> validSpots(Chess* c);
};
#endif
