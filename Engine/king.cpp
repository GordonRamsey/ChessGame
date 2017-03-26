#include "king.h"
using namespace std;

King::King()
{
    m_name = name;
}

King::~King()
{}

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

void King::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}

char King::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
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

void King::ValidMoves(cp.y, cp.x, vector<coord> captureable, vector<coord> validPos)
{
    coord cap, valid; 
    int temp.y = cp.y; 
    int temp.x = cp.x; 
    //move forward (w) back (b)  
    while(tmp.y >= 0)
    {
        temp.y -= 1; 
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
            validPos.push_back(cap); 
            break; 
        }
        temp.y -= 1; 
    }
    //move back(w) forward (b)
    while(temp.y < 8)
    {
        temp.y += 1; 
        temp.x = cp.x; 
        if(isAlly(temp.y, temp.x))
            break; 
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
            break;
        }
    }
    //move right (w) left (b)
    while(temp.x >= 0)
    {
        temp.y = cp.y; 
        temp.x -= 1; 
        if(isAlly(temp.y, temp.x))
            break; 
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
            break;
        }
        temp.y = cp.y; 
        temp.x -= 1;
    }
    //move left (w) right(b) 
    while(temp.x < 8)
    {
        temp.y = cp.y; 
        temp.x += 1; 
        if(isAlly(temp.y, temp.x))
            break; 
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
            break; 
        }
        temp.y = cp.y; 
        temp.x += 1;
    }
    //D up, right
    while((temp.y >= 0) && (temp.x >= 0))
    {
        temp.y -= 1; 
        temp.x -= 1; 
        if(isAlly(temp.y, temp.x))
            break; 
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
            break; 
        }
        temp.y -= 1; 
        temp.x -= 1; 
    }
    //D up, left
    while((temp.y >= 0) && (temp.x < 8))
    {
        temp.y -= 1; 
        temp.x += 1; 
        if(isAlly(temp.y, temp.x))
            break; 
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
            break;
        }
        temp.y -= 1; 
        temp.x -= 1;
    }
    //D down, right
    while((temp.y < 8) && (temp.x >= 0))
    {
        temp.y += 1; 
        temp.x -= 1; 
        if(isAlly(temp.y, temp.x))
            break; 
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
            break; 
        }
        temp.y += 1; 
        temp.x -= 1; 
    }
    //D down, left
    while((temp.y < 8) && (temp.x < 8))
    {
        temp.y += 1; 
        temp.x += 1; 
        if(isAlly(temp.y, temp.x))
            break; 
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
            break; 
        }
        temp.y += 1;
        temp.x += 1; 
    }
}

