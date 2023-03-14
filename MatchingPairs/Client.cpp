#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";

    // Create socket

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;

    // Convert IPv4 and IPv6 addresses from text to binary form

    if (inet_pton(AF_INET, "", &serv_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    serv_addr.sin_port = htons(8080);

    // Connect to server


    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }

    // Send message to server

    send(sock, hello, strlen(hello), 0);

    // Close the socket

    close(sock);

    return 0;
}