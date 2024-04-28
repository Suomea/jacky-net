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

    // 创建套接字
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(13);

    // 绑定套接字到地址
    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    // 监听套接字
    if (listen(listenfd, 10) == -1) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    printf("Time server is running...\n");

    // 无限循环接受客户端连接并处理
    for (;;) {
        if ((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) == -1) {
            perror("accept error");
            continue;
        }

        char buff[MAXLINE];
        time_t ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

        // 向客户端发送时间
        if (write(connfd, buff, strlen(buff)) == -1) {
            perror("write error");
        }

        // 关闭连接
        close(connfd);
    }

    // 关闭监听套接字（实际上这一行永远不会执行）
    close(listenfd);

    return 0;
}

