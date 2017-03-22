#include <SDL/SDL.h>

#ifndef PIECE_H
#define PIECE_H

struct coord {
    int x;
    int y;
};

class Piece {

    private:
        char m_color; // 'w' is white, 'b' is black
        coord m_position; // initially will be set to "", chess functions will handle set up. Positions range from "A1" to "H8", where 1-8 is the y-axis and A-H is the x-axis
        bool m_captured; //Initially set to false in constructor. We could just use the pieces position to determine if it's empty or not, but this seems faster since we can just negate the function call

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
        
        //Accessors and Mutators
        char getColor() const;
        void setColor(const char color);
        
        coord getPos() const;
        void setPos(int x, int y);
        
        bool getCaptured() const;
        void setCaptured(const bool captured);

	//SDL Functions
	void handle_events();
	void show();
	int  getNum();
	
	void setClip(int x);
	int  getClip();
	
	coord getSpot();
	
	void setTeam(int x);
	int  getTeam();

	void setAlpha(int x);

};
#endif
