//Based on http://beej.us/guide/bgnet/output/html/multipage/syscalls.html

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/select.h>
#include <cstdio>
#include <cstdlib>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>


using namespace std;

int listener;
int client;


void closeClients(){
    close(client);
}

void closeServer(){
    closeClients();
    close(listener);
}


int openClient(){
    struct sockaddr_storage address;
    socklen_t size = sizeof(address);
    bzero(&address, sizeof(address));
    
    client = accept(listener, (struct sockaddr *)&address, &size);
 
    char ip[NI_MAXHOST];
    getnameinfo(((sockaddr *)&address), size, ip, sizeof(ip),NULL, NULL, NI_NUMERICHOST);
    
    printf("%s on port %d\n", ip, ntohs(size));
    
    return client;
}

void sendData(int theSocket,int value){
    int bytes = write(theSocket, &value, sizeof(int));
}

int recvData(int theSocket){
    int value = 0;
    int bytes = read(theSocket,&value,sizeof(int));
    return value;
}

int handleClient(int c){
    int value = recvData(c);
    sendData(c,value*2);
    return 0;
}

int launchServer(){
    struct addrinfo hints;
    struct addrinfo *info;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;  // or use AF_UNSPEC
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, "8421", &hints, &info);

    
    //This is the socket that will listen for connections
    int newSocket = socket(info->ai_family, info->ai_socktype, 0);
    
    int error = bind(newSocket, info->ai_addr, info->ai_addrlen);
    
    freeaddrinfo(info);

    if (error < 0) {
        return error;
    }
    return newSocket;
}

void runServer(){
    
    //Allow the listener socket to store up to 4 incomming connections
    //if listen returns a value < 0 we have a problem
    int error = listen(listener,4);
    int fd = listener;
    
    fd_set sockets;

    //add standard in and the listener to the set
    FD_ZERO(&sockets);
    FD_SET(STDIN_FILENO, &sockets);
    FD_SET(listener, &sockets);

    while(error >= 0){
        fd_set selected = sockets;
    
        error = select(fd+1, &selected,NULL,NULL,NULL);
        //should check if select went okay
        
        if(FD_ISSET(listener,&selected)){
            int newClient = openClient();
            FD_SET(newClient,&sockets);
            if(newClient > fd)
                fd = newClient;
        }
        
        if(FD_ISSET(client,&selected)){
            error = handleClient(client);
        }
        
        //close on a key press followed by a new line
        if (FD_ISSET(STDIN_FILENO, &selected)) {
            error = -1;
        }
    }
    
}

int main(){
    listener = launchServer();
    runServer();
    closeServer();
    return 0;
}
