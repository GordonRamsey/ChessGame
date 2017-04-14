CC=g++
CFLAGS= -c -g
LDFLAGS=
COMMON_SOURCES=Socket.cpp SocketSet.cpp
SERVER_SOURCES=testServer.cpp
COMMON_OBJECTS=$(COMMON_SOURCES:.cpp=.o)
SERVER_OBJECTS=$(SERVER_SOURCES:.cpp=.o)
SERVER_EXECUTABLE=Server

.PHONY: all Server Client

all: Server Client

Server: $(SERVER_EXECUTABLE)

$(SERVER_EXECUTABLE): $(COMMON_OBJECTS) $(SERVER_OBJECTS) 
	$(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	
	rm *o $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)
