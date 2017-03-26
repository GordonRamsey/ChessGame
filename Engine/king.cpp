#include "king.h"
using namespace std;

King::King()
{
    m_name = "King";
}

King::~King()
{}

char King::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord BLocs)
{
    char b, w, e; 
    int temp.y = y;
    int temp.x = x; 
    for(int b = 0, b < BLocs.size(); ++b)
    {
        if((temp.y == BLocs[b].y) && (temp.x == BLocs[b].x))
            return 'b';
        else
            continue; 
    }
    for(int w = 0; WLocs.size(); ++w)
    {
        if((temp.y == WLocs[b].y) && (temp.x == WLocs[b].x))
            return 'w'; 
        else
            continue; 
    }
    return 'e'; 
}

char King::isAlly(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 
    if(myColor == TmpColor)
        return true;
    else
        return false; 
}

bool King::isEnemy(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 
    if(tmpColor != myColor) 
        return true; 
    else 
        return false; 
}

void King::ValidMoves(cp_y, cp_x, vector<coord> captureable, vector<coord> validPos)
{
    coord cap, valid; 
    int temp.y = cp_y; 
    int temp.x = cp_x; 
    //move forward (w) back (b)  
    
    temp.y = cp_y-1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
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
            validPos.push_back(cap); 
        }
    }
    
    //move back(w) forward (b)
    temp.y = cp_y+1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //move right (w) left (b)

    temp.y = cp.y; 
    temp.x = cp_x-1; 

    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    
    //move left (w) right(b) 
    temp.x = cp_x+1; 

    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //D up, right
    temp.y = cp_y-1; 
    temp.x = cp_x-1; 

    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }

    }
    //D up, left
    temp.y = cp_y-1; 
    temp.x = cp_x+1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //D down, right
    temp.y = cp_y+1; 
    temp.x = cp_x-1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //D down, left
    temp.y = cp_y+1; 
    temp.x = cp_x+1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
}

void King::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}

string King::getName() const
{
    return m_name;
}

void King::setName(const string name)
{
    m_name = name;
}
