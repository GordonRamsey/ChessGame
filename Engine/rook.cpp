#include "rook.h"
using namespace std;

Rook::Rook()
{
    m_name = "Rook"; 
}

Rook::~Rook()
{}

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

bool Rook::isAlly(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(int y, int x);

    if(myColor == TmpColor)
        return true;
    else
        return false;
}

bool Rook::isEnemy(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(int y, int x);

    if(TmpColor != myColor)
        return true; 
    else 
        return false; 
}

bool Rook::isEmpty(int y, int x)
{
    char TmpColor = getTmpcolor(int y, int x);
    
    if(tmpColor == 'e')
        return true; 
    else
        return false; 
}

void Rook::ValidMoves(int cp_y, int cp_x, &vector<coord>captureable, &vector<coord>validPos)
{
    coord temp, cap, valid; 
    temp.y = cp_y-1; 
    temp.x = cp_x; 
    //move up(w) down(b)
    while(temp.y >= 0)
    {
        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.y -= 1;
    }
    temp.y = cp_y+1;
    //move down(w) up(b)
    while(temp.y < 8)
    {

        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if((isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.y += 1; 
    }
    temp.y = cp_y;
    temp.x=cp_x-1;
    //move right(w) left(b)
    while(temp.x >= 0)
    {

        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEmpty(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.x-=1;
    }
    temp.x = cp_x+1;
    //move left(w) right(w)
    while(temp.x < 8)
    {

        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEmpty(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.x+=1; 
}
void Rook::Move(const string posiiton)
{
  //Check if valid, then:  
  setPosition(position);
}

string Rook::getName() const
{
    return m_name; 
}

string Rook::setName(const string name)
{
    m_name = name; 
}
