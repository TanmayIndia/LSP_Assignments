#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc,char * argv[])
{
int fileSource=0;
int fileDest=0;
int Ret=0;
char Buffer[BLOCKSIZE];

if(argc !=3)
{
	printf("Invalid number of arguments\n");
	return -1;
}


fileSource=open(argv[1],O_RDONLY);

if(fileSource==-1)
{
	printf("Unable to open source file\n");
	return -1;
}

fileDest=creat(argv[2],0777);

while((Ret=read(fileSource,Buffer,sizeof(Buffer)))!=0)
{
write(fileDest,Buffer,Ret);
}
close(fileSource);
close(fileDest);
return 0;
}
