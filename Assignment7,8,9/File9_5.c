#include <stdio.h>
#include<unistd.h>

int main()
{
int ret;
ret = sched_yield();

printf("Current thread with PID %d has yielded processor with return value : %d\n", getpid(),ret);

return 0;
}
