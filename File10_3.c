#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
printf("Paramenter from main is:\t%s \n",(char * )ptr);
}

int main()
{
int Ret=0;
pthread_t TID=0;
char charArr[]= "Jay Ganesh...";

Ret= pthread_create(&TID,NULL,ThreadProc,&charArr);

if(Ret!=0)
{
printf("Unable to create thread.\n");
return -1;
}

printf("Thread has been created with TID: %lu\n",TID);

pthread_join(TID,NULL);

return 0;
}
