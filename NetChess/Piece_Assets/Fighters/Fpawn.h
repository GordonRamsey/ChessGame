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
		vector<coord> validSpots(Chess* c);
        string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
