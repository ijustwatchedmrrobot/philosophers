#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *t_sum(int a, int b)
{
  if (a % 2)
    return ((void *)(intptr_t)a + b);
  return ((void *)(intptr_t)a - b);
}

void  *myThread(void *arg)
{
  sleep(1);
  printf("Printing from thread\n");
  return t_sum(5, 3);
}

int main()
{
  pthread_t threadID;

  printf("before thread\n");
  pthread_create(&threadID, NULL, myThread, NULL);
  pthread_join(threadID, NULL);
  printf("after thread\n");
  exit(0);
}
