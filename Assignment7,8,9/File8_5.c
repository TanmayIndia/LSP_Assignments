#include <stdio.h>
#include <unistd.h>

int main()
{
int did;

did=daemon(0,1);

printf("The daemon process is made with id %d and parent process id is : %d\n",did,getppid());

return 0;
}
