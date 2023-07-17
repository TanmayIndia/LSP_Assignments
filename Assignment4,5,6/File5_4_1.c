#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>


#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{

    struct FileInfo fobj;
    int fd = 0;
    int Ret=0;
    int i=1;
    fd = open("AllCombine.txt",O_RDONLY);
    printf("File Name | File Size\n");
    printf("========================\n");
    while((Ret= read(fd,&fobj,sizeof(fobj)))!=0)
    {
     printf("%s | %d\n",fobj.FileName,fobj.FileSize);
    }
    printf("========================\n");
    close(fd);
    return 0;
}
