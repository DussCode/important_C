// Dussin Francesco 4Ai 1/11/2020

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

int my_array[99];
int research = 0;
int counter = 0;

void *Fun_Thread(void *arg) {

    int index = *(int*)arg;

    int i = 0;

    for(i = 0; i < index; i++) {

        if(my_array[index + i] == research) {

            counter++;
        }
    }
}

int main() {

    int i;

    printf("ENTER THE DESIRED NUMBER\n");
    printf("-------------------------------\n");
    printf("THREADS_RESEARCH_NUMBER: ");
    scanf("%d", &research);
    printf("-------------------------------\n");

    for (i = 1; i < 100; i++) {

        my_array[i] = rand() % 100;
        printf("%d", my_array[i]);
        printf("_");
    }

    printf("\n-------------------------------\n");

    int k = 0;

    pthread_t arr_thread[3];
    int retval_thread;

    for(i = 0; i < 3; i++) {

        int *a = malloc(sizeof(int));
        *a = i * 32;

        if(pthread_create(&arr_thread[i], NULL, &Fun_Thread, a) != 0) {

            perror("failed to create thread");
        } 
    }

    for(i = 0; i < 3; i++) {

        if(pthread_join(arr_thread[i], NULL) != 0) { // (void **)&retval_thread

            perror("failed to join thread");
        }
    }

    printf("%d", counter);
    
  return 0;
}