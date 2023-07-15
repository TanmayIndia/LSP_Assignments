#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
DIR *dp = NULL;
struct dirent * entry =NULL;
struct stat sobj;
char DirName[20];
char namecopy[30] = {'\0'};
int iMax=0;
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
entry=readdir(dp);
sprintf(name,"%s/%s",DirName,entry->d_name);
stat(name,&sobj);
	if(S_ISREG(sobj.st_mode))
	{	
		if(iMax<sobj.st_size)
		{	
		iMax=sobj.st_size;
                strcpy(namecopy,name);
		}
        }
}
printf("\t %s is the largest file %d with size.\n",namecopy,iMax);

closedir(dp);
return 0;
}
