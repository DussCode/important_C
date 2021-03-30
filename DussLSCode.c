/**
 * @file DussLSCode.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

typedef struct cpstruct
{
    //int *arr_CP;
    int arr_R[10];
    int arr_W[10];
}cpstruct;

sem_t Sem_Writers, Sem_Readers;
pthread_mutex_t roger;

int allowed_writing = 1;
int allowed_reading = 0;

void *Reader_Cris(void *);
void *Writer_Duss(void *);

int main()
{

    cpstruct *r = malloc(sizeof(struct cpstruct));

    int i = 0;
    int chunk_readers = 0;

    //printf("number of th_readers : ");
    //scanf("%d", &chunk_readers);

    pthread_mutex_init(&roger, NULL);
    pthread_t th_writer, th_readers;
    //[chunk_readers]
    sem_init(&Sem_Writers, 0, 1);
    sem_init(&Sem_Readers, 0, 0);

    pthread_create(&th_writer, NULL, &Writer_Duss, r);

    //for (i = 0; i < chunk_readers; i++)
    //{
        pthread_create(&th_readers, NULL, &Reader_Cris, r);
    //}
    //[i]
    pthread_join(th_writer, NULL);

    //for (i = 0; i < chunk_readers; i++)
    //{
        pthread_join(th_readers, NULL);
        //}[i]

    for (i = 0; i < 10; i++)
    {
        printf(r->arr_R[i]);
    }

    pthread_mutex_destroy(&roger);

    sem_destroy(&Sem_Writers);
    sem_destroy(&Sem_Readers);

    return 0;
}

//////////////////////////////////////

void *Reader_Cris(void *arg)
{
/*
    sem_post(&Sem_Readers);
    int *arr_2 = (int *)arg;
    int i = 0;
    /*
    if (((cpstruct *)arg) -> arr_W[0] == NULL)
    {
        printf("THERE'S NOTHING INSIDE THE ARRAY")
        sem_wait(&Sem_Readers);
    }
*/
/*
    pthread_mutex_lock(&roger);

    for(i = 0; i < 10; i++)
    {
        arr_2[i] += 1;
        ((cpstruct *)arg)->arr_R[i] = arr_2[i];
    }

    pthread_mutex_unlock(&roger);
*/
    pthread_exit(0);
}

//////////////////////////////////////

void *Writer_Duss(void *arg)
{
    int *arr_1 = (int *)arg;
    int i = 0;
    int arr_length = 10;

    //pthread_mutex_lock(&roger);

    sem_wait(&Sem_Writers);

    while (allowed_writing == 1)
    {
        for (i = 0; i < arr_length; i++)
        {
            arr_1[i] += 1;
            ((cpstruct *)arg)->arr_W[i] = arr_1[i];
        }

        allowed_writing -= 1;
        allowed_reading += 1;
        sem_post(&Sem_Readers);

        for (i = 0; i < arr_length; i++)
        {
            printf(((cpstruct *)arg)->arr_W[i]);
        }
        printf("READER_TIME");
    }

    //pthread_mutex_unlock(&roger);

    pthread_exit(0);
}

/*
HOW TO USE SEMAPHORES

#include <semaphore.h>
int sem_init(sem_t *sem, int pshared, unsigned int value);
Link with - pthread.

To initialize a semaphore, use sem_init:
      int sem_init(sem_t *sem, int pshared, unsigned int value);
sem points to a semaphore object to initialize
pshared is a flag indicating whether or not the semaphore should be shared with fork()ed processes. LinuxThreads does not currently support shared semaphores
value is an initial value to set the semaphore to
Example of use:
      sem_init(&sem_name, 0, 10);
    
///////////////////////////////////////////////////////////

To wait on a semaphore, use sem_wait:
      int sem_wait(sem_t *sem);
Example of use:
      sem_wait(&sem_name); 
If the value of the semaphore is negative, the calling process blocks; one of the blocked processes wakes up when another process calls sem_post.

///////////////////////////////////////////////////////////

To increment the value of a semaphore, use sem_post:
      int sem_post(sem_t *sem);
Example of use:
      sem_post(&sem_name); 
It increments the value of the semaphore and wakes up a blocked process waiting on the semaphore, if any.

///////////////////////////////////////////////////////////

To find out the value of a semaphore, use
      int sem_getvalue(sem_t *sem, int *valp);
gets the current value of sem and places it in the location pointed to by valp
Example of use:
      int value; 
      sem_getvalue(&sem_name, &value); 
      printf("The value of the semaphors is %d\n", value);

///////////////////////////////////////////////////////////

To destroy a semaphore, use
      int sem_destroy(sem_t *sem);
destroys the semaphore; no threads should be waiting on the semaphore if its destruction is to succeed.
Example of use:
     sem_destroy(&sem_name); 
*/