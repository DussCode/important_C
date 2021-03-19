/*Semafori binari composti:
esempio tre processi che, ciclicamente, incrementano a turno (in ordine P1,P2,P3) 
* la variabile condivisa V
* P1 incrementa di 1, P2 di 2 e P3 di 3.
* */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 58


/*variabili globali*/
static sem_t s1,s2,s3; /* semafori per imporre l’ordine di accesso (P1,P2,P3) allavariabile V */  //dichiaro 3 sem
int V=0;  //variabile globale che verrà incrementata
int F=0;  //contatore dei passaggi (non richiesto)


/*prototipi*/
void *thread1_process (void * );
void *thread2_process (void * );
void *thread3_process (void * );


int main ()
{
	pthread_t th1, th2,th3;
	sem_init(&s1,0,1); 
	sem_init(&s2,0,0);
	sem_init(&s3,0,0);
	if (pthread_create(&th1, NULL, thread1_process, NULL) < 0)
	{
		fprintf (stderr, "pthread_create error for thread 1\n");
		exit (1);
	}
	if (pthread_create(&th2, NULL,thread2_process,NULL) < 0)
	{
		fprintf (stderr, "pthread_create error for thread 2\n");
		exit (1);
	}
	if (pthread_create(&th3,NULL,thread3_process, NULL) < 0)
	{
		fprintf (stderr, "pthread_create error for thread 3\n");
		exit (1);
	}
	
	//attendo i processi
	pthread_join (th1, NULL);
	pthread_join (th2, NULL);
	pthread_join (th3, NULL);
	
	
	//dealloco i semafori
	if (sem_destroy(&s1)<0)
	{
	   fprintf (stderr, "sem_destroy error for s1\n");
	   exit (1);
	}	
	if (sem_destroy(&s2)<0)
	{
	   fprintf (stderr, "sem_destroy error for s2\n");
	   exit (1);
	}
	if (sem_destroy(&s3)<0)
	{
	   fprintf (stderr, "sem_destroy error for s3\n");
	   exit (1);
	}
	
	return 0;
}


/*implementazione sottoprogrammi */
void *thread1_process (void * arg)
{
	int k=1;
	while(k)
	{
		sem_wait (&s1);
		if (V<MAX)
		{
			V+=1;
			printf("T1: %d(V=%d)\n",++F, V);
		}
		else
		{
			k=0;
			printf("T1: %d(V=%d)\n",++F, V);
		}
	sem_post(&s2);
	}
	pthread_exit (0);
}

void *thread2_process (void * arg)
{
	int k=1;	
	while(k)
	{
		sem_wait (&s2);
		if ((V+1)<MAX)
		{
			V+=2;
			printf("T2: %d(V=%d)\n",++F, V);		
		}
		else
		{
			k=0;
			printf("T2: %d(V=%d)\n",++F, V);			
		}
		sem_post(&s3);
	}
	pthread_exit (0);
}

void *thread3_process (void * arg)
{
	int k=1;
	while(k)
	{
		sem_wait (&s3);
		if ((V+2)<MAX){
			V+=3;
			printf("T3: %d(V=%d)\n",++F, V);		
		}
		else
		{
			k=0;
			printf("T3: %d(V=%d)\n",++F, V);			
		}
		sem_post(&s1);
	}
	pthread_exit (0);
}
