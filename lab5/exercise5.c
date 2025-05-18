#include <stdio.h>

/*
Round robin

AIM: To simulate the CPU scheduling algorithm round-robin.

DESCRIPTION:
The aim is to calculate the average waiting time. There will be a time slice; each process should be executed within that time slice, and if not, it will go to the waiting state, so first check whether the burst time is less than the time slice. If it is less than it is, assign the waiting time to the sum of the total times. If it is greater than the burst time, then subtract the time slot from the actual burst time, increment it by time slot, and the loop continues until all the processes are completed.

ALGORITHM:
Step 1: Start the process
Step 2: Accept the number of processes in the ready Queue and time quantum (or) time 
slice
Step 3: For each process in the ready Q, assign the process id and accept the CPU burst 
time
Step 4: Calculate the no. of time slices for each process where No. of time 
slice for process (n) = burst time process (n)/time slice
Step 5: If the burst time is less than the time slice then the no. of time slices =1.
Step 6: Consider the ready queue is a circular Q, calculate
a) Waiting time for process (n) = waiting time of process(n-1)+ burst time of 
process(n-1 ) + the time difference in getting the CPU fromprocess(n-1)
b) Turnaround time for process(n) = waiting time of process(n) + burst time of 
process(n)+ the time difference in getting CPU from process(n).
Step 7: Calculate
c) Average waiting time = Total waiting Time / Number of process
d) Average Turnaround time = Total Turnaround Time / Number of process Step 
8: Stop the process
*/

int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i]; // Copy original burst time
    }

    printf("\nEnter the size of time slice: ");
    scanf("%d", &t);

    max = bu[0];
    for (i = 1; i < n; i++) {
        if (max < bu[i]) 
            max = bu[i];
    }

    // Round Robin Simulation
    for (j = 0; j < (max / t) + 1; j++) {
        for (i = 0; i < n; i++) {
            if (bu[i] != 0) {
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i];
                    temp = temp + bu[i];
                    bu[i] = 0;
                } else {
                    bu[i] = bu[i] - t;
                    temp = temp + t;
                }
            }
        }
    }

    // Calculate waiting times and totals
    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    printf("\nThe Average Turnaround Time is: %.2f", att / n);
    printf("\nThe Average Waiting Time is: %.2f", awt / n);

    printf("\n\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
    }

    return 0;
}

