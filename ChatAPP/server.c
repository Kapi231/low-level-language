#include <complex.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

void TCP_server(int Port)
{
    printf("Initialiazing server...\n");    
    const char hello = "Hello";
    char buffer[512] = { 0 };

    // Sockets
    int commmunication_socket, sockfd;
   
    if (socket(AF_INET, SOCK_STREAM, 0) < 0)
    {
        perror("Faild creating socket");
        exit(1);
    }

    // Assigning variables
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = INADDR_ANY;
    sock_addr.sin_port = htons(Port);
    socklen_t addr_len = sizeof(sock_addr);

    if (bind(sockfd, (struct sockaddr*)&sock_addr, addr_len) < 0)
    {
        perror("Bind error!");
        exit(1);
    }
    if (listen(sockfd, 3) < 0) //why 3?
    {
        perror("Listen error!");
        exit(1);
    }

    if (commmunication_socket = accept(sockfd, (struct sockaddr*)&sock_addr, &addr_len) < 0)
    {
        perror("Accept error!");
        exit(1);
    }

    read(commmunication_socket, buffer, sizeof(buffer) - 1);
    printf("%s\n", buffer);
    send(commmunication_socket, hello, sizeof(hello) - 1, 0);
    printf("Message send");
    
    close(commmunication_socket);
    close(sockfd);
}
