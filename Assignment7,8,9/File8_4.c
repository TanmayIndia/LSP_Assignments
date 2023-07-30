#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
int RET1=0,RET2=0,RET3=0;
int Cpid1=0,Cpid2=0,Cpid3=0;
int Exit_Status=0;

RET1=fork();//1st process gets created
if(RET1==0)
{	
execl("./ChildProcess","1",NULL);
}
else
{
printf("Parent process is running with Pid %d.\n",getpid());
RET2=fork();//2nd process gets created
	if(RET2==0)
	{	
	execl("./ChildProcess","2",NULL);
	}
	else
	{
	printf("Parent process is running with Pid %d.\n",getpid());
	RET3=fork();//3rd process gets created
	}
		if(RET3==0)
		{
		execl("./ChildProcess","3",NULL);
		}
		else
		{
		printf("Parent process is running with Pid %d.\n",getpid());
		}
}
Cpid1=wait(&Exit_Status);
printf("Child process terminated having Pid %d with exit status %d.\n",Cpid1,Exit_Status);
Cpid2=wait(&Exit_Status);
printf("Child process terminated having Pid %d with exit status %d.\n",Cpid2,Exit_Status);
Cpid3=wait(&Exit_Status);
printf("Child process terminated having Pid %d with exit status %d.\n",Cpid3,Exit_Status);
return 0;
}
