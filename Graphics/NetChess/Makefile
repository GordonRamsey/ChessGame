CC=g++
CFLAGS= -c -Wall
LDFLAGS= -lSDL -lSDL_image -lSDL_ttf
COMMON_SOURCES=./Net_Assets/Socket.cpp ./Net_Assets/SocketSet.cpp ../../Engine/piece.cpp ./Text_Assets/StringInput.cpp
CLIENT_SOURCES=netChess.cpp
#CLIENT_SOURCES=twoPlayerNetChess.cpp
COMMON_OBJECTS=$(COMMON_SOURCES:.cpp=.o)
CLIENT_OBJECTS=$(CLIENT_SOURCES:.cpp=.o)
CLIENT_EXECUTABLE=NetChess
#CLIENT_EXECUTABLE=TwoPlayerNetChess

.PHONY: all Client

all: Client

Client: $(CLIENT_EXECUTABLE)

$(CLIENT_EXECUTABLE): $(COMMON_OBJECTS) $(CLIENT_OBJECTS) 
	$(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	
	rm *o $(CLIENT_EXECUTABLE)
