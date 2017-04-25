#ifndef PIECE_H
#define PIECE_H

#include <SDL/SDL.h>
#include <vector>
#include <string>
#include "chess.h"
#include <sstream>
#include <iostream>
#include <map>


using namespace std;

class Piece {

    private:
	//SDL Necessary variables
	SDL_Rect box; //Bounding box of sprite
	SDL_Rect* clip; //Sprite of... sprite
	int clip_num; //Number on clips sheet
	int num; //Piece number, for network purposes
	SDL_Surface* sheet;
	int owner;
    
    protected:
	bool rock = false;
    
    public:
        
	bool m_level = false;
    Piece(int x, int y, int num); //Constructor
    ~Piece();//Deconstructor
    Piece& operator=(const Piece& other);
        
	string debug_name;
	map <coord,string> captureMap;//postions that we can capture
        
	coord getPos() const;
    void setPos(int x, int y);
        
	//Called to give a network message to spawn other things
    virtual string Move(coord newpos) { return "DEFAULT MOVE"; }

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


        //Used in Moving and Capturing
    virtual vector<coord> validSpots(Chess* c) 
      { vector<coord> empty;
        return empty; }

	string getCaptCmd(coord spot);

	//Used for special unit commands
	int clicks = 0;
	int getClicks() { return clicks; }
    virtual string processClicks(vector<coord> clickedOn, Chess* c) 
      { return "DEFAULT"; }

	int isLevel() { return m_level; }
	void levelUp();

	//For golems
	bool isRock(){ return rock; }
        void Rock();	

	//For necros and walls
        string turnPass() { return "DEFAULT"; }
};
#endif
