#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXLINE 4096

int main() {
    int listenfd, connfd;
    struct sockaddr_in serveraddr;
    
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(13);

    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) 
    {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, 10) == -1) 
    {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    printf("Time server is running...\n");

    for (;;) 
    {
        if ((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) == -1) 
        {
            perror("accept error");
            continue;
        }

        char buff[MAXLINE];
        time_t ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

        if (write(connfd, buff, strlen(buff)) == -1) 
        {
            perror("write error");
        }

        close(connfd);
    }
    
    close(listenfd);

    return 0;
}

