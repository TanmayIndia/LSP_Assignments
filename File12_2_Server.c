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

id= shmget(key,BLOCKSIZE,IPC_CREAT | 0666);

if(id==-1)
{
printf("Unable to create shared memory.\n");
return -1;
}

adr=shmat(id,NULL,0);

if(adr!=NULL)
{
printf("Shared memory is attached sucessfully!\n");
}

*adr='I';
adr++;
*adr='N';
adr++;
*adr='D';
adr++;
*adr='I';
adr++;
*adr='A';
adr++;
*adr='\0';
adr++;

printf("Data is written in shared memory.\n");

return 0;
}
