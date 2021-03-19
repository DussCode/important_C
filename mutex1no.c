/* Realizzare due thread A e B, che stampano rispettivamente i 
 * numeri pari e i numeri  dispari (da 1 a 100) in ordine crescente.
 * Compilare gcc mutex1no.c -pthread -o mutex1no
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x;           //variabile globale
pthread_t a, b;  

void *incr_pari()
{
	while(1)
	{
		if (x > 100)
			exit(0);
		if ((x % 2) != 0)
		{
			x++; //incremento prima della stampa
			printf("Thread A: %d\n", x);
		}		
	}
}

void *incr_dispari()
{
	while(1)
	{
		if (x > 99)
			exit(0);
		if ((x % 2) == 0)
		{
			x++; //incremento prima della stampa
			printf("Thread B: %d\n", x);
		}		
	}
}

int main()
{
	x = 0;
	pthread_create(&a, NULL, (void *)incr_pari, NULL);
	pthread_create(&b, NULL, (void *)incr_dispari, NULL);
	
	
	pthread_join(b, NULL);
	pthread_join(a, NULL);
	return 0;
}
