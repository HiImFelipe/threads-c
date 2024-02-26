#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "bank_account/bank_account.h"

pthread_mutex_t mutex;
void *routine(void *deposit);

int main(int argc, char *argv) {
  pthread_t thread1;
  pthread_t thread2;

  int deposit1 = 850;
  int deposit2 = 500;

  pthread_mutex_init(&mutex, NULL);

  pthread_create(&thread1, NULL, routine, (void *)&deposit1);
  pthread_create(&thread2, NULL, routine, (void *)&deposit2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  pthread_mutex_destroy(&mutex);

  int result = read_balance();

  printf("result: %d", result);

  return 0;
}

void *routine(void *amount) {
  pthread_mutex_lock(&mutex);

  int balance = read_balance();

  write_balance(*(int *)amount);

  pthread_mutex_unlock(&mutex);

  return NULL;
}