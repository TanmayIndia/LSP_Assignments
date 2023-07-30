#include<stdio.h>
#include<unistd.h>

int main()
{
int Ret=0;

Ret=fork();

if(Ret==0)
{
execl("./Process","NULL",NULL);
}

 return 0;
}
