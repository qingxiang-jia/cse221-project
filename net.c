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

/* Shared Functions BEGIN */

void sleep500ms() {
  struct timespec tspec1, tspec2;
  tspec1.tv_sec = 0;
  tspec2.tv_nsec = 500000000L; // 500 ms
  nanosleep(&tspec1, &tspec2);
}

void server(int port, int payloadSize) // sizeof(char) == 1
{
  char *payloadPtr = malloc(payloadSize);
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

  uint64_t timestamp;
  ssize_t received = 0;
  ssize_t accu = 0;
  unsigned loop = 1;
  while (loop)
  {
    bzero(payloadPtr, payloadSize);
    received = read(dataSocket, payloadPtr, payloadSize);
    timestamp = getNano();
    accu += received;
    if (received == 0) {
      loop = 0;
    }
    if (accu >= payloadSize) {
      printf("%-15llu %zd\n", timestamp, accu);
      accu = 0;   
    }
  }
  close(listenSocket);
  close(dataSocket);
}

void client(char *serverAddress, int port, int payloadSize, int i)
{
  int socketTCP, n;
  char *payloadPtr = malloc(payloadSize);
  struct sockaddr_in servaddr;

  socketTCP = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);

  inet_pton(AF_INET, serverAddress, &(servaddr.sin_addr));

  connect(socketTCP, (struct sockaddr *)&servaddr, sizeof(servaddr));

  ssize_t sent;
  uint64_t timestamp;
  while (i--)
  {
    bzero(payloadPtr, payloadSize);
    sent = write(socketTCP, payloadPtr, payloadSize);
    timestamp = getNano();
    printf("%-15llu %zd\n", timestamp, sent);
    sleep(1);
  }
  close(socketTCP);
}

void serverClient(int argc, char *argv[], int payloadSize)
{
  if (argc == 3 && strcmp(argv[1], "-s") == 0)
  {
    printf("role: %s\nport: %s\n", "server", argv[2]);
    server(atoi(argv[2]), payloadSize);
  }
  else if (argc == 4 && strcmp(argv[1], "-c") == 0)
  {
    printf("role: %s\nport: %s\naddr: %s\n", "client", argv[2], argv[3]);
    client(argv[2], atoi(argv[2]), payloadSize, 10);
  }
  else
  {
    printf("net -s <port>\nnet -c <ip> <port>");
  }
}

/* Shared Functions END */

/* Measure Round Trip Time BEGIN */



/* Measure Round Trip Time END */

/* Measure Peak Bandwidth BEGIN */

#define PAYLOAD_SIZE_2 67108864 // 64 MB, char is 1 byte

/* Measure Peak Bandwidth END */

int main(int argc, char *argv[])
{
  // measure peak bandwidth
  serverClient(argc, argv, PAYLOAD_SIZE_2);
}
