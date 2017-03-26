#include "bishop.h"
using namespace std;

Bishop::Bishop()
{
    m_name = "Bishop";
}

Bishop::~Bishop()
{}

string Bishop::getName() const
{
    return m_name;
}

void Bishop::setName(const string name)
{
    m_name = name;
}

void Bishop::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}

char Bishop::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char b, w, e; //E MEANS EMPTY
    int temp.y = y;
    int temp.x = x; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((temp.y == BLocs[b].y) && (temp.x == BLocs[b].x))
                return 'b';
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((temp.y == WLocs[w].y) && (temp.x == BLocs[w].y))
            return 'w'
    }
    else 
        return 'e'; 
}

bool Bishop::isAlly(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 
    
    if(myColor == TmpColor) 
        return true; 
    else
        return false; 
}

/* Here is where you are going to want to (1) go into chess.cpp and take the type, (2)check to see if it is a King so that we can (3)pass it in to our object 'info' to call checkmate */
bool Bishop::isEnemy(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 

    if(TmpColor != myColor) 
        return true; 
    else
        return false; 
}

bool Bishop::isEmpty(int y, int x)
{
    char TmpColor = getTmpColor(y,x); 

    if(tmpColor == 'e') 
        return true; 
    else 
        return false; 
}

void Bishop::ValidMoves(int cp.y, int cp.x, &vector<coord> captureable, &vector<coord>validPos)
{
    coord cap, valid; 
    int temp.y = cp.y; 
    int temp.x = cp.x; 
    //Move Diagonal up, right(w) AND down, left(b)  
    while((temp.y && temp.x) >= 0)
    {
        temp.y -= 1; 
        temp.x -= 1; 
            
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
        temp.x -= 1; 
    }

    //Move Diagonal down, right(w) AND up, left(b)
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

        temp.y += 1;  
        temp.x -= 1; 
       
    }   
    //Move Diagonal up, left(w) AND down, right(b)
    while((temp.y <= 0) && (temp.x < 8))
    {
        temp.y -= 1; 
        temp.x += 1; 
            
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
        temp.x += 1; 

    }   
    //Move Diagonal down, left(w) AND up, right(b)
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

        temp.y += 1; 
        temp.x += 1; 

    }        
}

