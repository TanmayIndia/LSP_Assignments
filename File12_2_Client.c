#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>

#define BLOCKSIZE 1024

int main()
{
int key=1234;
int id=0;
char *adr=NULL;

id= shmget(key,BLOCKSIZE,0666);

if(id==-1)
{
printf("Unable to create shared memory.\n");
return -1;
}

adr=shmat(id,NULL,SHM_RDONLY);

if(adr!=NULL)
{
printf("Shared memory is attached sucessfully!\n");
}

while(*adr!='\0')
{
printf("%c",*adr);
adr++;
}
printf("\n");
shmdt(id);
return 0;
}
