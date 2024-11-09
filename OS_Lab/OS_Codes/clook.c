#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMovement = 0, initial, size, move;
    
    // Input the number of requests
    printf("Enter the number of Requests (max 100)\n");
    scanf("%d", &n);
    
    if (n > 100 || n <= 0) {
        printf("Invalid number of requests. Please enter a number between 1 and 100.\n");
        return 1;
    }

    // Input the request sequence
    printf("Enter the Requests sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }
    
    // Input the initial head position
    printf("Enter initial head position:\n");
    scanf("%d", &initial);
    
    // Input the total disk size
    printf("Enter total disk size:\n");
    scanf("%d", &size);
    
    // Input the head movement direction
    printf("Enter the head movement direction (high = 1, low = 0):\n");
    scanf("%d", &move);
    
    // Sort the request array
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    // Find the index of the first request greater than the initial position
    int index = 0;
    while (index < n && RQ[index] < initial) {
        index++;
    }

    // Calculate total head movement based on the direction of movement
    if (move == 1) { // Move towards higher values
        for (i = index; i < n; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // If there are requests lower than the initial, we need to go back to the start
        if (index > 0) {
            TotalHeadMovement += abs(RQ[index - 1] - initial);
            initial = RQ[0];
            for (i = 0; i < index; i++) {
                TotalHeadMovement += abs(RQ[i] - initial);
                initial = RQ[i];
            }
        }
    } else { // Move towards lower values
        for (i = index - 1; i >= 0; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // If there are requests higher than the initial, we need to go to the end
        if (index < n) {
            TotalHeadMovement += abs(RQ[index] - initial);
            initial = RQ[n - 1];
            for (i = n - 1; i >= index; i--) {
                TotalHeadMovement += abs(RQ[i] - initial);
                initial = RQ[i];
            }
        }
    }
    
    // Output the total head movement
    printf("Total head movement is %d\n", TotalHeadMovement);
    
    return 0;
}

