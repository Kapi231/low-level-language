#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main()
{
    const char *mes = "Hello Server";
    char buffer[512] = { 0 };
    int client_fd;

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Faild to create socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1500);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) < 0)
    {
        perror("Wrong server addres");
        exit(1);
    }
    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection error");
        exit(1);
    }

    send(client_fd, mes, strlen(mes), 0);
    printf("client send packet\n");
    read(client_fd, buffer, 512 - 1);
    printf("%s", buffer);

    close(client_fd); 
    return 0;
}
