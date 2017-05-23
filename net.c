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

void sleep500ms() {
  struct timespec tspec1, tspec2;
  tspec1.tv_sec = 0;
  tspec2.tv_nsec = 500000000L; // 500 ms
  nanosleep(&tspec1, &tspec2);
}

#define PAYLOAD_SIZE 67108864 // 64 MB
void server(int port) // sizeof(char) == 1
{
  char *payloadPtr = malloc(PAYLOAD_SIZE);
  int listenSocket, dataSocket;

  struct sockaddr_in address;

  listenSocket = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&address, sizeof(address));

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htons(INADDR_ANY);
  address.sin_port = htons(port);

  bind(listenSocket, (struct sockaddr *)&address, sizeof(address));

  listen(listenSocket, 10);

  dataSocket = accept(listenSocket, (struct sockaddr *)NULL, NULL);

  while (1)
  {
    bzero(payloadPtr, PAYLOAD_SIZE);
    double timestamp;
    unsigned lo, hi;
    GETTIME(lo, hi)
    read(dataSocket, payloadPtr, PAYLOAD_SIZE);
    GETNUM(lo, hi, timestamp)
    printf("%f\n", timestamp);
  }
  close(listenSocket);
  close(dataSocket);
}

void client(char *serverAddress, int port)
{
  int socketTCP, n;
  char *payloadPtr = malloc(PAYLOAD_SIZE);
  struct sockaddr_in servaddr;

  socketTCP = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);

  inet_pton(AF_INET, serverAddress, &(servaddr.sin_addr));

  connect(socketTCP, (struct sockaddr *)&servaddr, sizeof(servaddr));

  int i = 10;
  while (i--)
  {
    bzero(payloadPtr, PAYLOAD_SIZE);
    double timestamp;
    unsigned lo, hi;
    GETTIME(lo, hi)
    write(socketTCP, payloadPtr, PAYLOAD_SIZE + 1);
    GETNUM(hi, lo, timestamp)
    printf("%f\n", timestamp);
    sleep500ms(); // gives some time for server to set up for each iteration
  }
  close(socketTCP);
}

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

/* Measure Round Trip Time END */
