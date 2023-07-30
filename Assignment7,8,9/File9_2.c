#include<stdio.h>
#include<unistd.h>

int main()
{
int Ret1=0,Ret2=0;

Ret1=fork();

if(Ret1==0)
{
execl("./Process1","NULL",NULL);
}

Ret2=fork();

if(Ret2==0)
{
execl("./Process2","NULL",NULL);
}

 return 0;
}
