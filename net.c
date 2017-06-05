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

#include <errno.h>
#include <string.h>

/* Measure Round Trip Time BEGIN */

void pong(int port, int payloadSize) // sizeof(char) == 1
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

  ssize_t received = 0;
  ssize_t accu = 0;
  unsigned loop = 1;
  while (loop)
  {
    bzero(payloadPtr, payloadSize);
    received = read(dataSocket, payloadPtr, payloadSize);
    if (received > 0) {
      write(dataSocket, payloadPtr, payloadSize);
    }
    accu += received;
    if (received == 0)
    {
      loop = 0;
    }
    if (accu >= payloadSize)
    {
      accu = 0;
    }
  }
  close(listenSocket);
  close(dataSocket);
}

void ping(char *serverAddress, int port, int payloadSize)
{
  int socketTCP, n;
  char *payloadPtr = malloc(payloadSize);
  struct sockaddr_in servaddr;

  socketTCP = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);

  inet_pton(AF_INET, serverAddress, &(servaddr.sin_addr));

  int connectionRet = connect(socketTCP, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (connectionRet == -1) {
    printf("Connection failed! %s\n", strerror(errno));
    exit(0);
  }

  int i = 100;
  ssize_t sent;
  ssize_t received;
  double start, end;
  unsigned lo, hi, lo1, hi1;
  while (i--)
  {
    start = 0, end = 0, lo = 0, hi = 0, lo1 = 0, hi1 = 0;
    bzero(payloadPtr, payloadSize);
    COUNT1(hi, lo)
    sent = write(socketTCP, payloadPtr, payloadSize);
    received = read(socketTCP, payloadPtr, payloadSize);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    printf("%-15f %zd\n", end - start, sent);
  }
  close(socketTCP);
}

#define PAYLOAD_SIZE_1 64
int main1(int argc, char *argv[])
{
  if (argc == 3 && strcmp(argv[1], "-s") == 0)
  {
    printf("role: %s\nport: %s\n", "server", argv[2]);
    pong(atoi(argv[2]), PAYLOAD_SIZE_1);
  }
  else if (argc == 4 && strcmp(argv[1], "-c") == 0)
  {
    printf("role: %s\nport: %s\naddr: %s\n", "client", argv[2], argv[3]);
    ping(argv[2], atoi(argv[3]), PAYLOAD_SIZE_1);
  }
  else
  {
    printf("net -s <port>\nnet -c <ip> <port>");
    //      0    1 2       0    1 2    3
  }
  return 0;
}

/* Measure Round Trip Time END */

/* Measure Peak Bandwidth BEGIN */

void sleep500ms()
{
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
    if (received == 0)
    {
      loop = 0;
    }
    if (accu >= payloadSize)
    {
      printf("%-15llu %zd\n", timestamp, accu);
      accu = 0;
    }
  }
  close(listenSocket);
  close(dataSocket);
}

void client(char *serverAddress, int port, int payloadSize)
{
  int socketTCP, n;
  char *payloadPtr = malloc(payloadSize);
  struct sockaddr_in servaddr;

  socketTCP = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);

  inet_pton(AF_INET, serverAddress, &(servaddr.sin_addr));

  int connectionRet = connect(socketTCP, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (connectionRet == -1) {
    printf("Connection failed! %s\n", strerror(errno));
    exit(0);
  }

  int i = 10;
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

#define PAYLOAD_SIZE_2 67108864        // 64 MB, char is 1 byte
int main2(int argc, char *argv[])
{
  if (argc == 3 && strcmp(argv[1], "-s") == 0)
  {
    printf("role: %s\nport: %s\n", "server", argv[2]);
    server(atoi(argv[2]), PAYLOAD_SIZE_2);
  }
  else if (argc == 4 && strcmp(argv[1], "-c") == 0)
  {
    printf("role: %s\nport: %s\naddr: %s\n", "client", argv[2], argv[3]);
    client(argv[2], atoi(argv[3]), PAYLOAD_SIZE_2);
  }
  else
  {
    printf("net -s <port>\nnet -c <ip> <port>");
    //      0    1 2       0    1 2    3
  }
  return 0;
}

/* Measure Peak Bandwidth END */

/* Measure Setup and Tear-down BEGIN */

void server1(int port, int payloadSize) // sizeof(char) == 1
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

  ssize_t received = 0;
  ssize_t accu = 0;
  unsigned loop = 1;
  while (loop)
  {
    bzero(payloadPtr, payloadSize);
    received = read(dataSocket, payloadPtr, payloadSize);
    // printf("server received: %zd\n", received);
    accu += received;
    if (received == 0)
    {
      loop = 0;
    }
    if (accu >= payloadSize)
    {
      accu = 0;
    }
  }
  double start, end;
  unsigned lo, hi, lo1, hi1;
  COUNT1(hi, lo)
  close(listenSocket);
  COUNT2(hi1, lo1)
  GETNUM(hi, lo, start)
  GETNUM(hi1, lo1, end)
  printf("teardown: %f\n", end - start);
  close(dataSocket);
}

void client1(char *serverAddress, int port, int payloadSize)
{
  int socketTCP, n;
  char *payloadPtr = malloc(payloadSize);
  struct sockaddr_in servaddr;

  socketTCP = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);

  inet_pton(AF_INET, serverAddress, &(servaddr.sin_addr));

  double start, end;
  unsigned lo, hi, lo1, hi1;
  COUNT1(hi, lo)
  connect(socketTCP, (struct sockaddr *)&servaddr, sizeof(servaddr));
  COUNT2(hi1, lo1)
  GETNUM(hi, lo, start)
  GETNUM(hi1, lo1, end)
  printf("setup: %f\n", end - start);

  int i = 1;
  ssize_t sent;
  while (i--)
  {
    bzero(payloadPtr, payloadSize);
    sent = write(socketTCP, payloadPtr, payloadSize);
  }
}

#define PAYLOAD_SIZE_3 128
int main(int argc, char *argv[])
{
  if (argc == 3 && strcmp(argv[1], "-s") == 0)
  {
    // printf("role: %s\nport: %s\n", "server", argv[2]);
    server1(atoi(argv[2]), PAYLOAD_SIZE_3);
  }
  else if (argc == 4 && strcmp(argv[1], "-c") == 0)
  {
    // printf("role: %s\nport: %s\naddr: %s\n", "client", argv[2], argv[3]);
    client1(argv[2], atoi(argv[3]), PAYLOAD_SIZE_3);
  }
  else
  {
    printf("net -s <port>\nnet -c <ip> <port>");
  }
  return 0;
}

/* Measure Setup and Tear-down END */