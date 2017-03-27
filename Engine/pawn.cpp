#include "pawn.h"
using namespace std;

Pawn::Pawn()
{
    m_name = "Pawn";
}

Pawn::~Pawn()
{}
char Pawn::getTmpColor(int y, int x, vector<coord>WLocs, vector<coord>BLocs)
{
    char b, w, e; 
    int temp.y = y; 
    int temp.x = x; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((temp.y == BLocs[b].y) && (temp.x == BLocs[b].x))
            return 'b'; 
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((temp.y == WLocs[w].y) == (temp.x == WLocs[w]
            return 'c'; 
    }

    return 'e'; 
}

bool Pawn::isAlly(int y, int x, char myColor, vector<coord>WLocs, vector<coord>BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 
    if(TmpColor == myColor)
        return true; 
    else
        return false; 
}

bool Pawn::isEnemy(int y, int x, char myColor, vector<coord>WLocs, vector<coord>BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 
    if(TmpColor != myColor)
        return true; 
    else 
        return false;
}

bool Pawn::isEmpty(int y, int x, vector<coord>WLocs, vector<coord>BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 
    if(TmpColor == 'e')
        return true; 
    else
        return false; 
}

bool Pawn::firstMove(int y, int x, char myColor)
{
    if(myColor == 'w')
    {
        if((y == 6) && (x < 8))
            return true; 
    }
    if(myColor == 'b')
    {
        if((y == 1) && (x < 8))
            return true; 
    }
    
    return false; //won't ever care if its empty
}

/*You will want to clear both vectors after 2nd click? */
void Pawn::ValidMoves(int cp.y, int cp.x, char myColor, &vector<coord>captureable, &vector<coord>validPos, vector<coord> WLocs, vector<coord> BLocs)
{
	coord cap, valid; 
    int temp.y = cp_y; 
    int temp.x = cp_x; 

	if(firstMove(cp_y, cp_x, myColor))
	{
        if(myColor == 'w')
        {
            temp.y = cp_y-2; 
            temp.x = cp_x;  
            if(isAlly(temp.y, temp.x))
            if(isEmpty(temp.y, temp.x))
            {
                valid.y = temp.y; 
                valid.x = temp.x; 
                validPos.push_back(valid);   
            }
            if(isEnemy(temp.y, temp.x))
        }
        if(myColor == 'b')
        {
            temp.y = cp_y+2; 
            temp.x = cp_x;  
            if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            if(isEmpty(temp.y, temp.x, WLocs, BLocs))
            {
                valid.y = temp.y; 
                valid.x = temp.x; 
                validPos.push_back(valid);   
            }
            if(isEnemy(temp.y, temp.x, myColor, WLocs, Blocs)) 
        }
	}
    
    if(myColor == 'w')
    {
        temp.y = cp_y-1; 
        temp.x = cp_x; 
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        //Check for Diagonal Enemies
        temp.y = cp_y-1;
        temp.x = cp_x-1;
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y;
            cap.x = temp.x; //diagonal left
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
        temp.y = cp_y-1;
        temp.x = cp_x+1; 
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y;
            cap.x = temp.x;
            captureable.push_back(cap);
            validPos.push_back(temp);
        }

    }
    if(myColor == 'b')
    {
        temp.y = cp_y+1; 
        temp.x = cp_x; 
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        
        temp.y = cp_y+1;
        temp.x = cp_x-1;
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y;
            cap.x = temp.x; //diagonal left
            captureable.push_back(cap); 
            validPos.push_back(cap);          
        }
        
        temp.y = cp_y+1;
        temp.x = cp_x+1;
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; //diagonal right 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }

}

string Pawn::getName()const
{
    return m_name;
}

void Pawn::setName(const string name)
{
    m_name = name;
}

void Pawn::Move(const coord position)
{
    //Will only be called if the piece is moved
    if(m_first == false)    
    {
        m_first == true;
    }
    m_position = position;
}

