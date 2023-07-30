#include "sharedfile.h"
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<time.h>
#include<string.h>

void DisplayInfo(char Fname[30])
{
int fd=0;
struct stat fobj;
struct tm *pactm=NULL;//last access time
struct tm *pmtm=NULL;//last modification time
struct tm *psctm=NULL;//last status change time
char Type[30];

fd=open(Fname,O_RDONLY);
if(fd==-1)
{
printf("Unable to open file.\n");
exit(-1);
}

fstat(fd,&fobj);
if (fstat(fd, &fobj) == -1) {
	printf("Error\n");
        exit(-1);
}
pactm = localtime(&fobj.st_atime);
pmtm=localtime(&fobj.st_mtime);
psctm=localtime(&fobj.st_ctime);

if(S_ISREG(fobj.st_mode))
{
strcpy(Type,"Regular");
}
if(S_ISDIR(fobj.st_mode))
{
strcpy(Type,"Directory");
}
if(S_ISBLK(fobj.st_mode))
{
strcpy(Type,"Block Special");
}
if(S_ISCHR(fobj.st_mode))
{
strcpy(Type,"Character Special");
}
printf("The information of given file is...\n");
printf("===========================================\n");

printf("Device Id:%d\n",fobj.st_dev);
printf("Inode number: %ld\n",fobj.st_ino);
printf("Number of links:%ld\n",fobj.st_nlink);
printf("User id:%d\n",fobj.st_uid);
printf("Size of the file in bytes:%ld\n",fobj.st_size);
printf("Fily type:%s\n",Type);
printf("Last access time:%02d-%02d-%02d || %02d:%02d:%02d\n",pactm->tm_mday,pactm->tm_mon,(pactm->tm_year+1900),pactm->tm_hour,pactm->tm_min,pactm->tm_sec);
printf("Last modification time:%02d-%02d-%02d || %02d:%02d:%02d\n",pmtm->tm_mday,pmtm->tm_mon,(pmtm->tm_year+1900),pmtm->tm_hour,pmtm->tm_min,pmtm->tm_sec);
printf("Last time status changed:%02d-%02d-%02d || %02d:%02d:%02d\n",psctm->tm_mday,psctm->tm_mon,(psctm->tm_year+1900),psctm->tm_hour,psctm->tm_min,psctm->tm_sec);

printf("===========================================\n");
close(fd);
exit(0);
}

// convert .c to .o
// gcc -c sharedfile.c -o sharedfile.o

// convert .o to .a
// ar rcs sharedfile.a sharedfile.o

