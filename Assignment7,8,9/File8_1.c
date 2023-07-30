#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
int Ret=0;
int Cpid=0, Exit_Status=0;

Ret= fork();
if(Ret==0)//Child
{
execl("./ChildProcess1","NULL",NULL);//l for list
}
else//Parent
{
printf("Parent is running with PID: %d\n",getpid());
Cpid=wait(&Exit_Status);
printf("Child process terminated having Pid %d with exit status %d.\n",Cpid,Exit_Status);
}
return 0;
}
