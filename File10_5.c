#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
int i=(int)ptr;
printf("Value received from main thread: %d.\n",(int)ptr);
pthread_exit(++i);
}
int main()
{
pthread_t TID;
int ret=0;
int no=11;
int value=0;
ret= pthread_create(&TID,NULL,ThreadProc,(int *)no);
//Address of pthread_attr_t structure object
//thread attributes  
//address of call function
//parameters of callback function

if(ret!=0)
{
printf("Unable to create thread.\n");
return -1;
}
printf("Thread is created with ID: %u\n",TID);

pthread_join(TID,&value);
printf("Return value from thread is: %d.\n",value);

printf("End of main thread.\n");

pthread_exit(NULL);
return 0;
}
