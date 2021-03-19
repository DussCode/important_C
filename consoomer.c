// Duss

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct bitcoins
{

    //int *arr_CP;
    int arr_CP[10];

}bitcoins;

static sem_t s1, s2;

int V = 0;
int F = 0;

void *prodoocer_chad(void *);
void *consoomer_james(void *);

int main() 
{

    bitcoins *r = malloc(sizeof(struct bitcoins));

    int i = 0;
    pthread_t th1, th2;

    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);

    for()

        if (pthread_create(&th1, NULL, &prodoocer_chad, r) < 0)
        {

            fprintf(stderr, "pthread1_create error\n");

            exit(1);
        }

        if (pthread_create(&th2, NULL, &consoomer_james, r) < 0)
        {

            fprintf(stderr, "pthread2_create error\n");

            exit(1);
        }

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    if (sem_destroy(&s1) < 0) 
    {

        fprintf(stderr, "sem1_destroy error\n");

        exit(1);
    }

    if (sem_destroy(&s2) < 0)
    {

        fprintf(stderr, "sem2_destroy error\n");

        exit(1);
    }

    return 0;
}

void *prodoocer_chad(void *arg) 
{

    int *buffer_P = (int *)arg;

    int k = 1;

    while (k) 
    {

        
        
        sem_wait(&s1);

        sem_post(&s2);
    }

    pthread_exit(0);
}

void *consoomer_james(void *arg) 
{

    int k = 1;

    while (k) 
    {

    }

    pthread_exit(0);
}
