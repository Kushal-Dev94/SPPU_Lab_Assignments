/*

Kushal Shankhapal
Roll No. 56
KBTUG22165


Write a program of using TCP socket for wired network following:
a. Say Hello to Each other

Hello Client

*/

#include <stdio.h>       // For printf(), perror()
#include <sys/socket.h>  // For socket(), connect(), recv()
#include <netinet/in.h>  // For sockaddr_in structure
#include <string.h>      // For memset()
#include <arpa/inet.h>   // For inet_addr()
#include <unistd.h>      // For close()

int main() {
    int clientSocket;
    char buffer[1024];  // Buffer to store received message
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // Step 1: Create a TCP socket (IPv4, Stream socket, Default protocol)
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Step 2: Configure the server address structure
    serverAddr.sin_family = AF_INET;          // Address family = Internet
    serverAddr.sin_port = htons(7891);        // Port number = 7891
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address (localhost)
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); // Zero padding

    // Step 3: Connect to the server
    addr_size = sizeof(serverAddr);
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, addr_size) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to server!\n");

    // Step 4: Receive message from server
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';  // Null terminate the received string
        printf("Message from server: %s", buffer);
    } else {
        printf("Error receiving data from server.\n");
    }

    // Step 5: Close socket
    close(clientSocket);

    return 0;
}

