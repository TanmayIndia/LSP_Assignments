#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
printf("Inside Thread..\n");
}

int main()
{
int Ret=0;
pthread_t TID=0;

Ret= pthread_create(&TID,NULL,ThreadProc,NULL);

if(Ret!=0)
{
printf("Unable to create thread.\n");
return -1;
}

printf("Thread has been created with TID: %lu\n",TID);

return 0;
}
