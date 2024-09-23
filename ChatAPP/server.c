#include <complex.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

void TCP_server(int Port)
{
    int BufferSize = 512;

    printf("Initialiazing server...\n");    
    const char *hello = "Hello";
    //char buffer[512] = { 0 };
    
    char *buffer = malloc(BufferSize * sizeof(char));
    
    int opt = 1;

    // Assigning variables
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = INADDR_ANY;
    sock_addr.sin_port = htons(Port);
    socklen_t addr_len = sizeof(sock_addr);

    // Sockets
    int commmunication_socket, sockfd;
   
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Faild creating socket");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    if (bind(sockfd, (struct sockaddr*)&sock_addr, addr_len) == -1)
    {
        perror("Bind error!");
        exit(1);
    }
    if (listen(sockfd, 3) == -1) //why 3?
    {
        perror("Listen error!");
        exit(1);
    }

    if ((commmunication_socket = accept(sockfd, (struct sockaddr*)&sock_addr, &addr_len)) == -1)
    {
        perror("Accept error!");
        exit(1);
    }

    read(commmunication_socket, buffer, BufferSize * sizeof(char));
    printf("%s\n", buffer);
    send(commmunication_socket, hello, strlen(hello), 0);
    printf("Message send\n");
    
    memset(buffer, 0, BufferSize * sizeof(char)); //Clearing buffer

//    free(buffer); //Freeing buffer memory
    close(commmunication_socket);
    close(sockfd);
}
