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
            return 'c'
    }

    return 'e'
}

bool Pawn::isAlly(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 
    if(TmpColor == myColor)
        return true; 
    else
        return false; 
}
y
bool Pawn::isEnemy(int y, int x, char myColor)
{
    char TmpColor == getTmpColor(y,x); 
    if(TmpColor != myColor)
        return true; 
    else 
        return false;
}

bool Pawn::isEmpty(int y, int x)
{
    char TmpColor = getTmpColor(y,x); 
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
void Pawn::ValidMoves(int cp.y, int cp.x, &vector<coord>captureable, &vector<coord>validPos)
{
	coord cap, valid; 
    int temp.y = cp.y; 
    int temp.x = cp.x; 

	if(firstMove(cp.y, cp.x))
	{
        if(myColor == 'w')
        {
            temp.y = temp.y-2; 
            temp.x = cp.x;  
            if(isAlly(temp.y, temp.x))
                break; 
            if(isEmpty(temp.y, temp.x))
            {
                valid.y = temp.y; 
                valid.x = temp.x; 
                validPos.push_back(valid);   
            }
            if(isEnemy(temp.y, temp.x))
                break; 
        }
        if(myColor == 'b')
        {
            temp.y = temp.y+2; 
            temp.x = cp.x;  
            if(isAlly(temp.y, temp.x))
                break; 
            if(isEmpty(temp.y, temp.x))
            {
                valid.y = temp.y; 
                valid.x = temp.x; 
                validPos.push_back(valid);   
            }
            if(isEnemy(temp.y, temp.x)) 
                break;                 
        }
	}
    
    if(myColor == 'w')
    {
        temp.y -= 1; 
        temp.x = cp.x; 
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
            cap.y = temp.y-1;
            cap.x = temp.x+1; //diagonal left
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            cap.y = temp.y-2; 
            cap.x = temp.x+2; //diagonal right 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    if(myColor == 'b')
    {
        temp.y += 1; 
        temp.x = cp.x; 
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
            cap.y = temp.y+1;
            cap.x = temp.x-1; //diagonal left
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            cap.y = temp.y+2; 
            cap.x = temp.x+2; //diagonal right 
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

