To compile:
  g++ netchess.cpp -o NetChess -lSDL -lSDL_image ./Net_Asssets/Socket.cpp ./Net_Assets/SocketSet.cpp ../../Engine/piece.cpp

To Run:
  Server: ./Server <port>

  Client: ./NetChess <IP> <port>

Notes:
  Bridge file is for local dependencies, edit accordingly
