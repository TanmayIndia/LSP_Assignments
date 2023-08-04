#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
pthread_t childThread=0;
childThread=pthread_self();

printf("Inside thread....thread id is:%lu\n",childThread);
}

int main()
{
int Ret=0;
pthread_t TID=0;
int i=10,value=0;


Ret= pthread_create(&TID,NULL,ThreadProc,NULL);

if(Ret!=0)
{
printf("Unable to create thread.\n");
return -1;
}

printf("Thread has been created with TID: %lu\n",TID);

pthread_join(TID,NULL);

printf("Exiting from main thread.\n");
pthread_exit(NULL);

return 0;
}
