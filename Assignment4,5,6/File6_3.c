#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

DIR *dp=NULL;
int fd=0;
char path[30];

if(argc!=3)
{
	printf("Insufficient arguments\n");
	return -1;
}

dp=opendir(argv[1]);

if(dp==NULL)
{
	printf("Unable to open directory\n");
	return -1;
}
sprintf(path,"%s/%s",argv[1],argv[2]);

fd=creat(path,0777);

if(fd !=-1)
{
printf("The file has been created at specified location.\n");
}
else
{
printf("Unable to create a file at specified location.\n");
return -1;
}

closedir(dp);
return 0;
}
