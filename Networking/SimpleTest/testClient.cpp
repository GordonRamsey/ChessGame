#include "Socket.h"
#include "SocketSet.h"
#include <vector>

int main(int argc, char* argv[])
{
  Socket socket;
  SocketSet socketSet;
  socket.open(argv[1], argv[2]);
  socket.joinGroup(&socketSet);

  socket.writeString("FUCKING KILL ME!!!!");


}
