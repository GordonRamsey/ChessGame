#ifndef WPAWN_H
#define WPAWN_H
#include "../pawn.h"
class WPawn ; public Pawn
{
	private:
		string debug_name;
	public:
		WPawn(int x, int y, int it);
		~WPawn();
		string Move(coord newpos);
		vector<coord> validSpots(Chess* c);
};
#endif
