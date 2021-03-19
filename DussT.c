// Dussin Francesco 4Ai 1/11/2020

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#define massive 20

////////////////////////////////////////////////////////////////////////////////

typedef struct op {

  int aaaa[massive];
  struct op *left;
  struct op *right;
}op;

op BigArr;

// array sort thread
void Fun_ThreadBooble(char array[]); // x
void Fun_ThreadPrint(char array[]); // x

// end array sort thread

////////////////////////////////////////////////////////////////////////////////

int main() {

  pthread_t idthread1, idthread2;
  int retvalthread1, retvalthread2;
  int i = 0;

  for (i = 0; i < massive; i++) {

      struct op BigArr[i] = i;
  }

  printf("ARRAY: %s", yes);

  feelgood_ThreadFun(&head);
  feelgood_RecursivePrint(head);

  printf("idthread current thread id %ld\n", pthread_self());
  printf("main process pid: %d \n", getpid());

  pthread_create(&idthread1, NULL, feelgood_ThreadFun, NULL);

  printf("\n idthread = %d \n", idthread1);
  printf("\n retvalthread = %d \n", retvalthread1);

  pthread_join(idthread1, (void **)&retvalthread1);

///////////////////////////////thread array sort////////////////////////////////



  exit(0);

  return 0;
}


////////////////////////////////////////////////////////////////////////////////

void *feelgood_ThreadBooble(k arr) {


}

