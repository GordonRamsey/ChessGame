#include "queen.h"
using namespace std;

vector<coords> Queen::isValid()
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
		set.push_back(temp)
	}

	//Moving vertically towards "bottom" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y - 1;
		temp.x = m_position.x + 0;
		set.push_back(temp)
	}

	//Moving horizontally towards "right" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 0;
		temp.x = m_position.x + 1;
		set.push_back(temp)
	}

	//Moving horizontally towards "left" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 0;
		temp.x = m_position.x - 1;
		set.push_back(temp)
	}

	//Moving diagonally towards "top right" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 1;
		temp.x = m_position.x + 0;
		set.push_back(temp)
	}

	//Moving diagonally towards "top left" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y + 1;
		temp.x = m_position.x - 1;
		set.push_back(temp)
	}

	//Moving diagonally towards "bottom right" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y - 1;
		temp.x = m_position.x + 1;
		set.push_back(temp)
	}

	//Moving diagonally towards "bottom left" of board:
	for (int i = 0; i < 8; ++i)
	{
		temp.y = m_position.y - 1;
		temp.x = m_position.x - 1;
		set.push_back(temp)
	}

}
void Queen::Move(const coord posiiton)
{
  //Check if valid move, then: 
  m_position = position;
}
