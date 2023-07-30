#include <stdio.h>
#include <unistd.h>

int main()
{
int Ret=0;
int Cpid=0, Exit_Status=0;

Ret= fork();
if(Ret==0)//Child
{
execl("./Process2","NULL",NULL);//l for list
}
else//Process1
{
printf("Process1 i.e. parent of process 2 is running with Pid %d.\n",getpid());
sleep(2);
}
return 0;
}
