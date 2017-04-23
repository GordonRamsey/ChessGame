#include "Frook.h"

FRook::FRook(int x, int y, int it) : Rook(x, y, it)
{
  debug_name = "Frook";
}

FRook::~FRook()
{}

string FRook::Move(coord newpos)
{
  return Rook::Move(newpos);
}

vector<coord> FRook::validSpots(Chess* c)
{
  stringstream ss;
  coord seek;
  coord tempseek; 
  if(!m_level)
    return Rook::validSpots(c);

  vector<coord> spots;
  seek = getSpot(); 
  //Check North  
  while(true){
    seek.y-=1;
    if(seek.y < 0)//Out of bounds
      break; 
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;

    //Check seek spot
    cerr << "[FROOK] Checking spot:" << seek.x << "," << seek.y << endl;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek); 
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~"; 
	captureMap[seek] = ss.str();
	break;
      }
      else
	break;
    }

    //look to the right
    tempseek.x = seek.x+1; 
    tempseek.y = seek.y; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.x > 13 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	}
      }
    }

    //look to the left 
    tempseek.x = seek.x-1; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.x < 0 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	} 
      }
    }	
    spots.push_back(seek);
  }
  //Check South
  seek = getSpot(); 
  while(true){
    seek.y+=1;
    if(seek.y > 13)//Out of bounds
      break; 
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;

    //Check seek spot
    cerr << "[FROOK] Checking spot:" << seek.x << "," << seek.y << endl;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek); 
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~"; 
	captureMap[seek] = ss.str();
	break;
      }
      else
	break;
    }

    //look to the left
    tempseek.x = seek.x+1; 
    tempseek.y = seek.y; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.x > 13 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	}
      }
    }

    //look to the right; 
    tempseek.x = seek.x-1; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.x < 0 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	} 
      }
    }
    spots.push_back(seek); 
  }
  //Check Left
  seek = getSpot(); 
  while(true){
    seek.x-=1;
    if(seek.x < 0)//Out of bounds
      break; 
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;

    //Check seek spot
    cerr << "[FROOK] Checking spot:" << seek.x << "," << seek.y << endl;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek); 
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~"; 
	captureMap[seek] = ss.str();
	break;
      }
      else
	break;
    } 

    //look up
    tempseek.x = seek.x; 
    tempseek.y = seek.y-1; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.y < 0 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	}
      }
    }

    //look down; 
    tempseek.y = seek.y+1; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.y > 13 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	} 
      }
    }
    spots.push_back(seek); 
  }
  //Check Right
  seek = getSpot(); 
  while(true){
    seek.x+=1;
    if(seek.x > 13)//Out of bounds
      break; 
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;

    //Check seek spot
    cerr << "[FROOK] Checking spot:" << seek.x << "," << seek.y << endl;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek); 
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~"; 
	captureMap[seek] = ss.str();
	break;
      }
      else
	break;
    } 

    //look up
    tempseek.x = seek.x; 
    tempseek.y = seek.y-1; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.y < 0 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	}
      }
    }

    //look to the right; 
    tempseek.y = seek.y+1; 
    cerr << "[FROOK] Checking alt spot:" << tempseek.x << "," << tempseek.y << endl;
    if(!(tempseek.y > 13 || c->validspots[tempseek.x][tempseek.y] == 0)){
      if(c->board[tempseek.x][tempseek.y] != NULL){
	if(c->board[tempseek.x][tempseek.y]->getTeam() != getTeam()){
	  spots.push_back(tempseek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[tempseek.x][tempseek.y]->getNum() << " ~"; 
	  captureMap[tempseek] = ss.str(); 
	} 
      }
    }
    spots.push_back(seek); 
  }
  return spots;
}
