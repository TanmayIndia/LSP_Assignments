#include<stdio.h>
#include<unistd.h>
#include<string.h>
 
int main()
{
int Ret=0,Cpid=0;
int Fd[2];
char Buf[30]={'\0'};
char *msg= "\nHello from India....";

Ret= pipe(Fd);

Cpid= fork();

if(Cpid==0)
{
printf("Child is writing into pipe.\n");
close(Fd[0]);
write(Fd[1],msg,strlen(msg));
}
else
{
printf("Parent is reading from pipe.\n");
close(Fd[1]);
read(Fd[0],Buf,sizeof(Buf));
printf("Data from pipe is: %s\n", Buf);
}
return 0;
}

