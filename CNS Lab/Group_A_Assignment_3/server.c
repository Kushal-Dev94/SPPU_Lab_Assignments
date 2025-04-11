/*

Kushal Shankhapal
Roll No. 56
KBTUG22165


Write a program of using TCP socket for wired network following:
a. Say Hello to Each other

Hello Server

*/

#include <stdio.h>       // For printf(), perror()
#include <sys/socket.h>  // For socket(), bind(), listen(), accept()
#include <netinet/in.h>  // For sockaddr_in structure
#include <string.h>      // For memset(), strcpy()
#include <arpa/inet.h>   // For inet_addr()
#include <unistd.h>      // For close()

int main() {
    int welcomeSocket, newSocket;
    char buffer[1024] = "Hello Client\n"; // Message to be sent to the client
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    // Step 1: Create a TCP socket (IPv4, Stream socket, Default protocol)
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (welcomeSocket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Step 2: Configure the server address structure
    serverAddr.sin_family = AF_INET;          // Address family = Internet
    serverAddr.sin_port = htons(7891);        // Port number = 7891 (converted to network byte order)
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address (localhost)
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); // Zero padding

    // Step 3: Bind the socket to the IP and port
    if (bind(welcomeSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Step 4: Listen for incoming connections (max 5 clients in queue)
    if (listen(welcomeSocket, 5) == 0)
        printf("Server is listening on port 7891...\n");
    else {
        perror("Listen failed");
        return 1;
    }

    // Step 5: Accept a client connection
    addr_size = sizeof(serverStorage);
    newSocket = accept(welcomeSocket, (struct sockaddr*)&serverStorage, &addr_size);
    if (newSocket < 0) {
        perror("Accept failed");
        return 1;
    }
    printf("Client connected!\n");

    // Step 6: Send message to client
    send(newSocket, buffer, strlen(buffer), 0);
    printf("Message sent to client: %s", buffer);

    // Step 7: Close sockets
    close(newSocket);
    close(welcomeSocket);

    return 0;
}


