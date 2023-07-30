#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
int RET1=0,RET2=0,RET3=0;

RET1=fork();//1st process gets created
if(RET1==0)
{	
execl("./ChildProcess","NULL",NULL);
}
else
{
printf("Parent process is running with Pid %d.\n",getpid());
RET2=fork();//2nd process gets created
	if(RET2==0)
	{	
	execl("./ChildProcess","NULL",NULL);
	}
	else
	{
	printf("Parent process is running with Pid %d.\n",getpid());
	RET3=fork();//3rd process gets created
	}
		if(RET3==0)
		{
		execl("./ChildProcess","NULL",NULL);
		}
		else
		{
		printf("Parent process is running with Pid %d.\n",getpid());
		}
}
return 0;
}
