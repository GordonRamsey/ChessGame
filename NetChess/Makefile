CC = g++
CFLAGS = -c -Wall -g
LDFLAGS = -lSDL -lSDL_image -lSDL_ttf -g
COMMON_SOURCES =./Net_Assets/Socket.cpp ./Net_Assets/SocketSet.cpp  ./Text_Assets/StringInput.cpp
CLIENT_SOURCES = netChess.cpp

PIECE_SOURCES = ./Piece_Assets/piece.cpp ./Piece_Assets/rook.cpp ./Piece_Assets/knight.cpp ./Piece_Assets/bishop.cpp ./Piece_Assets/queen.cpp ./Piece_Assets/king.cpp ./Piece_Assets/pawn.cpp ./Piece_Assets/chess.cpp 
FIGHTER_SOURCES = ./Piece_Assets/Fighters/Frook.cpp ./Piece_Assets/Fighters/Fknight.cpp ./Piece_Assets/Fighters/Fbishop.cpp ./Piece_Assets/Fighters/Fqueen.cpp ./Piece_Assets/Fighters/Fking.cpp ./Piece_Assets/Fighters/Fpawn.cpp
GOLEM_SOURCES = ./Piece_Assets/Golem/Grook.cpp ./Piece_Assets/Golem/Gknight.cpp ./Piece_Assets/Golem/Gbishop.cpp ./Piece_Assets/Golem/Gqueen.cpp ./Piece_Assets/Golem/Gking.cpp ./Piece_Assets/Golem/Gpawn.cpp
NECRO_SOURCES = ./Piece_Assets/Necro/Nrook.cpp ./Piece_Assets/Necro/Nknight.cpp ./Piece_Assets/Necro/Nbishop.cpp ./Piece_Assets/Necro/Nqueen.cpp ./Piece_Assets/Necro/Nking.cpp ./Piece_Assets/Necro/Npawn.cpp
PORTAL_SOURCES = ./Piece_Assets/Portal/Prook.cpp ./Piece_Assets/Portal/Pknight.cpp ./Piece_Assets/Portal/Pbishop.cpp ./Piece_Assets/Portal/Pqueen.cpp ./Piece_Assets/Portal/Pking.cpp ./Piece_Assets/Portal/Ppawn.cpp
WURM_SOURCES = ./Piece_Assets/Wurm/Wrook.cpp ./Piece_Assets/Wurm/Wknight.cpp ./Piece_Assets/Wurm/Wbishop.cpp ./Piece_Assets/Wurm/Wqueen.cpp ./Piece_Assets/Wurm/Wking.cpp ./Piece_Assets/Wurm/Wpawn.cpp

MENU_SOURCES = ./Menu_Assets/menu.cpp

COMMON_OBJECTS=$(COMMON_SOURCES:.cpp=.o)
CLIENT_OBJECTS=$(CLIENT_SOURCES:.cpp=.o)

PIECE_OBJECTS=$(PIECE_SOURCES:.cpp=.o)  
FIGHTER_OBJECTS=$(FIGHTER_SOURCES:.cpp=.o)  
GOLEM_OBJECTS=$(GOLEM_SOURCES:.cpp=.o)  
NECRO_OBJECTS=$(NECRO_SOURCES:.cpp=.o)  
PORTAL_OBJECTS=$(PORTAL_SOURCES:.cpp=.o)  
WURM_OBJECTS=$(WURM_SOURCES:.cpp=.o)  

MENU_OBJECTS=$(MENU_SOURCES:.cpp=.o)

CLIENT_EXECUTABLE=NetChess

.PHONY: all Client

all: Client

Client: $(CLIENT_EXECUTABLE)

$(CLIENT_EXECUTABLE): $(COMMON_OBJECTS) $(CLIENT_OBJECTS) $(PIECE_OBJECTS) $(MENU_OBJECTS) $(FIGHTER_OBJECTS) $(GOLEM_OBJECTS) $(NECRO_OBJECTS) $(PORTAL_OBJECTS) $(WURM_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	
	rm *o $(CLIENT_EXECUTABLE)  \
	./Menu_Assets/*.o	    \
	./Piece_Assets/*.o          \
	./Piece_Assets/Fighters/*.o \
	./Piece_Assets/Golem/*.o    \
	./Piece_Assets/Necro/*.o    \
	./Piece_Assets/Portal/*.o   \
	./Piece_Assets/Wurm/*.o
  	
