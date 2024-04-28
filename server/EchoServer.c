#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main() {
    int sd; // 套接字描述符
    int nr; // 接收的字节数
    char buffer[256];   // 数据缓存
    struct sockaddr_in serverAddr;    // 服务端地址
    struct sockaddr_in clientAddr;    // 客户端地址
    int clAddrLen;

    sd = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(7);
    bind(sd, (struct socketaddr*) &serverAddr, sizeof(serverAddr));
    for(;;) {
        nr = recvfrom(sd, buffer, 256, 0, (struct socketaddr*)&clientAddr, &clAddrLen);
        sendto(sd, buffer, nr, 0, (struct socketaddr*)&clientAddr, sizeof(clientAddr));
    }

    return 0;
}