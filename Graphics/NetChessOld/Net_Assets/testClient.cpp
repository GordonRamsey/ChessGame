#include "Socket.h"
#include "SocketSet.h"
#include <vector>
#include <iostream>
#include <sstream>

stringstream ss;

int main(int argc, char* argv[])
{
  Socket socket;
  SocketSet socketSet;
  socket.open(argv[1], argv[2]);
  socket.joinGroup(&socketSet);

  string msg = "";
  socket.writeString("Attempting connection...");
  socketSet.wait(10);
  while(!socket.hasEvent()){
  }//Wait for acceptance  
  
  int player_num;
  socket.readInt(&player_num);
  ss.str("");
  ss << "[Client] I am player number " << player_num;
  socket.writeString(ss.str());
  cout << ss.str() << endl;

  string input;
  while(!socket.isClosed()){ //While active connection with server
    cin >> input;
    if (input == "quit")
      socket.close();

    socket.writeString(input);

    socketSet.wait(0);
    if(socket.hasEvent()){
      socket.readString(msg, 100);
      cout << msg << endl;
    }

  }
  cout << "Program exited" << endl;


}
