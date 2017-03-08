/* Thomas Morgan
 * 360 Proj1
 */
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
#include "Noise.h"

using namespace std;

void sendData(int theSocket,int id, int size, unsigned char* img){
    int bytes = write(theSocket, &id, sizeof(int));
    bytes = write(theSocket, &size, sizeof(int));
    bytes = write(theSocket, img, size);
}

int recvInt(int theSocket, int value){
    value = 0;
    int bytes = read(theSocket,&value,sizeof(int));
    return value;
}

float recvFloat(int theSocket, float value){
    value = 0;
    int bytes = read(theSocket,&value,sizeof(float));
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
    int id = recvInt(theSocket, id);
    float z = recvFloat(theSocket, z);
    int seed = recvInt(theSocket, seed);
    Noise perlin(seed);
    unsigned char* img = perlin.createImage(z);
    int size = perlin.imageSize();
    sendData(theSocket, id, size, img);
    printf("%d\n",id);
    printf("%f\n",z);
    printf("%d\n",seed);
    close(theSocket);
    return 0;
}
