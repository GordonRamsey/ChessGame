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

char King::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char b, w, e; 
    int temp_y = y;
    int temp_x = x; 
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

char King::isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)

{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    if(myColor == TmpColor)
        return true;
    else
        return false; 
}

bool King::isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    if(TmpColor != myColor) 
        return true; 
    else 
        return false; 
}

bool King::isEmpty(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 
    if(TmpColor == 'e')
        return true; 
    else 
        return false; 
}

void King::ValidMoves(cp.y, cp.x, char myColor, vector<coord> captureable, vector<coord> validPos, vector<coord> WLocs, vector<coord> BLocs)
{
    coord cap, valid; 
    int temp_y = cp.y; 
    int temp_x = cp.x; 
    //move forward (w) back (b)  
    while(tmp_y >= 0)
    {
        temp_y -= 1; 
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
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
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
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
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
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
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
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
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
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
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
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
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
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
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

