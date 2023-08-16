#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

void sig_handler()
{
printf("Inside signal handler function.\n");
}

int main()
{
int iCnt=0;
signal(SIGINT,sig_handler);

for(iCnt;iCnt<0xFFFFFFFF;iCnt++);
printf("Inside main function.\n");

return 0;
}

