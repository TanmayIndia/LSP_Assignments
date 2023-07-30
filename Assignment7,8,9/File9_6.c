#include <stdio.h>
#include<unistd.h>

extern char ** environ;
int main()
{
char ** envp=environ;

printf("The environment of a given process is:\n");

for(;envp!=NULL;envp++)
{
printf("%s: \n",*envp);
}

return 0;
}
