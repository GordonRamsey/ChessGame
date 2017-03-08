CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Client.cpp  Noise.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=client

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	
	rm *o $(EXECUTABLE)
