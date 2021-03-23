/*
 * @file DussCPCode.c
 * @Author Dussin Francesco (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-03-23
 * @copyright Copyright (c) 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct cpstruct
{
    //int *arr_CP;
    int arr_CP[10];
    int counter_prodooced;
    int counter_consoomed;
}cpstruct;

static sem_t Sem_consoomer, Sem_Prodoocer;

int V = 0;
int F = 0;

void *prodoocer_chad(void *);
void *consoomer_james(void *);

int main() 
{

    lulz *r = malloc(sizeof(struct cpstruct));

    int i = 0;
    pthread_t th1, th2;

    /*
    #include <semaphore.h>
    int sem_init(sem_t *sem, int pshared, unsigned int value);
    Link with -pthread.
    */

    sem_init(&Sem_Prodoocer, 0, 1);
    sem_init(&Sem_consoomer, 0, 0);

    //for() 
    //{
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
    //}
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
    int counting_P = (int *)arg;
    
    int k = 0;
    int i = 0;

    for(i = 0; i < 10; i++) 
    {
        if (buffer_P[9] == 1)
        {
            sem_wait(&Sem_Prodoocer);
            printf("WAITING PRODOOCER")
        }

        while(buffer_P[i] != 1) 
        {
            while (buffer_P[9] == 1)
            {
                sem_post(&Sem_Consoomer);
                printf("GOING CONSOOMER")
            }

            buffer_P[i] += 1;
            counting_P += 1;
            ((cpstruct *)arg) -> arr_CP[i] = buffer_P[i];
            ((cpstruct *)arg)-> counter_prodooced = counting_P;
        }
    }

    pthread_exit(0);
}

void *consoomer_james(void *arg) 
{
    int *buffer_C = (int *)arg;
    int counting_C = (int *)arg;

    int k = 0;
    int i = 10;

    for (i = 10; i > 0; i--)
    {
        while (buffer_P[i] != 1)
        {
            while (buffer_P[0] == 1)
            {
                sem_wait(&Sem_Prodoocer);
                printf("WAITING TEST_2")
            }

            buffer_P[i] -= 1;
            ((cpstruct *)arg) -> arr_CP[i] = buffer_P[i];

            if (buffer_P[9] == 1)
            {
                sem_post(&Sem_Consoomer);
                printf("GOING PRODOOCER")
            }
        }
    }

    pthread_exit(0);
}
