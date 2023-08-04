#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
int i=0;
printf("Inside Thread 1...\n");
for(i=1;i<=500;i++)
{
printf("%d\n",i);
}
}

void * ThreadProc2(void * ptr)
{
int i=0;
printf("Inside Thread 2....\n");
for(i=500;i>=1;i--)
{
printf("%d\n",i);
}
}

int main()
{
int Ret=0;
pthread_t TID1=0,TID2=0;

//Creating first thread
Ret= pthread_create(&TID1,NULL,ThreadProc1,NULL);

if(Ret!=0)
{
printf("Unable to create thread.\n");
return -1;
}

printf("Thread has been created with TID: %lu\n",TID1);

//Creating second thread
Ret= pthread_create(&TID2,NULL,ThreadProc2,NULL);

if(Ret!=0)
{
printf("Unable to create thread.\n");
}

printf("Thread has been created with TID: %lu\n",TID2);

pthread_join(TID1,NULL);
pthread_join(TID2,NULL);

return 0;
}
