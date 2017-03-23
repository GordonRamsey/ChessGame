#include "queen.h"
using namespace std;

Queen::Queen()
{
    m_name = "Queen";
}

Queen::~Queen()
{}

vector<coords> Queen::AllPos()
{
	coords temp;
	vector<coords> set;

	//Think we don't need to check color.
	//Queen can move the same no matter what color.

	//Moving vertically towards "top" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 1;
		temp.x = m_position.x + 0;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp); 
        else
            continue; 
	}

	//Moving vertically towards "bottom" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y - 1;
		temp.x = m_position.x + 0;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp);
        else
            continue;
	}

	//Moving horizontally towards "right" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 0;
		temp.x = m_position.x + 1;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp);
        else
            continue;
	}

	//Moving horizontally towards "left" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 0;
		temp.x = m_position.x - 1;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp);
        else
            continue;
	}

	//Moving diagonally towards "top right" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 1;
		temp.x = m_position.x + 0;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp);
        else
            continue;
	}

	//Moving diagonally towards "top left" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 1;
		temp.x = m_position.x - 1;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp);
        else
            continue;
	}

	//Moving diagonally towards "bottom right" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y - 1;
		temp.x = m_position.x + 1;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp);
        else
            continue;
	}

	//Moving diagonally towards "bottom left" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y - 1;
		temp.x = m_position.x - 1;
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0) 
		    set.push_back(temp);
        else
            continue;
	}

}

string Queen:getName() const
{
    return m_name;
}

void Queen::setName(const string name)
{
    m_name = name;
}
void Queen::Move(const coord posiiton)
{
  //Check if valid move, then: 
  m_position = position;
}
