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
