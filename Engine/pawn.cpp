#include "pawn.h"
using namespace std;

vector<coords> Pawn::isValid()
{
	coord temp;
	vector<coord> set;

	//Checking what color first.
    if (m_color == 'w')
    {
		if(m_first == true)
		{
			temp.y = m_position.y + 2;
			temp.x = m_position.x + 0;
			set.push_back(temp);
		}
		//Directly "in front of" the pawn
		temp.y = m_position.y + 1;
		temp.x = m_position.x + 0;
		set.push_back(temp);

		//Diagonal left:
		temp.y = m_position.y + 1;
		temp.x = m_position.x - 1;
		set.push_back(temp);

		//Diagonal right:
		temp.y = m_position.y + 1;
		temp.x = m_position.x + 1;
		set.push_back(temp);
		
	}

	else if (m_color == 'b')
	{
		if (m_first == true)
		{
			temp.y = m_position.y - 2;
			temp.x = m_position.x + 0;
			set.push_back(temp);
		}
		//Directly "in front of" the pawn:
		temp.y = m_position.y - 1;
		temp.x = m_position.x + 0;
		set.push_back(temp);

		//Diagonal left:
		temp.y = m_position.y - 1;
		temp.x = m_position.x - 1;
		set.push_back(temp);

		//Diagonal right:
		temp.y = m_position.y - 1;
		temp.x = m_position.x + 1;
		set.push_back(temp);

	} 
}

void Pawn::Move(const string position)
{
	//After it has been moved, it's not the pawn's first move
	//This may mess up though if the move isn't valid, because
	//this function will be called and set m_first to be true
	//even though it didn't actually move.
    if(m_first == false)    
    {
        m_first == true;
    }
    setPosition(position);
}

