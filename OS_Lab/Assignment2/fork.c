#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // For malloc and free
#include <sys/wait.h> // For wait()

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


// Function to perform selection sort

void selectionSort(int arr[], int n) {
    int temp, small;
    for (int i = 0; i < n - 1; i++) {
        small = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[small] > arr[j]) {
                small = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}


int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Original array
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Allocate memory for the array copy
    int *arr_copy = (int *)malloc(n * sizeof(int));
    if (arr_copy == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Copy the original array
    for (int i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }

    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        free(arr_copy);
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("This is the child process (PID: %d)\n", getpid());

        // Perform bubble sort
        bubbleSort(arr_copy, n);

        printf("The sorted array in the child process is:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr_copy[i]);
        }
        printf("\n");

        // Exit child process
        exit(0);
    } else {
        // Parent process
        printf("This is the parent process (PID: %d)\n", getpid());

        // Wait for the child process to complete
        printf("Parent process waiting for the child process to complete...\n");
        wait(NULL);

        // Perform selection sort
        selectionSort(arr, n);

        printf("The sorted array in the parent process is:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Demonstrate the zombie state:
        printf("Parent process sleeping to demonstrate the zombie state...\n");
        sleep(15);  // Sleep to allow observation of the zombie process

        // After sleep, child process should be cleaned up by the kernel
        printf("Parent process waking up from sleep...\n");
    }

    // Free the allocated memory
    free(arr_copy);

    return 0;
}



