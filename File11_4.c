#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;
int counter=0;

void * ThreadProc1(void * ptr)
{
pthread_mutex_lock(&lock);
int i=0;
for(i=0;i<5;i++)
{
printf("counter:%d\n",(++counter));
}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
void * ThreadProc2(void * ptr)
{
pthread_mutex_lock(&lock);
int i=0;
for(i=0;i<5;i++)
{
printf("counter:%d\n",(++counter));
}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
void * ThreadProc3(void * ptr)
{
pthread_mutex_lock(&lock);
int i=0;
for(i=0;i<5;i++)
{
printf("counter:%d\n",(++counter));
}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
void * ThreadProc4(void * ptr)
{
pthread_mutex_lock(&lock);
int i=0;
for(i=0;i<5;i++)
{
printf("counter:%d\n",(++counter));
}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}


void (*arr_fptr[4])(void * ptr)={ThreadProc1,ThreadProc2,ThreadProc3,ThreadProc4};

int main()
{
pthread_t arrTid[4];
int Ret=0,i=0;

Ret=pthread_mutex_init(&lock,NULL);
if(Ret!=0)
{
printf("Unable to initialize lock.\n");
return -1;
}

for(i=0;i<4;i++)
{
Ret= pthread_create(&arrTid[i],NULL,arr_fptr[i],NULL);
}

for(i=0;i<4;i++)
{
pthread_join(arrTid[i],NULL);
}
pthread_mutex_destroy(&lock);
pthread_exit(NULL);
return 0;
}

