#include <complex.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int com_socket;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = INADDR_ANY;
    sock_addr.sin_port = htons(3500);
    socklen_t addr_len = sizeof(sock_addr);

    if (bind(sockfd, (struct sockaddr*)&sock_addr, addr_len) < 0)
    {
        perror("Bind error!");
        return -1;
    }
    if (listen(sockfd, 3) < 0) //why 3?
    {
        perror("Listen error!");
        return -1;
    }
    if (com_socket = accept(sockfd, (struct sockaddr*)&sock_addr, &addr_len) < 0)
    {
        perror("Accept error!");
        return -1;
    }
    //read();
    close(com_socket);
    close(sockfd);
    return 0;
}
