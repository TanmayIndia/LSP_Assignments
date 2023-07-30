#include <stdio.h>
#include<sys/resource.h>

int main()
{
int Priority;

Priority=getpriority(PRIO_PROCESS,0);

printf("The priority of current process is:%d\n",Priority);

return 0;
}
