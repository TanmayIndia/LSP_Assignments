#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
int fd=0;
int Size=0;
char *Buffer=NULL;
int Ret;

if(argc !=3)
{
	printf("Invalid number of arguments\n");
	return -1;
}

fd=open(argv[1],O_RDONLY);

if(fd==-1)
{
printf("Unable to open file");
return -1;
}

Buffer = (char *)malloc(sizeof(atoi(argv[2])));

Size=atoi(argv[2]);

Ret=read(fd,Buffer,Size);
if (Ret==0)
{
	printf("Unable to read from file.\n");
	return -1;
}

else
{
	printf("The Data in the file is: %s\n", Buffer);
}
close(fd);
return 0;
}
