#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char DirName[30];
    char name[30];
    int Size= BLOCKSIZE;
    int Diff=0;
    int fd=0;
  	

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
   
    while((entry = readdir(dp)) != NULL)
   {
     sprintf(name,"%s/%s",DirName,entry->d_name);
     fd=open(name,O_WRONLY);
     stat(name,&sobj);
 
     if(S_ISREG(sobj.st_mode))
     {
     if(Size>sobj.st_size)
     {
        Diff= Size-sobj.st_size;
        lseek(fd,Diff,SEEK_CUR);
     }
     else
     {
     	truncate(name,BLOCKSIZE);
     }
    }
  }

    closedir(dp);
    return 0;
}
