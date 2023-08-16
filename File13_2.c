#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

#define SIZE 512

void sighup();
void sigquit();

int main()
{
int pid=0;

pid=fork();

if(pid==-1)
{
printf("Unable to create child process.\n");
return -1;
}
 
if(pid==0)
{
printf("Child process is running...\n");
signal(SIGHUP,sighup);
signal(SIGQUIT,sigquit);
for(;;);
} 
else
{
printf("Parent is running...\n");

printf("\nPARENT: sending SIGHUP\n\n");
kill(pid,SIGHUP);
sleep(3);

printf("\nPARENT: sending SIGQUIT\n\n");
kill(pid,SIGQUIT);
sleep(3);
}
}

void sighup()
{
signal(SIGHUP,sighup);
printf("RECIEVING SIGHUP form parent\n");
}

void sigquit()
{
printf("RECIEVING SIGQUIT form parent.\n");
exit(0);
}


