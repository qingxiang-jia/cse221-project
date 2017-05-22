#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "headers/count.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

/* Measure Round Trip Time BEGIN */

void server(int port)
{
  char str[100];
  int listen_fd, comm_fd;

  struct sockaddr_in servaddr;

  listen_fd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(port);

  bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  listen(listen_fd, 10);

  comm_fd = accept(listen_fd, (struct sockaddr *)NULL, NULL);

  while (1)
  {
    bzero(str, 100);
    read(comm_fd, str, 100);
    printf("Echoing back - %s", str);
    write(comm_fd, str, strlen(str) + 1);
  }
}

void client(char *serverAddress, int port)
{
  int sockfd, n;
  char sendline[100];
  char recvline[100];
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);

  inet_pton(AF_INET, serverAddress, &(servaddr.sin_addr));

  connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  while (1)
  {
    bzero(sendline, 100);
    bzero(recvline, 100);
    fgets(sendline, 100, stdin); /*stdin = 0 , for standard input */

    write(sockfd, sendline, strlen(sendline) + 1);
    read(sockfd, recvline, 100);
    printf("%s", recvline);
  }
}

/* Measure Round Trip Time END */

int main(int argc, char *argv[])
{
  if (argc == 3 && strcmp(argv[1], "-s") == 0)
  {
    printf("role: %s\nport: %s\n", "server", argv[2]);
    server(atoi(argv[2]));
  }
  else if (argc == 4 && strcmp(argv[1], "-c") == 0)
  {
    printf("role: %s\nport: %s\naddr: %s\n", "client", argv[2], argv[3]);
    client(argv[2], atoi(argv[2]));
  }
  else
  {
    printf("net -s <port>\nnet -c <ip> <port>");
  }
  return 0;
}
