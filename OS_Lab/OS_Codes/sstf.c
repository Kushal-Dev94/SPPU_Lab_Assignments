#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, n, TotalHeadMovement = 0, initial, count = 0;

    // Input the number of requests
    printf("Enter the number of Requests (max 100):\n");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
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

    // SSTF disk scheduling logic
    while (count < n) {
        int min = 1000, index = -1; // Reset min and index for each iteration
        for (i = 0; i < n; i++) {
            int d = abs(RQ[i] - initial);
            if (RQ[i] != 1000 && d < min) { // Ensure we don't consider the processed requests
                min = d;
                index = i;
            }
        }

        if (index != -1) { // If a valid request was found
            TotalHeadMovement += min;
            initial = RQ[index];
            RQ[index] = 1000; // Mark this request as processed
            count++;
        } else {
            break; // No more requests to process
        }
    }

    // Output the total head movement
    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}

