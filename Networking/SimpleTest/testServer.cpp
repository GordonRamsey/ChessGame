#include "Socket.h"
#include <vector>
#include <iostream>

Socket listener;
vector<Socket> sockets;

int main(int argc, char* argv[])
{
  SocketSet socketSet;
  listener.listen(argv[1]);
  listener.joinGroup(&socketSet);
  string msg = "";

  while(!listener.isClosed()){
    //XXX Dont know why this is here
    socketSet.wait(2);

    if(listener.hasEvent()){
      Socket sock = listener.accept();
      sock.joinGroup(&socketSet);
      cout << sock.toString() << " has joined\n";
      sockets.push_back(sock);
    }else{
      for(int i=sockets.size()-1; i >= 0; --i) {
	if(sockets[i].hasEvent()){
	  int bytes = sockets[i].readString(msg,255);
	  if(!sockets[i].isClosed())
	  {
	    cerr << msg << "\n";

	    if(strncmp(msg.c_str(),"STRT",4) == 0)
	    {
	      //Shit
	    }//shit on my dick
	  }//if- socket is not closed
	}//if- socket has event
      }//for- each socket
    }//else- One of the sockets has an event


  }//While - Listener is open


}
