#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int op = 100;
int a[op];

void* booble_Fun(void *a);
void Fun_ArrayInitialize(int a[op]);

int main() {

 pthread_t threads[4];
 int BigArr[op];
 void* result;
 int t = 0, i = 0;

 Fun_ArrayInitialize((void *)BigArr[100]);

 for(i = 0; i < op; i++) {

    printf("ARRAY POSITION %d -- %d\n",i ,BigArr[op]);
 }

 for (t = 0; t < 20; t++) {

 if(pthread_create(&threads[t] , NULL, booble_Fun, NULL) != 0) {

   printf("error\n");
   exit(-1);
 }

 for (t = 0; t < 4; t++) {

   pthread_join(threads[t], &result);
 }

 return 0;
}
}

void* booble_Fun(void *a) {


}

void Fun_ArrayInitialize(int a[op]) {

	int i;
	//srand(time(NULL));

	for(i = 0; i < op; i++) {

    a[i] = rand() % op;
  }
}
------------------------------------------------------------------
	#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OP 100

typedef struct {
    
    int *items;
    int length;
} IntArray;

int BigArr[OP];

void* Fun_Bubble(void *BigArr);
void Fun_ArrayInitialize(int BigArr[OP]);
void Fun_Print(int BigArr[OP]);

int main() {

 pthread_t threads[4];
 void* result;
 
 int t = 0, i = 0;

 Fun_ArrayInitialize((void *)BigArr[100]);

 for(i = 0; i < OP; i++) {

    printf("ARRAY POSITION %d -- %d\n",i ,BigArr[OP]);
 }

 for (t = 0; t < 4; t++) {

    if(pthread_create(&threads[t] , NULL, Fun_Bubble, (void *) BigArr) != 0) {
    
      printf("error\n");
      exit(-1);
    }

    for (t = 0; t < 4; t++) {
    
      pthread_join(threads[t], NULL);
    }
}

 return 0;
}

void* Fun_Bubble(void *BigArr) {

 int i = 1, temp = 0;
 IntArray yes = *(IntArray *) BigArr;

 for(i = 1; i < yes.length; i++) {
        
        if(yes.items[i] < yes.items[i-1]) {
            
            temp = yes.items[i];
            yes.items[i] = yes.items[i-1];
            yes.items[i-1] = temp;
        }
    }
  }

void Fun_ArrayInitialize(int BigArr[OP]) {

	int i;
	//srand(time(NULL));

	for(i = 0; i < OP; i++) {

    BigArr[i] = rand() % OP;
  }
}

void Fun_Print(IntArray BigArr) {
    
    int i = 0;
    
    for(i = 0; i < BigArr.items-1; i++) {
        
        printf("ARRAY POSITION: %d -- %d", i, BigArr.items[i]);
    }
}
