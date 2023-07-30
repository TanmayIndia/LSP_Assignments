#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include "sharedfile.h"

#define BLOCKSIZE 1024
void Compare_files()
{
int fd1=0;
int fd2=0;
struct stat obj1,obj2;
char Buffer1[BLOCKSIZE];
char Buffer2[BLOCKSIZE];
char F1name[30];
char F2name[30];

printf("Please enter first file name.\n");
scanf("%s",F1name);
printf("Please enter second file name.\n");
scanf("%s",F2name);

fd1=open(F1name,O_RDONLY);
fd2=open(F2name,O_RDONLY);
int ret =0;
if(fd1 ==-1 || fd2 == -1)
{
printf("Unable to open file\n");
exit(-1);
}
fstat(fd1,&obj1);
fstat(fd2,&obj2);

if(obj1.st_size != obj2.st_size)
{
printf("File are different\n");
exit(-1);;
}
while((ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
{
ret = read(fd2,Buffer2,sizeof(Buffer2));
if(memcmp(Buffer1, Buffer2,ret) != 0)
{
break;
}
}
if(ret == 0)
{
printf("Both files are identical\n");
}
else
{
printf("Not identical\n");
}

close(fd1);
close(fd2);
exit(0);
}

// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o
