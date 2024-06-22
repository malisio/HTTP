#include <errno.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {


  setbuf(stdout, NULL);

  printf("Logs from your program will appear here!\n");


  int server_fd, client_addr_len;

  struct sockaddr_in client_addr;

  server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (server_fd == -1) {

    printf("Socket creation failed: %s...\n", strerror(errno));

    return 1;

  }

  // Since   I well be restarting the  program quite often, setting REUSE_PORT

  // ensures that we don't run into 'Address already in use' errors

  int reuse = 1;

  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) <

      0) {

    printf("SO_REUSEPORT failed: %s \n", strerror(errno));

    return 1;

  }
  //defining structure for binding socket with adress
  struct sockaddr_in serv_addr = {

      .sin_family = AF_INET,

      .sin_port = htons(4221),

      .sin_addr = {htonl(INADDR_ANY)},

  };

  if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0) {

    printf("Bind failed: %s \n", strerror(errno));

    return 1;

  }

  int connection_backlog = 5;

  if (listen(server_fd, connection_backlog) != 0) {

    printf("Listen failed: %s \n", strerror(errno));

    return 1;

  }

  printf("Waiting for a client to connect...\n");

  client_addr_len = sizeof(client_addr);

  accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

  int fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

  printf("Client connected\n");

  char *reply = "HTTP/1.1  200 OK\r\n\r\n";

  int bytes_sent = send(fd, reply, strlen(reply), 0);

  close(server_fd);

  return 0;

}
