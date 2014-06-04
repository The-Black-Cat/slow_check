#ifndef SLOW_CHECK_H_INCLUDED
#define SLOW_CHECK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

int n;
char request[256];

clock_t start,stop,startb,stopb;

struct sockaddr_in serv_addr;
struct hostent *server;

void error(const char *msg);
int create_socket(char * host);
void connect_socket(int s,char * port);
void create_rdata(char * host);
void send_socket(int s,int mode);
void wait_socket(int s);
#endif // SLOW_CHECK_H_INCLUDED


