#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// -------- Macros ---------------------------------------------------------------------------------------------------
#define int                     long long int
#define ull                     unsingned long long
#define sp                      " "
#define forl(i,n)               for(int i=0;i<n;i++)
#define itr(i,a,b)              for(int i=a;(b>=a)?i<b:i>b;(b>=a)?i++:i--)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b)) / __gcd((a),(b))
#define min3(a,b,c)             min(c, min(a, b))
#define min4(a,b,c,d)           min(d, min(c, min(a, b)))
#define max3(a,b,c)             max(c, max(a, b))
#define max4(a,b,c,d)           max(d, max(c, max(a, b)))
// --------------------------------------------------------------------------------------------------------------------

struct SharedQNode
{
    char msg[500];
    struct SharedQ *link;
};

struct SharedQ
{
    struct SharedQNode *front;
    struct SharedQNode *rear;
    int size;
};

struct SharedQ *createNewQ()
{
    struct SharedQ *q = (struct SharedQ*)malloc(sizeof(struct SharedQ));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int n_reader = 0;

void *writer(void *wno)
{   
    sem_wait(&wrt);
    cnt = cnt*2;
    printf("Writer %d modified variable to %d\n",(*((int *)wno)),cnt);
    sem_post(&wrt);

}
void *reader(void *rno)
{   
    // Reader acquire the lock before modifying n_reader
    pthread_mutex_lock(&mutex);
    n_reader++;
    if(n_reader == 1) {
        sem_wait(&wrt); // If this id the first reader, then it will block the writer
    }
    pthread_mutex_unlock(&mutex);
    // Reading Section
    printf("Reader %d: read variable as %d\n",*((int *)rno),cnt);

    // Reader acquire the lock before modifying n_reader
    pthread_mutex_lock(&mutex);
    n_reader--;
    if(n_reader == 0) {
        sem_post(&wrt); // If this is the last reader, it will wake up the writer.
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{   

    pthread_t read[10],write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);

    int a[10] = {1,2,3,4,5,6,7,8,9,10}; //Just used for numbering the producer and consumer
    for(int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }
    for(int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    
    for(int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }
    

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
    
}