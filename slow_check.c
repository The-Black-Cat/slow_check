#include "slow_check.h"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int create_socket(char * host)
{
    int s;
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
        error("ERROR opening socket");
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
        }
    return s;

}

void connect_socket(int s,char * port)
{
    int portno;
    portno = atoi(port);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(s,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}


void create_rdata(char * host)
{
    bzero(request,sizeof(request));
    char *rp = request;
    snprintf(rp,sizeof(request),
        "GET / HTTP/1.1\r\n"
        "Host: %s\r\n"
        "User-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Trident/4.0; .NET CLR 1.1.4322; .NET CLR 2.0.503l3; .NET CLR 3.0.4506.2152; .NET CLR 3.5.30729; MSOffice 12)\r\n"
        "Connection: Keep-Alive"
        "Content-Length: 42\r\n",host);
}


void send_socket(int s,int mode)
{
    n = write(s,request,strlen(request));
    if (n < 0)
         error("ERROR writing to socket");
    if(mode == 1)
    {
        bzero(request,sizeof(request));
        char *rp = request;
        snprintf(rp,sizeof(request),"X-a: b\r\n");
        sleep(10);
        n = write(s,request,strlen(request));
        if (n < 0)
            error("ERROR writing to socket");
    }
}

void wait_socket(int s)
{
    bzero(request,sizeof(request));
    n = read(s,request,sizeof(request));
    if (n < 0)
         error("ERROR reading from socket");
    close(s);
}

void * slow_check(void * arguments)
{
	struct arg_struct *args = arguments;
	int sock;
	clock_t start,stop;
	
	sock =  create_socket(args->host);
    connect_socket(sock,args->port);
    create_rdata(args->host);
    time(&start);
    send_socket(sock,args->mode);
    wait_socket(sock);
    time(&stop);
    args->time_spent = (int)(stop - start);
    printf("[!] Server waited for : %d secs\n", args->time_spent);
    return NULL;
}
