#include <SDL/SDL.h>
#include <vector>
#include <string>
#include "chess.h"

#ifndef PIECE_H
#define PIECE_H

using namespace std;

struct coord {
    int x;
    int y;
};

class Piece {

    private:
	//SDL Necessary variables
	SDL_Rect box; //Bounding box of sprite
	SDL_Rect* clip; //Sprite of... sprite
	int clip_num; //Number on clips sheet
	int num; //Piece number, for network purposes
	SDL_Surface* sheet;
	int owner;

    public:
        
        Piece(int x, int y, int num); //Constructor
        ~Piece();//Deconstructor
        Piece& operator=(const Piece& other);
        
        coord getPos() const;
        void setPos(int x, int y);
       
        string Move(coord original, coord newpos);

	//SDL Functions
	void handle_events();
	void show();
	int  getNum();
	
	void setClip(int x);
	int  getClip();
	
	coord getSpot();
	
	void setTeam(int x);
	int  getTeam();

	SDL_Surface* getSheet() { return sheet; }
	string toString();

	void setAlpha(int x);

        virtual vector<coord> validSpots(Chess* c) { };

};
#endif
