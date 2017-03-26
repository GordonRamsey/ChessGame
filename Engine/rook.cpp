#include "rook.h"
using namespace std;

vector<coord> Rook::AllPos()
{
    coord temp; 
    vector<coord> set; 
Rook::Rook()
{
    m_name = "Rook"; 
}

char Rook::getTmpcolor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    coord tmp; 
    char b, w, e; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((tmp.y == BLocs[b].y) && (tmp.x == BLocs[b].x))
            return 'b'; 
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((tmp.y == WLocs[w].y) && (tmp.x == BLocs[w].y))
                return 'w'; 
    }
    return 'e'; 
    
}

bool Rook::isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(int y, int x, WLocs, BLocs);

    if(myColor == TmpColor)
        return true;
    else
        return false;
}

bool Rook::isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(int y, int x, WLocs, BLocs);

    if(TmpColor != myColor)
        return true; 
    else 
        return false; 
}

bool Rook::isEmpty(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpcolor(int y, int x, WLocs, BLocs);
    
    if(tmpColor == 'e')
        return true; 
    else
        return false; 
}

void Rook::ValidMoves(int cp.y, int cp.x, char myColor, &vector<coord> captureable, &vector<coord> validPos, vector<coord>WLocs, vector<coord> BLocs)
{
    coord temp, cap, valid; 
    temp.y = cp.y; 
    temp.x = cp.x; 
    //move up(w) down(b)
    while(temp.y >= 0)
    {
        temp.y -= 1;
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.y -= 1; 
    }
    //move down(w) up(b)
    while(temp.y < 8)
    {
        temp.y += 1; 

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if((isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.y += 1; 
    }
    //move right(w) left(b)
    while(temp.x >= 0)
    {
        temp.x-=1;

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEmpty(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.x-=1; 
    }
    //move left(w) right(w)
    while(temp.x < 8)
    {
        temp.x+=1; 

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEmpty(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }
}
void Rook::Move(const string posiiton)
{
  //Check if valid, then:  
  setPosition(position);
}

void Rook::IsValid(coord Position, &vector<coord> allpos)
{
	
}

string Rook::getName() const
{
    return m_name; 
}

string Rook::setName(const string name)
{
    m_name = name; 
}
