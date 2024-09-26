#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void clientApp()
{
    //-------------------Network section-------------------------
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

    //-------------------GUI section-------------------------------------------------
    int screenWidth = 400;
    int screenHeight = 200;
    bool sendMsg = false;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "raygui - controls test suite");
    SetTargetFPS(60);

    bool showMessageBox = false;

    while (!WindowShouldClose())
   {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        Rectangle textBox = { 10, screenHeight - 60, screenWidth - 140, 50};

        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        DrawRectangleRec(textBox, LIGHTGRAY);

        if (GuiButton((Rectangle){screenWidth - 110, screenHeight - 60, 100, 50}, "SEND")) sendMsg = true;
        
        if (sendMsg)
        {
            // Send message to server
            send(client_fd, mes, strlen(mes), 0);
            printf("client send packet\n");
            read(client_fd, buffer, 512 - 1);
            printf("%s", buffer);
            sendMsg = false;
        }

        EndDrawing();
    }
    CloseWindow();
    
    close(client_fd); 
}
