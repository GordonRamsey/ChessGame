CC=g++
CFLAGS= -c -Wall
LDFLAGS= -lSDL -lSDL_image -lSDL_ttf -g
COMMON_SOURCES=../Net_Assets/Socket.cpp ../Net_Assets/SocketSet.cpp  ../Text_Assets/StringInput.cpp
PIECE_SOURCES = ../Piece_Assets/piece.cpp ../Piece_Assets/rook.cpp ../Piece_Assets/knight.cpp ../Piece_Assets/bishop.cpp ../Piece_Assets/queen.cpp ../Piece_Assets/king.cpp ../Piece_Assets/pawn.cpp ../Piece_Assets/chess.cpp 
CLIENT_SOURCES=sandboxChess.cpp

COMMON_OBJECTS=$(COMMON_SOURCES:.cpp=.o)
PIECE_OBJECTS=$(PIECE_SOURCES:.cpp=.o)  
CLIENT_OBJECTS=$(CLIENT_SOURCES:.cpp=.o)
CLIENT_EXECUTABLE=SandboxChess

.PHONY: all Client

all: Client

Client: $(CLIENT_EXECUTABLE)

$(CLIENT_EXECUTABLE): $(COMMON_OBJECTS) $(CLIENT_OBJECTS) $(PIECE_OBJECTS) 
	$(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	
	rm *o $(CLIENT_EXECUTABLE)
