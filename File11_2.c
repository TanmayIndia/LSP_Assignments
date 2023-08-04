#define _GNU_SOURCE
#include <pthread.h>       
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void display_pthread_attr(pthread_attr_t *attr, char * prefix)
{
int Ret,i;
size_t v;
void *stkaddr;
struct sched_param sp;


Ret = pthread_attr_getschedparam(attr, &sp);

if (Ret != 0)
{
printf("Unable to get schedparam.\n");
}
printf("%sScheduling priority = %d\n", prefix, sp.sched_priority);

Ret = pthread_attr_getguardsize(attr, &v);
if (Ret != 0)
{
printf("Unable to get guard size.\n");
}
printf("%sGuard size          = %zu bytes\n", prefix, v);

Ret = pthread_attr_getstack(attr, &stkaddr, &v);
if (Ret != 0)
{
printf("Unable to get stack size and stack address.\n");
}
printf("%sStack address       = %p\n", prefix, stkaddr);
printf("%sStack size          = %#zx bytes\n", prefix, v);
}

void * ThreadProc1(void * ptr)
{
int Ret;
pthread_attr_t gattr;

Ret = pthread_getattr_np(pthread_self(), &gattr);

if (Ret != 0)
{
printf("Unable to get attribute.\n");
}
printf("Thread attributes:\n");
display_pthread_attr(&gattr, "\t");
}

void * ThreadProc2(void * ptr)
{
int Ret;
pthread_attr_t gattr;

Ret = pthread_getattr_np(pthread_self(), &gattr);

if (Ret != 0)
{
printf("Unable to get attribute.\n");
}
printf("Thread attributes:\n");
display_pthread_attr(&gattr, "\t");
}


int main(int argc , char *argv[])
{
pthread_t TID1=0,TID2=0;
int Ret=0;
pthread_attr_t attr;
pthread_attr_t *attrp;

attrp =NULL;

Ret= pthread_create(&TID1,attrp,ThreadProc1,NULL);
printf("Thread has been created with TID: %lu\n",TID1);

if(Ret!=0)
{
printf("Unable to create thread.\n");
return -1;
}
Ret= pthread_create(&TID2,attrp,ThreadProc2,NULL);
printf("Thread has been created with TID: %lu\n",TID2);

if(Ret!=0)
{
printf("Unable to create thread.\n");
return -1;
}

pthread_join(TID1,NULL);
pthread_join(TID2,NULL);

return 0;
}
























