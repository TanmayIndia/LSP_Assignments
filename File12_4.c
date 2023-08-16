#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define PAGE 1024

int main()
{
int Fd=0,i=0;
char *map=NULL;
struct stat sb;
int FileSize=0;

Fd=open("new.txt",O_RDONLY);

if(Fd==-1)
{
printf("Unable to open file.\n");
return -1;
}

fstat(Fd,&sb);

FileSize= sb.st_size;

map= mmap(NULL,FileSize,PROT_READ,MAP_PRIVATE,Fd,0);

printf("Data from file is:\n");
printf("========================================================\n");
for(i=0;i<=FileSize;i++)
{
printf("%c",map[i]);
}
printf("=========================================================\n");
return 0;
}

