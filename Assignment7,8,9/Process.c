#include <stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
DIR *dir;
struct dirent *entry;
int fd=0;
char fName[30]={'\0'};

dir=opendir("/home/tanmay27/Desktop");

if(dir==NULL)
{
	printf("Unable to open folder.\n");
}

fd=creat("Name.txt",0777);

if(fd==-1)
{
	printf("Unable to create file.\n");
}

while((entry=readdir(dir))!=NULL)
{
sprintf(fName,"%s",entry->d_name);
write(fd,fName,sizeof(fName));
}

close(fd);
closedir(dir);

return 0;
}
