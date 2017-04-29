#include "Socket.h"
#include <vector>
#include <iostream>
#include <sstream>

struct player{
  Socket sock;
  int number;
  int team = -1;
  bool alive = true;
};

Socket listener;
vector<Socket> sockets;
vector<player> players;
stringstream ss;

bool game_start = false;
int faction_confirm = 0;
int current_player = 1;
int alive_players = -1;

void startGame(SocketSet socs)
{
  cout << "[BEGINNING GAME]" << endl;
  cerr << "[CURRENT PLAYER] = " << current_player << endl;
  socs.wait(2);
  game_start = true;
  alive_players = 4;
  ss.str("");
  ss << "STRT ~";
  for(unsigned int i=0;i<sockets.size();i++){
    sockets[i].writeString(ss.str());
  }
}

void nextPlayer()
{
  current_player++;
  
  if(current_player > players.size())
    current_player = 1;
  
  if(players[current_player-1].alive == false){  
    cerr << "Player " << current_player << " is ded" << endl;
    nextPlayer();
  }

  cerr << "[CURRENT PLAYER] = " << current_player << endl;
  ss.str("");
  ss << "TURN " << current_player << " ~";

  for(int j=0;j<sockets.size(); ++j)
    sockets[j].writeString(ss.str());
}

int main(int argc, char* argv[])
{
  int player_num = 1;
  SocketSet socketSet;
  listener.listen(argv[1]);
  listener.joinGroup(&socketSet);
  string msg = "";
  cerr << "Server started, your IP information is:" << endl << listener.toString() << endl;

  while(!listener.isClosed()){
    //XXX Dont know why this is here
    socketSet.wait(2);

    //Client joining
    if(listener.hasEvent()){
      Socket sock = listener.accept();
      sock.joinGroup(&socketSet);
      cout << sock.toString() << " has joined\n";
      sockets.push_back(sock);
      
      ss.str("");
      ss << "REDY " << player_num << " ~";
      cerr << "Sending new Client player number:" << player_num << endl;
      sock.writeString(ss.str());

      player newplayer;
      newplayer.number = player_num;
      newplayer.sock = sock;
      players.push_back(newplayer);

      player_num++;
    }
    else //Messages from client
    {
      for(int i=sockets.size()-1; i >= 0; --i) {
	if(sockets[i].hasEvent()){
	  int bytes = sockets[i].readString(msg,255);
	  if(!sockets[i].isClosed())
	  {
	    cerr << "[MESSAGE]" << msg << "\n";

	    //Snip large messages so each command can be processed individually
	    //Necessary incase of HOLD clobbering
	    vector<string> snipped;
	    int cur = 0;
	    while(cur < msg.length()){
	      int snip = msg.find("~",cur);
	      if(snip == string::npos)//If message is invalid/corrupted do not process it
		break;
	      snipped.push_back(msg.substr(cur,snip-cur+1));
	      cur = snip + 1;
	    }

	    for(unsigned int s=0;s<snipped.size();s++)
	    {
	      msg = snipped[s];
	      cerr << "Processing message:" << msg << endl;

	      if(strncmp(msg.c_str(),"FACT",4) == 0)
	      {
		cerr << "FACT command recognized" << endl;
		string s_fact = "";
		s_fact += msg[5];
		int fact = atoi(s_fact.c_str());
		bool good = true;
		int index;
		//check if team already in use
		for(int j=0;j<players.size();j++){
		  if(players[j].sock == sockets[i])
		  {  
		    index = j;
		  }
		  
		  if(players[j].team == fact){
		    cerr << "Faction " << fact << " already in use" << endl;
		    sockets[i].writeString("BADD");
		    good = false;
		    break;
		  }
		}
		if(good)//If open, assign to player
		{
		  players[index].team = fact;
		  sockets[i].writeString("GOOD");
		  cerr << "Player " << players[index].number << " faction set to " << fact << endl;
		  faction_confirm++;
		  if(faction_confirm == 4)
		    startGame(socketSet);

		}

	      }//REDY state
	      else if(strncmp(msg.c_str(),"MOVE",4) == 0)
	      {
		bool success = false;
		cerr << "MOVE command recognized" << endl;
		//Check if its correct player, relay info and next player if it is
		for(int j=0;j<players.size(); ++j){
		  if(players[j].sock == sockets[i])
		    if(players[j].number == current_player){
		      for(int j=0;j<sockets.size(); ++j)
			sockets[j].writeString(msg);//Relay
		      nextPlayer();
		      success = true;
		      break;
		    }
		}
		if(!success)
		  cerr << "Command received from invalid player" << endl;
	      }// MOVE Comparison
	      else if(strncmp(msg.c_str(),"CAPT",4) == 0)
	      {
		//Check if its correct player, relay info and next player if it is
		bool success = false;
		cerr << "CAPT command recognized" << endl;
		for(int j=0;j<players.size(); ++j){
		  if(players[j].sock == sockets[i])
		    if(players[j].number == current_player){
		      for(int j=0;j<sockets.size(); ++j)
			sockets[j].writeString(msg);
		      nextPlayer();
		      success = true;
		      break;
		    }
		}
		if(!success)
		  cerr << "Command received from invalid player" << endl;
	      }//CAPT comparison
	      //HOLD method test
	      else if(strncmp(msg.c_str(), "HOLD",4) == 0)
	      {
		bool success = false;
		cerr << "HOLD command recognized" << endl;
		for(int j=0;j<players.size(); ++j){
		  if(players[j].sock == sockets[i])
		    if(players[j].number == current_player){
		      for(int j=0;j<sockets.size(); ++j)
			sockets[j].writeString(msg);
		      success = true;
		      break;
		    }
		  if(!success)
		    cerr << "Command received from invalid player" << endl;	    
		}
	      }//HOLD comparison
	      else if(strncmp(msg.c_str(), "GMSG", 4) == 0)
	      {//simple handshake and relay this one
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);
	      }
	      else if(strncmp(msg.c_str(), "PLAC", 4) == 0)
	      {//This shouldnt be coming in on its own, assume a move or capt has been sent already
		cerr << "PLAC Command recognized" << endl;
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);
	      }
	      else if(strncmp(msg.c_str(), "REMV", 4) == 0)
	      {
		cerr << "REMV Command recognized" << endl;
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);
	      }
	      else if(strncmp(msg.c_str(), "LVUP", 4) == 0)
	      {
		cerr << "LVUP Command recognized" << endl;
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);
	      }
	      else if(strncmp(msg.c_str(), "ROCK", 4) == 0)
	      {
		cerr << "ROCK Command recognized" << endl;
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);
	      }
	      else if(strncmp(msg.c_str(), "BITE", 4) == 0)
	      {
		cerr << "BITE Command recognized" << endl;
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);
	      } 
	      else if(strncmp(msg.c_str(), "CLIP", 4) == 0)
	      {
		cerr << "CLIP Command recognized" << endl;
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);
	      }
	      else if(strncmp(msg.c_str(), "DEAD", 4) == 0)
	      {
		cerr << "DEAD Command recognized" << endl;
		for(int j=0;j<sockets.size(); ++j)
		  sockets[j].writeString(msg);

		string s_num = "";
		s_num += msg[5];
		int num = atoi(s_num.c_str());
		cout << "Player:" << s_num << " is DEAD" << endl;

		//remove player turn
		for(int k=0;k<players.size();k++){
		  if(players[k].number == num){
		    players[k].alive = false;
		    if(current_player == num)
		      nextPlayer();
		    break;
		  }
		}
		//check win
		alive_players--;
		if(alive_players == 1)
		{
		  int winner_num;
		  for(int k=0;k<players.size();k++){
		    if(players[k].alive == true)
		      winner_num = players[k].number;
		  }
		  ss.str("");
		  ss << "WINN " << winner_num << " ~";
		  for(int j=0;j<sockets.size(); ++j)
		    sockets[j].writeString(ss.str());

		  cout << "Player " << winner_num  << " won, thanks for playing!" << endl;
		  exit(0);
		}
	      } 
	      else //Anything that isnt a command
	      {
		cerr << "Sending unknown message to clients:" << msg << endl;
		for(int j=0;j<sockets.size(); ++j){
		  Socket sock = sockets[j];
		  sock.writeString(msg);
		}
	      }
	    }//for each snipped element of msg
	  }//if- socket is not closed
	  else{//If there is no connection with the socket
	    cout << "Socket has been closed" << endl;
	    Socket sock = sockets[i];
	    sockets[i] = sockets[sockets.size()-1];
	    sockets.pop_back();
	    cout << "Socket:" << sock.toString() << " removed." << endl;
	    for(unsigned int i=0;i<players.size();i++){	
	      if(players[i].sock == sock){
		if(game_start){
		  stringstream ss;
		  ss << "DEAD " << players[i].number << " ~";

		  for(int j=0;j<sockets.size(); ++j)
		    sockets[j].writeString(ss.str());

		  cout << "Player:" << players[i].number << " disconnected and is DEAD" << endl;

		  //remove player turn
		  int num = players[i].number;
		  for(int k=0;k<players.size();k++){
		    if(players[k].number == num){
		      players[k].alive = false;
		      if(current_player == num)
			nextPlayer();
		      break;
		    }
		  }
		  //check win
		  alive_players--;
		  if(alive_players == 1)
		  {
		    int winner_num;
		    for(int k=0;k<players.size();k++){
		      if(players[k].alive == true)
			winner_num = players[k].number;
		    }
		    ss.str("");
		    ss <<  "WINN " << winner_num << " ~";
		    for(int j=0;j<sockets.size(); ++j)
		      sockets[j].writeString(ss.str());

		    cout << "Player " << winner_num  << " won, thanks for playing!" << endl;
		    exit(0);
		  } 
		  break;
		}//if game start
		else
		{
		  players[i] = players[players.size()-1];
		  players.pop_back();
		  player_num--;
		  cout << "Removed prospective player from queue" << endl;
		  cout << "Num players in queue:" << player_num << endl;
		  break;
		}
	      }//if player socket found
	    }//for all players

	  }//else - if socket is closed
	}//if- socket has event
      }//for- each socket
    }//else- One of the sockets has an event
  }//While - Listener is open


}
