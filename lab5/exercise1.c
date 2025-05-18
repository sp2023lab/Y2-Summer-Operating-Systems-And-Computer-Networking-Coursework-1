#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*
Semaphores

This program creates two threads: one that increments the value of a shared variable and another that decrements the same shared variable. Both threads execute concurrently, so the final value of the shared variable should ideally be the same as its initial value. However, due to a race condition, the final value may not match the initial value. Please refer the lecture PPT also for more details
*/

void *increment();
void *decrement();

int sharedVar = 1;            // Shared variable
pthread_mutex_t lock;  // Mutex lock for shared variable
int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);  // Initialize mutex
    pthread_create(&thread1, NULL, increment, NULL);  // Create thread to increment the value
    pthread_create(&thread2, NULL, decrement, NULL);  // Create thread to decrement the value
    pthread_join(thread1, NULL);  // Wait for thread1 to finish
    pthread_join(thread2, NULL);  // Wait for thread2 to finish
    printf("Final value of shared variable: %d\n", sharedVar);   // Print the final value of the shared variable
}

void *increment() {
    pthread_mutex_lock(&lock);  // Lock before access
    int localVar;
    localVar = sharedVar;  // Thread1 reads the value of shared variable
    printf("Thread1 reads the value of shared variable as: %d\n", localVar);
    localVar++;  // Thread1 increments the value
    printf("Local increment by Thread1: %d\n", localVar);
    sleep(1);  // Simulate preemption, allowing Thread2 to execute
    sharedVar = localVar;  // Thread1 updates the shared variable
    printf("Shared variable updated by Thread1: %d\n", sharedVar);
}
void *decrement() {
    pthread_mutex_lock(&lock);
    int localVar;
    localVar = sharedVar;  // Thread2 reads the value of shared variable
    printf("Thread2 reads the value of shared variable as: %d\n", localVar);
    localVar--;  // Thread2 decrements the value
    printf("Local decrement by Thread2: %d\n", localVar);
    sleep(1);  // Simulate preemption, allowing Thread1 to execute
    sharedVar = localVar;  // Thread2 updates the shared variable
    printf("Shared variable updated by Thread2: %d\n", sharedVar);
}

