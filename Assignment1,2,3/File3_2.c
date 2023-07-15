#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
DIR *dp = NULL;
struct dirent * entry =NULL;
char DirName[30];
char Fname[30];
int flag=0;

printf("Enter directory name\n");
scanf("%s", DirName);

printf("Enter file name\n");
scanf("%s", Fname);

dp= opendir(DirName);

if(dp==NULL)
{
printf("Unable to open directory\n");
return -1;
}

while((entry= readdir(dp)) != NULL)
{
	if(strcmp(Fname,entry->d_name)==0)
	{
	flag=1;
	break;
	}
}	
if(flag)
{
	printf("File Present.\n");
}
else
{
	printf("File Not present.");
}
closedir(dp);
return 0;
}
