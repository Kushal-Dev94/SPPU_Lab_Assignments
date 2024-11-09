#include<stdio.h>       // Include standard input/output library for I/O functions
#include<stdlib.h>      // Include standard library for general functions like memory allocation
#include<unistd.h>      // Include standard symbolic constants and types for UNIX standard functions
#include<sys/types.h>   // Include definitions for data types used in system calls
#include<fcntl.h>       // Include file control options for file handling
#include<string.h>      // Include string handling functions

int main() {
    int n; // Variable declaration (not used in this snippet)
    puts("Server"); // Print a message indicating that this is the server

    char strMessage[5000]; // Buffer for messages to be sent to the client

    // Open FIFO6 for writing (to send messages to the client)
    int fd = open("fifo6.txt", O_WRONLY);
    
    // Open FIFO7 for reading (to receive messages from the client)
    int fd2 = open("fifo7.txt", O_RDONLY);

    // Check if opening FIFO6 for writing was successful
    if(fd == -1) {
        perror("cannot open fifo6"); // Print error message if failed
        return EXIT_FAILURE; // Exit the program with failure status
    }

    // Check if opening FIFO7 for reading was successful
    if(fd2 == -1) {
        perror("cannot open fifo7"); // Print error message if failed
        return EXIT_FAILURE; // Exit the program with failure status
    }

    puts("FIFO OPEN"); // Indicate that the FIFOs are successfully open

    // Buffer for reading the incoming message
    char stringBuffer[5000]; 
    memset(stringBuffer, 0, 5000); // Initialize the buffer to zero

    int res; // Variable for read results (not used in this snippet)
    char Len; // Variable to hold the length of the message

    // Main loop for sending and receiving messages
    {
        // Prompt the user to enter a message
        printf("\n\n\t\tEnter the Message to be passed (hitting ENTER without any string will terminate program): ");
        fgets(strMessage, 100, stdin); // Read user input into strMessage

        char L = (char)strlen(strMessage); // Get the length of the input message

        // Write the length of the message to FIFO6
        write(fd, &L, 1); 
        // Write the actual message to FIFO6
        write(fd, strMessage, strlen(strMessage)); 

        fflush(stdin); // Clear the input buffer (not necessary for this use case)
        
        strMessage[0] = 0; // Reset the character array for the next message

        // Read the length of the response from the client
        int len2; 
        res = read(fd2, &len2, 1); 

        // Read the actual response message from the client
        read(fd2, stringBuffer, 5000); // Read string characters into the buffer
        
        // Print the message received from the client
        printf("\nServer Received: %s\n", stringBuffer);
        stringBuffer[(int)len2] = 0; // Null-terminate the received string (this should actually be done before printing)
    }; 

    // Cleanup and exit logic (commented out)
    // printf("\n\nCLIENT CLOSED\n")
    // return 0; 
}

