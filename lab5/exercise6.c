#include <stdio.h>

/*
Shortest job first

AIM: To write a program to stimulate the CPU scheduling algorithm: Shortest job first
(Non- Preemption)

DESCRIPTION:
To calculate the average waiting time for the shortest job, the first algorithm is the sorting of the processes based on their burst time in ascending order, then calculating the waiting time of each process as the sum of the bursting times of all the processes previous or before that process.

ALGORITHM:
Step 1: Start the process
Step 2: Accept the number of processes in the ready Queue
Step 3: For each process in the ready Q, assign the process id and accept the CPU 
burst time
Step 4: Start the Ready Q according the shortest Burst time by sorting according to 
lowest to highest burst time.
Step 5: Set the waiting time of the first process as ‗0‘ and its turnaround time as its burst 
time.
Step 6: Sort the processes names based on their Burt time
Step 7: For each process in the ready queue, 
calculate
a) Waiting time(n)= waiting time (n-1) + Burst time (n-1)
b) Turnaround time (n)= waiting time(n)+Burst time(n)
Step 8: Calculate
c) Average waiting time = Total waiting Time / Number of process
d)Average Turnaround time = Total Turnaround Time / Number of process
Step 9: Stop the process.

*/

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }

    // Sort processes by burst time (ascending order)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}

