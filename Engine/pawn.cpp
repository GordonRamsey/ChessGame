#include "pawn.h"
using namespace std;

vector<coords> Pawn::AllPos()
{
	coord temp;
	vector<coord> set;
        
		if(m_first == true)
		{
            //should we check out of bounds?
			temp.y = m_position.y + 2;
			temp.x = m_position.x + 0;
			set.push_back(temp);
		}
		//Directly "in front of" the pawn
		temp.y = m_position.y + 1;
		temp.x = m_position.x + 0;
		if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp);
		//Diagonal left:
		temp.y = m_position.y + 1;
		temp.x = m_position.x - 1;
		if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp);

		//Diagonal right:
		temp.y = m_position.y + 1;
		temp.x = m_position.x + 1;
		if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp);
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

