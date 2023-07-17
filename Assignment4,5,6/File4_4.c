////////////11111111111111111111
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    char nameCopy[30];
    struct stat sobj;
    int Size = 10;
    int fd = 0;//fd for file creation 
    int fdFile=0;//fd for individual file
    int Ret=0;
    char Buffer[1024];
   
    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("Demo.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(nameCopy,"%s",entry->d_name);
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
          fdFile= open(entry->d_name,O_RDONLY);  
           Ret = read(fdFile,Buffer,Size);
           write(fd,Buffer,Size);
        }
        
        
    }

    closedir(dp);
    
    return 0;
}
