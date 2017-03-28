compile:
  g++ netChess.cpp -o NetChess -lSDL -lSDL_image ./Net_Assets/Socket.cpp ./Net_Assets/SocketSet.cpp ../../Engine/piece.cpp

To Run:
  Server: ./Server <port>

  Client: ./NetChess <IP> <port>

Notes:
  Bridge file is for local dependencies, edit accordingly


THE_REAL_GOODS:
  To compile:
    make... but you are goign to want to go into he make file and make sure you are compilwing the right one.
      you might have to change the object and excutable to the two player chess. it will be defaulted to net chess.

    To run:
      same old same old


***DAVID***
you need to change the bridge.h
