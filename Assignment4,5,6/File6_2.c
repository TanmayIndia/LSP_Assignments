#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
int fd=0;
int Size=1024;
int fd1=0;
char Buffer[]= "Jay Ganesh...";

if(argc!=2)
{
	printf("Insufficient arguments\n");
	return -1;
}

fd=open(argv[1],O_WRONLY);

if(fd ==-1)
{
printf("Unable to open file.\n");
return -1;
}

fd1=lseek(fd,Size,SEEK_END);

if(fd!=-1)
{
printf("The hole hase been created at the end of the file.\n");
}

write(fd,Buffer,sizeof(Buffer));

close(fd);
close(fd1);
return 0;
}
