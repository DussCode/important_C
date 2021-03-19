// Dussin Francesco 4Ai 1/11/2020

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

////////////////////////////////////////////////////////////////////////////////

typedef struct roger{

    float *arr_s;
    int index_s;
    float research_s;
    int pos;
}roger;

void Fun_Rand(float *arr_s);
void *Fun_Thread(void *arg);

int main() {

    roger *r = malloc(sizeof(struct roger));

    printf("insert element: ");
    scanf("%f", &r -> research_s);

    Fun_Rand(r -> arr_s);
    
    int i = 0;

    for(i = 0; i < 100; i++) {

        printf("%f-", r -> arr_s[i]);
    }

    pid_t pid;
    pthread_t thid[4];

    pid = fork();

    int k = 0;

    if(pid > 0) {

        for(k = 0; k < 2; k++) {

            r -> index_s = (k + 1) * 24;
            pthread_create(&thid[k], NULL, &Fun_Thread, r);
        }

        for(k = 0; k < 2; k++) {

            pthread_join(thid[k], NULL);
        }
    } else {

        for(k = 2; k < 4; k++) {
            
            r -> index_s = (k + 1) * 24;
            pthread_create(&thid[k], NULL, &Fun_Thread, r);
        }

        for(k = 2; k < 4; k++) {

            pthread_join(thid[k], NULL);
        }
    }
    
  return 0;
}

void Fun_Rand(float *arr_s) {

    int i = 0;

    for(i = 0; i < 100; i++) {

        arr_s[i] = rand() % 100;
    }
}

void *Fun_Thread(void *arg) {

    int index_fun = ((roger *)arg) -> index_s;
    int research_fun = ((roger *)arg) -> research_s;
    float *arr_fun = ((roger *)arg) -> arr_s;
    int i = 0;

    for(i = 0; i <= index_fun; i++) { 

        if(arr_fun[i] == research_fun) {

            ((roger *)arg) -> pos = i;
            break;
        }
    }
}