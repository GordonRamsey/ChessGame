#include "Socket.h"
#include <vector>
#include <iostream>
#include <sstream>

Socket listener;
vector<Socket> sockets;
stringstream ss;

int main(int argc, char* argv[])
{
  SocketSet socketSet;
  listener.listen(argv[1]);
  listener.joinGroup(&socketSet);
  string msg = "";

  while(!listener.isClosed()){
    //XXX Dont know why this is here
    socketSet.wait(2);

    //Client joining
    if(listener.hasEvent()){
      Socket sock = listener.accept();
      sock.joinGroup(&socketSet);
      cout << sock.toString() << " has joined\n";
      sockets.push_back(sock);
    }
    else //Messages from client
    {
      for(int i=sockets.size()-1; i >= 0; --i) {
	if(sockets[i].hasEvent()){
	  int bytes = sockets[i].readString(msg,255);
	  if(!sockets[i].isClosed())
	  {
	    cerr << msg << "\n";

	    if(strncmp(msg.c_str(),"STRT",4) == 0)
	    {
	      //Shit
	    }//STRT Comparison
	    else //Anything that isnt a command
	    {
	      cerr << "Sending message to clients:" << msg << endl;
	      for(int j=0;j<sockets.size(); ++j){
		Socket sock = sockets[j];
		cerr << "To socket:" << sock.toString() << " Sending message:" << msg << endl;
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
