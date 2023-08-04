#include<pthread.h>       
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

pthread_mutex_t lock;
void * ThreadProc1(void * ptr)
{
pthread_mutex_lock(&lock);
int i=0,iCnt=0,fd=0;
ssize_t Ret;
char Buffer[1024]={'\0'};

fd=open("Demo.txt",O_RDONLY);
while((Ret=read(fd,Buffer,sizeof(Buffer))) != 0)
{
 for(i=0;i<Ret;i++)
 {
  if((Buffer[i]>= 'A') && (Buffer[i]<='Z'))
   {
   iCnt++;
   }
 }
}
printf("The number of capital letters is:%d.\n",iCnt);
close(fd);
pthread_mutex_unlock(&lock);
pthread_exit(NULL);

}

void * ThreadProc2(void * ptr)
{
pthread_mutex_lock(&lock);
int i=0,iCnt=0,fd=0;
ssize_t Ret;
char Buffer[1024]={'\0'};

fd=open("Demo.txt",O_RDONLY);
while((Ret=read(fd,Buffer,sizeof(Buffer))) != 0)
{
  for(i=0;i<Ret;i++)
  {
   if((Buffer[i]>= 'a') && (Buffer[i]<='z'))
   {
    iCnt++;
    }
   }
}
printf("The number of small letters is:%d.\n",iCnt);
close(fd);
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}


void (*arr_fptr[])(void * ptr)={ThreadProc1,ThreadProc2};
int main()
{
pthread_t aTid[2];
int Ret=0,i=0;

Ret=pthread_mutex_init(&lock,NULL);

if(Ret!=0)
{
printf("Unable to initialize mutex.\n");
return -1;
}

while(i<2)
{
pthread_create(&aTid[i],NULL,arr_fptr[i],NULL);
i++;
}

pthread_join(aTid[1],NULL);
pthread_join(aTid[2],NULL);

pthread_mutex_destroy(&lock);
pthread_exit(NULL);
return 0;
}
