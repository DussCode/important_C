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
    int *counter_prodooced;
    int *counter_consoomed;
}cpstruct;

static sem_t Sem_Consoomer, Sem_Prodoocer;

int V = 0;
int F = 0;

void *prodoocer_chad(void *);
void *consoomer_james(void *);

/**
 * @brief 
 * 
 * @return int 
 */
int main() 
{

    cpstruct *r = malloc(sizeof(struct cpstruct));

    int i = 0;
    pthread_t th1, th2;

    /*
    #include <semaphore.h>
    int sem_init(sem_t *sem, int pshared, unsigned int value);
    Link with -pthread.
    */

    sem_init (&Sem_Prodoocer, 0, 1);
    sem_init (&Sem_Consoomer, 0, 0);

    //for() 
    //{
        if (pthread_create (&th1, NULL, &prodoocer_chad, r) < 0)
        {

            fprintf (stderr, "pthread1_create error\n");

            exit(1);
        }

        if (pthread_create (&th2, NULL, &consoomer_james, r) < 0)
        {

            fprintf (stderr, "pthread2_create error\n");

            exit(1);
        }
    //}
    pthread_join (th1, NULL);
    pthread_join (th2, NULL);

    if (sem_destroy (&Sem_Prodoocer) < 0)
        {
            fprintf (stderr, "sem1_destroy error\n");

            exit(1);
        }

    if (sem_destroy (&Sem_Consoomer) < 0)
    {
        fprintf (stderr, "sem2_destroy error\n");

        exit (1);
    }
    return 0;
}
/**
 * @brief 
 * 
 * @param arg 
 * @return void* 
 */
void *prodoocer_chad (void *arg) 
{
    int *buffer_P = (int *) arg;
    int *counting_P = (int *) arg;
    
    int k = 0;
    int i = 0;

    for (i = 0; i < 10; i++) 
    {
        while (buffer_P[i] != 1) 
        {
            buffer_P[i] += 1;
            counting_P += 1;
            ((cpstruct *) arg) -> arr_CP[i] = buffer_P[i];
            ((cpstruct *) arg) -> counter_prodooced = counting_P;

            if (buffer_P[9] == 1)
            {
                sem_wait (&Sem_Prodoocer);
                sem_post (&Sem_Consoomer);
                printf ("GOING CONSOOMER");
            }
        }
    }

    pthread_exit (0);
}
/**
 * @brief 
 * 
 * @param arg 
 * @return void* 
 */
void *consoomer_james (void *arg) 
{
    int *buffer_C = (int *) arg;
    int *counting_C = (int *) arg;

    int k = 0;
    int i = 10;

    for (i = 9; i >=  0; i--)
    {
        while (buffer_C[i] != 0)
        {

            buffer_C[i] -= 1;
            ((cpstruct *) arg) -> arr_CP[i] = buffer_C[i];

            if (buffer_C[0] == 0)
            {
                sem_post (&Sem_Prodoocer);
                printf ("WAITING TEST_2");
            }

            sem_wait(&Sem_Consoomer);
        }
    }

    pthread_exit (0);
}

/*
HOW TO USE SEMAPHORES

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