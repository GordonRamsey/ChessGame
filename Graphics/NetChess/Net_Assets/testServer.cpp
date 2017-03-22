#include "Socket.h"
#include <vector>
#include <iostream>
#include <sstream>

struct player{
  Socket sock;
  int number;
};

Socket listener;
vector<Socket> sockets;
vector<player> players;
stringstream ss;

bool game_start = false;
int current_player = 1;

void startGame(SocketSet socs)
{
  socs.wait(2);
  game_start = true;
  ss.str("");
  ss << "STRT";
  for(unsigned int i=0;i<sockets.size();i++){
    sockets[i].writeString(ss.str());
  }
}

void nextPlayer()
{
  current_player++;
  if(current_player == 5)
    current_player = 1;
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
      ss << "REDY " << player_num;
      cerr << "Sending new Client player number:" << player_num << endl;
      sock.writeString(ss.str());

      player newplayer;
      newplayer.number = player_num;
      newplayer.sock = sock;
      players.push_back(newplayer);

      player_num++;
      if(player_num == 5)
	startGame(socketSet);
    }
    else //Messages from client
    {
      for(int i=sockets.size()-1; i >= 0; --i) {
	if(sockets[i].hasEvent()){
	  int bytes = sockets[i].readString(msg,255);
	  if(!sockets[i].isClosed())
	  {
	    cerr << msg << "\n";

	    if(strncmp(msg.c_str(),"MOVE",4) == 0)
	    {
	      bool success = false;
	      cerr << "MOVE command recognized" << endl;
	      //Check if its correct player, relay info and next player if it is
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
	    //XXX: HOLD method test
	    else if(strncmp(msg.c_str(), "HOLD",4) == 0)
	    {
	      if (msg.size() <= 20){
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
		}
		if(!success)
		  cerr << "Command received from invalid player" << endl;	    
	      }
	      else
		continue;
	    }//HOLD comparison
	    else //Anything that isnt a command
	    {
	      cerr << "Sending unknown message to clients:" << msg << endl;
	      for(int j=0;j<sockets.size(); ++j){
		Socket sock = sockets[j];
		//cerr << "To socket:" << sock.toString() << " Sending message:" << msg << endl;
		sock.writeString(msg);
	      }
	    }
	  }//if- socket is not closed
	  else{
	    cout << "Socket has been closed" << endl;
	    Socket sock = sockets[i];
	    sockets[i] = sockets[sockets.size()-1];
	    sockets.pop_back();
	    cout << "Socket:" << sock.toString() << " removed." << endl;

	  }//else - if socket is closed
	}//if- socket has event
      }//for- each socket
    }//else- One of the sockets has an event
  }//While - Listener is open


}
