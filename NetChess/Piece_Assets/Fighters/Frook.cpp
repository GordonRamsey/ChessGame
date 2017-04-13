#include "Frook.h"

FRook::FRook(int x, int y, int it) : Rook(x, y, it)
{
    debug_name = "Frook";
}

FRook::~FRook()
{}

string FRook::Move(coord newpos)
{
	stringstream ss;
	ss << "[MOVE-Rook]" << newpos.x << "," << newpos.y << endl;
	return ss.str()
}

vector<coord> FRook::validSpots(Chess* c)
{
	coord seek;
    coord tempseek; 
	if(!m_level)
		return Rook::validSpots(c);

	vector<coord> spots(Rook::validSpots(c));
    seek = getSpot(); 
    //Check North  
    while(true){
        seek.y-=1;
        if(seek.y < 0 or seek.x > 13)//Out of bounds
            break; 
        if(c->validspots[seek.x][seek.y] == 0)//valid spot
            break;

        //look to the left
        tempseek.x = seek.x+1; 
        tempseek.y = seek.y; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            }
            else break; 
        }

        //look to the right; 
        tempseek.x = seek.x-1; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            } 
        else break; 
        }
        spots.push_back(seek); 
    }
    //Check South
    while(true){
        seek.y+=1;
        if(seek.y < 0 or seek.x > 13)//Out of bounds
            break; 
        if(c->validspots[seek.x][seek.y] == 0)//valid spot
            break;

        //look to the left
        tempseek.x = seek.x+1; 
        tempseek.y = seek.y; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            }
            else break; 
        }

        //look to the right; 
        tempseek.x = seek.x-1; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            } 
        else break; 
        }
        spots.push_back(seek); 
    }
    //Check Left
    while(true){
        seek.x-=1;
        if(seek.y < 0 or seek.x > 13)//Out of bounds
            break; 
        if(c->validspots[seek.x][seek.y] == 0)//valid spot
            break;

        //look up
        tempseek.x = seek.x; 
        tempseek.y = seek.y-1; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            }
            else break; 
        }

        //look down; 
        tempseek.y = seek.y+1; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            } 
        else break; 
        }
        spots.push_back(seek); 
    }
    //Check Right
	while(true){
        seek.x+=1;
        if(seek.y < 0 or seek.x > 13)//Out of bounds
            break; 
        if(c->validspots[seek.x][seek.y] == 0)//valid spot
            break;

        //look up
        tempseek.x = seek.x; 
        tempseek.y = seek.y-1; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            }
            else break; 
        }

        //look to the right; 
        tempseek.y = seek.y+1; 
        if(c->board[tempseek.x][tempseek.y] != NULL){
            if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
                spots.push_back(tempseek); 
                ss.str("");
                ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
                captureMap(tempseek) = ss.str(); 
                break; 
            } 
        else break; 
        }
        spots.push_back(seek); 
    }
}
