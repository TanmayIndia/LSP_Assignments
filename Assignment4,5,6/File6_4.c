#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

DIR *dp=NULL;
struct dirent *entry=NULL;
struct stat sobj;
int Size=100;
char path[30];

if(argc!=2)
{
	printf("Insufficient arguments\n");
	return -1;
}

dp=opendir(argv[1]);

if(dp==NULL)
{
	printf("Unable to directory\n");
	return -1;
}

while((entry = readdir(dp))!= NULL)
{
sprintf(path,"%s/%s",argv[1],entry->d_name);
stat(path,&sobj);
if(S_ISREG(sobj.st_mode) && Size<sobj.st_size)
{
unlink(path);
printf("Files over 100 bytes of size are deleted\n");
}
}
closedir(dp);
return 0;
}
