#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 1337



int main(int argc, char const *argv[])
{

    int socketfd;
    struct sockaddr_in server_addr ;

    socketfd=socket(AF_INET,SOCK_STREAM,0 ); 

    server_addr.sin_port=htons(PORT);
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=   INADDR_ANY;


    if(bind(socketfd,(const struct  sockaddr *) &server_addr, sizeof(server_addr)) < 0){
        printf("Binding Went Wrong!\n");
        exit(EXIT_FAILURE);
    } 

    if(listen(socketfd, 3) < 0){

        printf("Listening Went Wrong!\n");
        exit(EXIT_FAILURE);

    }    
    printf("Waiting For connetion!\n");

    accept(socketfd,(struct sockaddr * )&server_addr, 0 );
    
    printf("Conneted!\n");

    close(socketfd);
    return 0;

}
