#include<stdio.h>
#include<unistd.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char * argv[])
{
char DirSource[20];
char DirDest[20];
DIR *dSource=NULL;
int dDest=0;

printf("Enter source directory: \n");
scanf("%s",DirSource);

dSource= opendir(DirSource);
if(dSource==NULL)
{
printf("Unable to open directory\n");
return -1;
}
printf("Enter destination directory: \n");
scanf("%s",DirDest);

/*dDest=mkdir(DirDest, 0777);
if(dDest==-1)
{
printf("Unable to create new directory\n");
return -1;
}*/
rename(DirSource, DirDest);
closedir(dSource);
return 0;
}
