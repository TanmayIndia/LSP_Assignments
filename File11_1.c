#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
printf("Inside Thread 1...\n");
}
void * ThreadProc2(void * ptr)
{
printf("Inside Thread 2...\n");
}
void * ThreadProc3(void * ptr)
{
printf("Inside Thread 3...\n");
}
void * ThreadProc4(void * ptr)
{
printf("Inside Thread 4...\n");
}


void (*arr_fptr[4])(void * ptr)={ThreadProc1,ThreadProc2,ThreadProc3,ThreadProc4};

int main()
{
pthread_t TID1=0,TID2=0,TID3=0,TID4=0; 
pthread_t TIDs[4]={TID1,TID2,TID3,TID4};
int Ret=0,i=0;

for(i=0;i<4;i++)
{
Ret= pthread_create(&TIDs[i],NULL,arr_fptr[i],NULL);
printf("Thread has been created with TID: %lu\n",TIDs[i]);
}

for(i=0;i<4;i++)
{
pthread_join(TIDs[i],NULL);
}
return 0;
}

