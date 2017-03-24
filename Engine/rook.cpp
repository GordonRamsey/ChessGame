#include "rook.h"
using namespace std;

Rook::Rook()
{
    m_name = "Rook"; 
}

Rook::~Rook()
{}


vector<coord> Rook::AllPos()
{
    int count = 0; 
    coords temp; 
    vector<coords> set; 

    //move up(w) down(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y - 1; 
        temp.x = m_position.x + 0; 
        
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
        else
            continue; 
    }
    //move down(w) up(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 1; 
        temp.x = m_position.x + 0; 
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
        else
            continue;
    }

    //move right(w) left(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 0; 
        temp.x = m_position.x - 1; 
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
        else
            continue;
    }

    //move left(w) right(w)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 0; 
        temp.x = m_position.x + 1; 
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
            ++count; 
        else
            continue;

}


void Rook::findCount(int count){
    return count; 
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
