#include <stdio.h>
#include<unistd.h>

int main()
{
int Priority;

Priority=nice(5);

printf("The priority of current process a after increasing by 5 is: %d\n",Priority);

return 0;
}
