#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define readEnd 0
#define writeEnd 1
#define BLOCKSIZE 1024

int main()
{
int Ret=0;
int Fd[2];
pid_t Cpid=0;
char Buf[BLOCKSIZE]={'\0'};
char *msg= "Hello from India....\n";

Ret= pipe(Fd);

Cpid= fork();

if(Cpid==0)
{
printf("Child is running with Cpid %d\n",Cpid);
close(Fd[writeEnd]);
printf("Child is reading from pipe.\n");
read(Fd[readEnd],Buf,sizeof(Buf));
printf("Data from pipe is: %s",Buf);
}
else
{
printf("Parent is running with Cpid %d\n",getpid());
close(Fd[readEnd]);
printf("Parent is writing in pipe.\n");
write(Fd[writeEnd],msg,strlen(msg));
}
return 0;
}

