To compile:
  g++ netChess.cpp -o NetChess -lSDL -lSDL_image ./Net_Assets/Socket.cpp ./Net_Assets/SocketSet.cpp ../../Engine/piece.cpp

To Run:
  Server: ./Server <port>

  Client: ./NetChess <IP> <port>

Notes:
  Bridge file is for local dependencies, edit accordingly
