#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

/*
Fixing the sephamore

Thread1 (increment) reads the shared variable, initially set to 1, and increments it to 2. Before Thread1 can update the shared variable, it is preempted (simulated with sleep(1)) by Thread2. 

Thread2 (decrement) then reads the shared variable (which is still 1 at this point) and decrements it to 0. 

Both threads print the updated values of the shared variable. Since Thread1 does the final update, the final value of the shared variable will be 2, even though both threads were supposed to bring it back to 1.

The race condition occurs because Thread1 and Thread2 access the shared variable without proper synchronization. Thread1 increments the value to 2, but before it can update the shared variable, Thread2 reads the old value (1) and decrements it to 0. After both threads update the shared variable, the final value will be either 0 or 2, depending on which thread performs the last update.
*/

void *increment();
void *decrement();

int shared = 1; // Shared variable
sem_t semaphore; // Semaphore variable

int main() {
    // Initialize semaphore:
    // 1st argument is the address of the semaphore,
    // 2nd argument is 0 (for single-process synchronization),
    // 3rd argument is the initial value of the semaphore (1)
    sem_init(&semaphore, 0, 1);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment, NULL); // Create thread to increment the shared variable
    pthread_create(&thread2, NULL, decrement, NULL); // Create thread to decrement the shared variable
    pthread_join(thread1, NULL); // Wait for thread1 to finish
    pthread_join(thread2, NULL); // Wait for thread2 to finish

    printf("Final value of shared variable: %d\n", shared); // Print the final updated value of the shared variable

    sem_destroy(&semaphore); // Destroy semaphore after use
    return 0;
}

void *increment() {
    int localValue;
    sem_wait(&semaphore); // Wait operation on semaphore, ensuring mutual exclusion
    localValue = shared; // Thread1 reads the shared variable
    printf("Thread1 reads the value as: %d\n", localValue);
    localValue++; // Thread1 increments the value
    printf("Local increment by Thread1: %d\n", localValue);
    sleep(1); // Simulate preemption, allowing Thread2 to execute
    shared = localValue; // Thread1 updates the shared variable
    printf("Shared variable updated by Thread1: %d\n", shared);
    sem_post(&semaphore); // Signal operation on semaphore, allowing the next thread to execute
    return NULL;
}

void *decrement() {
    int localValue;
    sem_wait(&semaphore); // Wait operation on semaphore, ensuring mutual exclusion
    localValue = shared; // Thread2 reads the shared variable
    printf("Thread2 reads the value as: %d\n", localValue);
    localValue--; // Thread2 decrements the value
    printf("Local decrement by Thread2: %d\n", localValue);
    sleep(1); // Simulate preemption, allowing Thread1 to execute
    shared = localValue; // Thread2 updates the shared variable
    printf("Shared variable updated by Thread2: %d\n", shared);
    sem_post(&semaphore); // Signal operation on semaphore, allowing the next thread to execute
    return NULL;
}

