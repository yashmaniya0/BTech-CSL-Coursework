#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>

sem_t f[5]; // representing every fork with a semaphore
void *simulate(void *k)
{
    int n = *(int *)k;
    printf("Philosopher %d starts thinking\n", n + 1);
    sem_wait(&f[n]);
    printf("Philosopher %d grabs left fork %d\n", n + 1, (n-1)%5+1);
    sem_wait(&f[(n + 1) % 5]);
    printf("Philosopher %d grabs right fork %d\n", n + 1, n%5+1);
    printf("Philosopher %d starts eating\n", n + 1);
    sleep(2);
    printf("Philosopher %d ends eating\n", n + 1);
    sem_post(&f[(n + 1) % 5]);
    sem_post(&f[n]);
    printf("Philosopher %d releases forks %d (left) and %d (right)\n", n + 1, (n-1)%5+1, n%5+1);
}

int main()
{
    pthread_t fork[5];
    int n[5];
    for (int i = 0; i < 5; i++)
    {
        sem_init(&f[i], 0, 1);
    }
    for (int i = 0; i < 5; i++)
    {
        n[i] = i;
        pthread_create(&fork[i], NULL, simulate, (void *)&n[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(fork[i], NULL);
    }
    return 0;
}
