#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char DirName[30];
    char name[30];
    int Size=10;
  

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("File Name | File Size\n\n");
    while((entry = readdir(dp)) != NULL)
   {
     sprintf(name,"%s/%s",DirName,entry->d_name);
     stat(name,&sobj);
     if(S_ISREG(sobj.st_mode) && Size<sobj.st_size)
     {
        printf("%s | %ld\n",entry->d_name, sobj.st_size);
     }
   }

    closedir(dp);
    return 0;
}
