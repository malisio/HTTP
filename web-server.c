#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define PORT 1337



int main(int argc, char const *argv[])
{
    //Declaration Of stuff we going to use later
    int socketfd;
    struct sockaddr_in server_addr ;
    char * OK_REQUEST ="HTTP/1.1 200 OK\r\n\r\n";
    //Creating a Socket
    socketfd=socket(AF_INET,SOCK_STREAM,0 ); 
    //Defining The Struct of the socket to bind it 
    server_addr.sin_port=htons(PORT);
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=   INADDR_ANY;

    //Binding and checking if the Socket is binding without any Problems

    if(bind(socketfd,(const struct  sockaddr *) &server_addr, sizeof(server_addr)) < 0){
        printf("Binding Went Wrong!\n");
        exit(EXIT_FAILURE);
    } 
    //Listening on the Port with the backlog being 3
    if(listen(socketfd, 3) < 0){
        printf("Listening Went Wrong!\n");
        exit(EXIT_FAILURE);

    }    
    //Waiting For coonections

    printf("Waiting For connetion!\n");

    //Accepting the Connection and creating a  file descriptor
    int server_addr_len= sizeof(socketfd);
    
    int fd = accept(socketfd,(struct sockaddr * )&server_addr,&server_addr_len);

    //Replying the request

    int bytes_send = send(fd,OK_REQUEST,strlen(OK_REQUEST), 0);
    printf("Conneted!\n");

    //Clossing and checking if something went Wrong

    if(close(socketfd)  == -1 ){
        printf("Closing the Socket went Wrong!\n");
        exit(EXIT_FAILURE);
    }

    return 0;

}
