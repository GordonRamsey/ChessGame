#include "Nking.h"
using namespace std;

NKing::NKing(int x, int y, int it) : King(x, y, it)
{
    debug_name = "Nking";
}

NKing::~NKing()
{}

string NKing::Move(coord newpos)
{
  return King::Move(newpos);
}

vector<coord> NKing::validSpots(Chess* c)
{
  return King::validSpots(c);
}
vector<coord> NKing::validSLoc(Chess* c)
{
    coord seek; 
    coord spot; 
    vector<coord>validSpot; 
    seek = getSpot(); 
    //up
    spot.x = seek.x; 
    spot.y = seek.y-1; 
    if((spot.y >= 0) && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot); 
    //down
    spot.x = seek.x; 
    spot.y = seek.y+1; 
    if((spot.y < 14) && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot);
    //left
    spot.x = seek.x-1; 
    spot.y = seek.y; 
    if((spot.x >= 0) && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot);
    //right
    spot.x = seek.x+1; 
    spot.y = seek.y; 
    if((spot.x < 14) && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot);
    //top left
    spot.x = seek.x-1; 
    spot.y = seek.y-1; 
    if(spot.x >= 0 && spot.y >= 0 && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot);   
    //top right
    spot.x = seek.x+1; 
    spot.y = seek.y-1; 
    if(spot.x < 14 && spot.y >= 0 && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot);
    //bottom left
    spot.x = seek.x-1; 
    spot.y = seek.y+1; 
    if(spot.y < 14 && spot.x >= 0 && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot);
    //bottom right
    spot.x = seek.x+1; 
    spot.y = seek.y+1; 
    if(spot.x < 14 && spot.y < 14 && (c->validspots[spot.x, spot.y] != 0))
        validSpot.push_back(spot);


    return validSpot; 
}

bool NKing::isValid(vector<coord> validSLoc, vector<coord> clickedOn, Chess* c)
{

    int count = 0; 
    for(int i = 0; i < clickedOn.size(); ++i){
        for(int j = 0; j < validSLoc.size(); ++j){
            if(clickedOn[i] == validSLoc[j])
                ++count; 
        }
    }


    if(count <= 3 && count != 0)
        return true; 
    else 
        return false; 
}

string NKing::processClicks(vector<coord> clickedOn, Chess* c)
{

    stringstream ss; 
    if(clickedOn.size() != 1)
        return "ERROR"; 

    if(clickedOn[0] == getPos())
    {
        vector<coord> tmp(validSLoc(c));  
        if(isValid(tmp, clickedOn, c))
        {
            ss.str(""); 
            ss << "MOVE " << getNum() << " " << getPos().x << getPos().y << " ~"; 
            for(int i = 1; i < clickedOn.size(); ++i){
                ss << "PLAC Npawn" << clickedOn[i].x << clickedOn[i].y << " ~"; 
            }
            return ss.str(); 
        }
        else
            return "DEFAULT"; 

    }

  return "DEFAULT"; 
}
