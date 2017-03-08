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


void sendData(int theSocket,int value){
    int bytes = write(theSocket, &value, sizeof(int));
}

int recvData(int theSocket){
    int value = 0;
    int bytes = read(theSocket,&value,sizeof(int));
    return value;
}

int launch(char* server,char* port){
    struct addrinfo hints;
    struct addrinfo *info;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    
    getaddrinfo(server, port, &hints,  &info);
    int theSocket = socket(info->ai_family, info->ai_socktype, 0);
    
    int result = connect(theSocket, info->ai_addr, info->ai_addrlen);
   
    freeaddrinfo(info);
    
    return theSocket;
}

int main(int argc, char* argv[])
{
    int theSocket = launch(argv[1],argv[2]);
    sendData(theSocket,atoi(argv[3]));
    int value = recvData(theSocket);
    printf("%d\n",value);
    close(theSocket);
    return 0;
    
}
