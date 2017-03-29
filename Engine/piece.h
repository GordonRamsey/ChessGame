#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>
using namespace std;
struct coord {
    int x;
    int y;
};

class Piece {

    private:
        char m_color;
        bool m_captured;
        coord m_position;

	//SDL Necessary variables
/*	SDL_Rect box; //Bounding box of sprite
	SDL_Rect* clip; //Sprite of... sprite
	int clip_num; //Number on clips sheet
	int num; //Piece number, for network purposes
	SDL_Surface* sheet;
	int owner;
*/
    public:
        
        Piece(int x, int y); //Constructor
        ~Piece();//Deconstructor
        
        //Accessors and Mutators
        char getColor() const;
        void setColor(const char color);
        
        coord getPos() const;
        void setPos(int x, int y);
        
        bool getCaptured() const;
        void setCaptured(const bool captured);
        virtual void ValidMoves(int cp_y, int cp_x, char myColor, vector<coord> &captureable, vector<coord> &validPos, vector<coord> WLocs, vector<coord> BLocs) =0;
	
	//SDL Functions
/*	void handle_events();
	void show();
	int  getNum();
	
	void setClip(int x);
	int  getClip();
	
	coord getSpot();
	
	void setTeam(int x);
	int  getTeam();

	void setAlpha(int x);
*/
};
#endif
