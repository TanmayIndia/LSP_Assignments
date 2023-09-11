#include<pthread.h>       
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

//threadproc1 starts here
void * ThreadProc1(void * ptr)
{
int i=0,iCnt=0,fd=0;
ssize_t Ret;
char Buffer[1024]={'\0'};

fd=(int) ptr;
lseek(fd,0,SEEK_SET);
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
pthread_exit(NULL);
}

//threadproc2 starts here
void * ThreadProc2(void * ptr)
{
int i=0,iCnt=0,fd=0;
ssize_t Ret;
char Buffer[1024]={'\0'};

fd=(int) ptr;
lseek(fd,0,SEEK_SET);
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
pthread_exit(NULL);
}


void (*arr_fptr[])(void * ptr)={ThreadProc1,ThreadProc2};
//main method starts here
int main()
{
pthread_t aTid[2];
int i=0,fd=0;

fd=open("Demo.txt",O_RDONLY);

while(i<2)
{
pthread_create(&aTid[i],NULL,arr_fptr[i],(int *)fd);
i++;
}

pthread_join(aTid[1],NULL);
pthread_join(aTid[2],NULL);
close(fd);
pthread_exit(NULL);
return 0;
}
