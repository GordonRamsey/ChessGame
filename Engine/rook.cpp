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
        for(int w = 0; w < WLocs.size(); ++w)
        {
            if((tmp.y == BLocs[b].y) && (tmp.x == BLocs[b].x))
                return 'b'; 
            if((tmp.y == WLocs[w].y) && (tmp.x == BLocs[w].y))
                return 'w'; 
            else
                return 'e'
        }
    }
}

bool Rook::isAlly(int y, int x)
{
    char TmpColor = getTmpColor(int y, int x);

    if(myColor == TmpColor)
        return true;
    else
        return false;
}

bool Rook::isEnemy(int y, int x)
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

void Rook::ValidMoves(int cp.y, int cp.x, &vector<coord>captureable, &vector<coord>validPos)
{
    coord temp, cap, valid; 
    temp.y = cp.y; 
    temp.x = cp.x; 
    //move up(w) down(b)
    while(temp.y >= 0)
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
            valid.push_back(cap); 
            break; 
        }

        temp.y -= 1; 
    }
    //move down(w) up(b)
    while(temp.y < 8)
    {
        temp.y += 1; 

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
        }

        temp.y += 1; 
    }
    //move right(w) left(b)
    while(temp.x >= 0)
    {
        temp.x-=1;

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
        }

        temp.x-=1; 
    }
    //move left(w) right(w)
    while(temp.x < 8)
    {
        temp.x+=1; 

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
        }

        temp.x+=1;
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
