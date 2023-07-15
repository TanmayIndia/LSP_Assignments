#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
DIR *dp = NULL;
struct dirent * entry =NULL;
struct stat sobj;
char DirName[30];
char name[30];

printf("Enter directory name\n");
scanf("%s", DirName);

dp= opendir(DirName);

if(dp==NULL)
{
printf("Unable to open directory\n");
return -1;
}
while((entry= readdir(dp)) != NULL)
{
sprintf(name,"%s/%s",DirName,entry->d_name);
stat(name,&sobj);
if(S_ISREG(sobj.st_mode))
{
if(sobj.st_size==0)
{
unlink(name);
}
}
}
closedir(dp);
return 0;
}
