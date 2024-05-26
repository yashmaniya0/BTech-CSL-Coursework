#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>

sem_t f[5]; // representing every fork with a semaphore

void thinking(int n)
{
    printf("Philosopher %d starts thinking\n", n);
    sem_wait(&f[n-1]);
    printf("Philosopher %d grabs left fork\n", n);
    sem_wait(&f[(n) % 5]);
    printf("Philosopher %d grabs right fork\n", n);
    printf("Philosopher %d starts eating\n", n);
    sleep(2);
    printf("Philosopher %d ends eating\n", n);
    sem_post(&f[(n) % 5]);
    sem_post(&f[n-1]);
    printf("Philosopher %d releases left and right forks\n", n);
}

int main()
{
    int i;
    for (i = 1; i <= 5; i++){
        sem_init(&f[i], 0, 1);
    }
    for (i = 1; i <= 5; i++){
        if (fork() == 0)
        {
            
            thinking(i);
        }
    }
    for(i=1;i<=5;i++)
    {
        wait(NULL);
    }
    return 0;
}
